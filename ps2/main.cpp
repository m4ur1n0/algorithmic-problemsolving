#include "student_code_1.h"
#include "student_code_2.h"
#include <algorithm>
#include <iostream>


int main() {

    // sturdy solution for p 1

    // vector<int> money(200);
    // vector<int> prices(200);
    
    // int min = 0;
    // int max = 100;

    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<int> dist(min, max);


    // for (size_t i = 0; i < 200; i++) {
    //     int x = dist(gen);
    //     int y = dist(gen);

    //     money[i] = x;
    //     prices[i] = y;

    // }

    // // cout << money[0] << " " << money[1] << " " << money[2] << endl;
    // // cout << prices[0] <<  " " << prices[1] << " " << money[2] << endl;

    // auto start = chrono::high_resolution_clock::now();
    // vector<int> dishes = count_dishes(money, prices);
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


    // for(int i = 0; i < dishes.size(); i++) {
    //     // cout << i << endl;
    //     int friend_dishes = dishes[i];
    //     int friend_money = money[i];

    //     size_t friendCount = 0;
    //     for (int j = 0; j < prices.size(); j++) {
    //         if (prices[j] <= friend_money) {
    //             friendCount++;
    //         }

        
    //     }

    //     if (friendCount != friend_dishes) {
    //         cout << "FAILED AT INDEX " << i << " -- HAVE : " << friend_dishes << " -- NEED : " << friendCount << endl;
    //         cout << "TIME : " << duration.count() << endl;
    //         return 0;
            
    //     }

    //     // friendCount = 0;
        
    // }
    // cout << "PROBLEM 1 SSUCCESS! VERIFIED!!" << endl;
    

    // cout << "TIME : " << duration.count() << endl;


    // TESTING P2

    // @ 10 --- 5 + 8 + 10 + 7 + 6 + 12 + 8 + 9 + 3 + 11 = 79
    // @ 0  --- 10 + 8 + 14 + 9 + 6 + 14 + 10 + 11 + 5 + 13 = 100
    vector<Price> giftPrices = {
        {5, 10, 12},   // Gift 0: savings = 10 - 5 = 5
        {15, 8, 9},    // Gift 1: savings = 8 - 15 = -7 (negative, skip)
        {10, 15, 14},  // Gift 2: savings = 14 - 10 = 4
        {7, 9, 11},    // Gift 3: savings = 9 - 7 = 2
        {20, 6, 8},    // Gift 4: savings = 6 - 20 = -14 (negative, skip)
        {12, 14, 16},  // Gift 5: savings = 14 - 12 = 2
        {8, 10, 12},   // Gift 6: savings = 10 - 8 = 2
        {9, 11, 13},   // Gift 7: savings = 11 - 9 = 2
        {3, 5, 7},     // Gift 8: savings = 5 - 3 = 2
        {11, 13, 15}   // Gift 9: savings = 13 - 11 = 2
    };
    int k = 0; 

    long long total = MinCost(giftPrices, k);

    cout << total << endl;



    // longest possible example

    // Generate Maximum Length Input (200,000 gifts)
    // const int n = 200000;
    // vector<Price> maxGiftPrices;
    // maxGiftPrices.reserve(n);
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<> priceDist(1, 1000000000); // Prices between 1 and 1e9

    // for (int i = 0; i < n; i++) {
    //     maxGiftPrices.push_back(Price(priceDist(gen), priceDist(gen), priceDist(gen)));

    // }
    // int maxK = 100000; // Arbitrary k for testing


    // // Test Maximum Length Input
    // cout << "Testing Maximum Length Input..." << endl;

    // auto start = chrono::high_resolution_clock::now();
    // long long result = MinCost(maxGiftPrices, maxK);
    // auto end = chrono::high_resolution_clock::now();

    // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


    // cout << "Result for Maximum Length Input: " << result << endl;
    // cout << "TIME : " << duration.count() << endl;




}
