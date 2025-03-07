#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> Stocks(const vector<int>& buy, const vector<int>& sell, int k) {

    int n = buy.size(); // number of stocks
    if (n == 0) return {}; // if no stocks, do nothing :)
    
    int s_max = min(k, n); // the maximum number of stocks we can have at once -- if k > n, we never need to worry abt jolding too amny
    
    vector<vector<long long>> history_dp; // dp array to hold history

    vector<long long> dp_arr_previous(s_max + 1, LLONG_MIN); // hold max profit of each stock held -- start at (essentailly) -inf
    dp_arr_previous[0] = 0; // initialize first result
    history_dp.push_back(dp_arr_previous);
    
    for (int day = 0; day < n; day++) { // for each day as we go --- O(n);

        // init a dp array to be filling out as we go, we'll let go of it at the end.
        vector<long long> curr_dp(s_max + 1, LLONG_MIN);

        for (int s = 0; s <= s_max; ++s) { // for as many stocks as we can hold -- O(min(k, n)) -- O(n) within O(n) loop == O(n^2)

            if (dp_arr_previous[s] == LLONG_MIN) continue; // do nothing at all, 
            
            
            if (curr_dp[s] < dp_arr_previous[s]) { // 

                curr_dp[s] = dp_arr_previous[s];
            }
            
            if (s < s_max) { // if we are under our maximum, we can buy

                long long new_profit = dp_arr_previous[s] - buy[day]; // save the profit we'd make

                if (new_profit > curr_dp[s + 1]) { // if we increase our profit we want this one

                    curr_dp[s + 1] = new_profit;
                }

            }
            

            if (s > 0) {
                // when not looking at first, look at prevs
                long long new_profit = dp_arr_previous[s] + sell[day];
                if (new_profit > curr_dp[s - 1]) { // if we get better ret, reset prev case
                    curr_dp[s - 1] = new_profit;
                }
            }


        }

        dp_arr_previous = curr_dp;
        history_dp.push_back(dp_arr_previous);
    }
    

    // backtracking now to find sol
    vector<int> actions(n, 0);
    int current_s = 0;

    for (int i = n - 1; i >= 0; --i) {
    
        long long current_profit = history_dp[i + 1][current_s];
        bool foundFlag = false;
        

        if (history_dp[i][current_s] == current_profit) { // if same do nothing

            actions[i] = 0;
            foundFlag = true;
        
        } else {

            if (current_s > 0) {
                // if prev profit fo r buy was the same as our current profit then we bought
                long long prev_profit_buy = history_dp[i][current_s - 1] - buy[i];

                if (prev_profit_buy == current_profit) {
                    actions[i] = 1;
                    current_s--;

                    foundFlag = true;
                }
            }

            if (!foundFlag && current_s < s_max) {
                // if we still haven't found adn we're not at max
                long long prev_profit_sell = history_dp[i][current_s + 1] + sell[i];

                if (prev_profit_sell == current_profit) {
                    // we sell
                    actions[i] = -1;
                    current_s++;
                    foundFlag = true;
                }
            }
        }
    }
    
    return actions;
}
