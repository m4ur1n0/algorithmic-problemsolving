#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using std::vector;
using namespace std;

struct Price {
    int friday, before, after;
    Price(int friday, int before, int after): friday(friday), before(before), after(after) { }
};

// compare by savings
// savings = abs( min( price.before, price.after ) - friday )

// struct compareSavings {
//     bool operator()(const Price& p1, Price&p2) const {
//         // assume REAL price is the min of before and after
//         // the difference between REAL price and FRIDAY PRICE is the ACTUAL savings
//             // cannot use the absolute value because the friday price may be the most expensive
//         return p1.friday - min(p1.after, p1.before) < p2.friday - min(p2.after, p2.before);
//     }
// };

// DON'T NEED THE ABOVE AS LONG AS WE DON'T HAVE TO PRIORITY QUEUE THE WHOLE VECTOR

long long int MinCost(const vector<Price>& giftPrices, int k) {
    // friday is not guaranteed to be the best price

    long long total = 0;
    int numGifts = giftPrices.size();
    vector<int> allSavings(numGifts);
    

    if (k <= 0) {
        for (Price p : giftPrices) {
            total += min(p.after, p.before);
        }
    }


    // if k could be all just grab the min of each
    if (k >= numGifts) {
        for(Price p : giftPrices) {
            total += min({p.before, p.friday, p.after});
        }

        return total;
    }

    // now ignoring edge cases
    // we can add the worst case scenario (no friday savings)
        // and then we can find the k best savings, and subtract the differences from the total
    vector<int> savingsOnly(numGifts);
    
    for(int i = 0; i < numGifts; i++) {
        Price p = giftPrices[i];
        int minimum = min(p.before, p.after);
        allSavings[i] = minimum - p.friday;
        total += minimum;
    }

    // we know k > 0
    nth_element(allSavings.begin(), allSavings.begin() + k -1, allSavings.end(), greater<int>());

    // then we can just iterate thru thee first k best savings, subtract, and return!!!!

    for (int i = 0; i < k; i++) {
        if(allSavings[i] < 0) break; // lol found the hard way
        // cout << "SAVING : " << allSavings[i] << endl;
        total -= allSavings[i];
    }


    return total;

    
}
