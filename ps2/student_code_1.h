#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>

using std::vector;
using namespace std;


vector<int> count_dishes(const vector<int>& money, const vector<int>& prices) {
    // prices = m
    // money/friends = n

    // sort prices   --- O(m * log(m))
    vector<int> prices_copy = prices;
    sort(prices_copy.begin(), prices_copy.end());
    // define num_plates vector  --- O(1)
    vector<int> num_dishes(money.size());

    vector<int>::iterator p_strt = prices_copy.begin();
    vector<int>::iterator p_end = prices_copy.end();

    // for each friend/money  --- O(n)
        //  binary search for money value (return index where price >= friend)  --- O(log(m))   --- O(n * log(m))
        //  num_plates.push_back() returned index  --- O(1) (amortized) --- O(n)
    size_t index = 0;
    for(int friend_money : money) {
        
        // friend_money is the amount of money this friend has, let's find the first time it is exceeded
        auto it = upper_bound(p_strt, p_end, friend_money);
        num_dishes[index] = distance(p_strt, it);

        index++;

    }

    
    return(num_dishes);


}

