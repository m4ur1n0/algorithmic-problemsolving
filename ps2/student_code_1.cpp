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


// TESTING CODE

// int main() {
//     vector<int> money(200000);
//     vector<int> prices(200000);
    
//     int min = 0;
//     int max = 100;

//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<int> dist(min, max);


//     for (size_t i = 0; i < 200000; i++) {
//         int x = dist(gen);
//         int y = dist(gen);

//         money[i] = x;
//         prices[i] = y;

//     }

//     // cout << money[0] << " " << money[1] << " " << money[2] << endl;
//     // cout << prices[0] <<  " " << prices[1] << " " << money[2] << endl;

//     auto start = chrono::high_resolution_clock::now();
//     vector<int> dishes = count_dishes(money, prices);
//     auto end = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


//     for(int i = 0; i < dishes.size(); i++) {
//         cout << i << endl;
//         int friend_dishes = dishes[i];
//         int friend_money = money[i];

//         size_t friendCount = 0;
//         for (int j = 0; j < prices.size(); j++) {
//             if (prices[j] <= friend_money) {
//                 friendCount++;
//             }

        
//         }

//         if (friendCount != friend_dishes) {
//             cout << "FAILED AT INDEX " << i << " -- HAVE : " << friend_dishes << " -- NEED : " << friendCount << endl;
//             cout << "TIME : " << duration.count() << endl;
//             return 0;
            
//         }

//         // friendCount = 0;
        
//     }
//     cout << "SUCCESS! VERIFIED!!" << endl;
    

//     cout << "TIME : " << duration.count() << endl;
// }
