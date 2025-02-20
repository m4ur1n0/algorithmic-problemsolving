// #include <vector>
// #include <iostream>
// #include <cmath>

// using std::vector;
// using namespace std;

// vector<int> Purchases(const vector<int>& cost, const vector<int>& bundle) {
//     // define dp array to store best-case-scenarios for each i
//     int num_gifts = cost.size();

//     if (num_gifts == 1) {
//         vector<int> r(1, 0);
//         return r;
//     }

//     vector<int> dp(num_gifts + 1, 0); // O(n + 1) => O(n)
//     vector<int> result(num_gifts, 0); // init all to buy at cost? doesn't matter

//     for (int i = 0; i < num_gifts; i++) { // fill out dp for each gift O(n)
//         // gift[i] has its best case scenario at dp[i + 1]
//         // because dp[0] is the cost of buying 0 gifts
//         int curr_gift_cost = cost[i];

//         if (i == 0) { // base case
//             // first gift, all we know is we can buy it alone
//             dp[1] = curr_gift_cost;
//             continue;
//         } 
//         // if (i == 1) {

//         // }

//         int bundle_with_prev = bundle[i - 1]; // only runs when i >= 1 -- cost of bundling w prev
//         int optimal_cost_of_prev = dp[i];
//         int optimal_cost_before_prev = dp[i-1];

//         // two choices
//             // 1) bundle with prev => new_cost = optimal_cost_before_prev + bundle_with_prev
//                 // [1, -1, curr] must become
//             // 2) buy alone =>        new_cost = optimal_cost_of_prev + curr_gift_cost
//             // it seems we actually cannot build results as we go

//         dp[i+1] = min((optimal_cost_before_prev + bundle_with_prev), (optimal_cost_of_prev + curr_gift_cost)); // these can never be equal or we wouldn't have unique result?

//     }

//     // traverse backwards through dp, set results values based on whether optimal
//     // was found by bundling or not
//     int i = num_gifts - 1;
//     while (i >= 0) {

//         if (i == 0) {
//             // if we got this far it should be a given that we bought 0 at cost
//             result[0] = 0;
//             break;
//         }

//         // determine if opt_for_i occurs because i was bundled with i - 1 or not
//         // since result is necessarily unique, we can safely assume that we will never have
//         // a situation where this is unclear (because that would mean result can have 2 valid values)

//         int opt_for_i = dp[i+1];
//         int opt_for_prev = dp[i];
//         int opt_for_two_prev = dp[i - 1]; 

//         if (opt_for_i == opt_for_two_prev + bundle[i - 1]) { // then we bought i as bundle
//             result[i-1] = 1;
//             result[i] = -1;

//             i -= 2;
//         } else if (opt_for_i == cost[i] + opt_for_prev) { // if curr_opt was found by adding cost of i to opt of prev, then we bought i alone
//             result[i] = 0; // bought alone
//             i--;
//         }  

//     }

//     return result;


// }


// #include <vector>
// #include <iostream>
// #include <cmath>

// using std::vector;
// using namespace std;

// vector<int> Purchases(const vector<int>& cost, const vector<int>& bundle) {
//     // define dp array to store best-case-scenarios for each i
//     int num_gifts = cost.size();

//     if (num_gifts == 0) {
//         return {};
//     }
//     if (num_gifts == 1) {
//         return {0};
//     }

//     vector<int> dp(num_gifts + 1, 0); // O(n + 1) => O(n)
//     vector<int> result(num_gifts, 0); // init all to buy at cost? doesn't matter
//     vector<int> decision(num_gifts + 1, 0);

//     for (int i = 0; i < num_gifts; i++) { // fill out dp for each gift O(n)
//         // gift[i] has its best case scenario at dp[i + 1]
//         // because dp[0] is the cost of buying 0 gifts
//         int curr_gift_cost = cost[i];

//         if (i == 0) { // base case
//             // first gift, all we know is we can buy it alone
//             dp[1] = curr_gift_cost;
//             decision[1] = 0;
//             continue;

//         } else {

//             int bundle_with_prev = bundle[i - 1]; // only runs when i >= 1 -- cost of bundling w prev
//             int optimal_cost_of_prev = dp[i];
//             int optimal_cost_before_prev = dp[i-1];

//             // two choices
//                 // 1) bundle with prev => new_cost = optimal_cost_before_prev + bundle_with_prev
//                     // [1, -1, curr] must become
//                 // 2) buy alone =>        new_cost = optimal_cost_of_prev + curr_gift_cost
//                 // it seems we actually cannot build results as we go

//             int cost_indiv = optimal_cost_of_prev + curr_gift_cost;
//             int cost_bundle = optimal_cost_before_prev + bundle_with_prev;

//             // if (cost_indiv < cost_bundle) {
//             //     dp[i + 1] = cost_indiv;
//             //     decision[i + 1] = 0; // 0 = individuals
//             // } else {
//             //     dp[i + 1] = cost_bundle;
//             //     decision[i + 1] = 1; // 1 = bundle with prev
//             // }
//             if (cost_bundle < cost_indiv) {
//                 dp[i + 1] = cost_bundle;
//                 decision[i + 1] = 1; // 1 = bundle with prev
//             } else {
//                 dp[i + 1] = cost_indiv;
//                 decision[i + 1] = 0; // 0 = individuals
//             }

//         }     
//     }

//     // traverse backwards through dp, set results values based on whether optimal
//     // was found by bundling or not
//     int i = num_gifts - 1;
//     while (i >= 0) {

//         if (decision[i + 1] == 0 ) {
//             // then we bought gift i individually
//             result[i] = 0;
//             i--;
//         } else {
//             // gift i must have been bought as bundle (decision only contains 0 and 1)
//             result[i] = -1;
//             result[i - 1] = 1;
//             i -= 2;
//         }

//     }

//     return result;

// }

// fuck try checking forward bundling too?

#include <vector>
#include <climits>


using namespace std;

vector<int> Purchases(const vector<int>& cost, const vector<int>& bundle) {
    int num_gifts = cost.size();

    if (num_gifts == 0) {
        return {};
    }

    if (num_gifts == 1) {
        return {0};
    }

    vector<long long> dp(num_gifts + 1, LLONG_MAX);

    dp[0] = 0; // accounts for base case here?

    // need to determine if we are bundling forward [i, i + 1]
    for (int i = 0; i < num_gifts; ++i) { // O(n)

        if (dp[i] == LLONG_MAX) { // if currently saved as ainf
            continue;
        }

        if (dp[i + 1] > dp[i] + cost[i]) { // look @ buying indiv

            dp[i + 1] = dp[i] + cost[i];

        }

        if (i < num_gifts - 1) { // look @ buying as bundle with subsequent
            long long bundle_with_next_cost = dp[i] + bundle[i];

            if (dp[i + 2] > bundle_with_next_cost) {

                dp[i + 2] = bundle_with_next_cost;

            }
        }
    }

    // backtracking step
    vector<int> result(num_gifts, 0);

    int i = num_gifts;
    while (i > 0) { // O(n) max

        if (i >= 1 && dp[i] == dp[i - 1] + cost[i - 1]) {
            // if the optimal cost found for gifts up to i
            // is equal to preceding gift optimal + the cost of this gift
            // then we bought it on its own
            result[i - 1] = 0;
            i--;

        } else if (i >= 2 && dp[i] == dp[i - 2] + bundle[i - 2]) {
            // if this is isn't the first gift and the optimal cost found
            // was calculated by adding the optimal cost from 2 gifts ago to the bundle cost fo rthis and prev
            // then this gift was bought as a bundle

            result[i - 2] = 1;
            result[i - 1] = -1;
            i -= 2;
            
        }
    }

    return result;
}