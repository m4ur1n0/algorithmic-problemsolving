#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


// start off : the overall energy cost if u watch set S is going to be
    // energy = (sum of all penalties) - (sum of penalties saved by watching episodes - mood adjustment)

    // therefore we can minimize energy by maximizing ( penalty_saved - mood_adj_cost ) ?

vector<int> Episodes(const vector<int>& excitement, const vector<int>& penalty) {
    // num eps
    int n = excitement.size();

    // dp array to store best total saving we get if we stop watching @ episode i
    // saving would be the amount of energy saved by watching an episode (i.e. penalty[i] + sum of other penalties)
    vector<long long> dp(n, 0); // init to 0s

    // previous[i] has the index of the previous episode in sequence that gave best calue
    // we can just say if parent[i] === -1 then it is first ep
    vector<long long> previous(n, -1); // init all to -1 because all might be first...

    long long best_saving = 0; // best saving overall tracker
    int best_idx = -1;

    for (int j = 0; j < n; j++) {
        // episode j might very well be the first watched ep

        long long best_candidate = 0;
        int best_previous = -1; // no prev for first ep

        for (int i = 0; i < j; i++) {
            // if episode i was the last watched prior 2 j, then we pay excitement cost |i - j|
            long long poss = dp[i] - llabs((long long) excitement[i] - excitement[j]);
            if (poss > best_candidate) {
                best_candidate = poss;
                best_previous = i;
            }
        }

        // so now we know what the best guy to watch BEFORE j is (if any
        // and the penalty is the cumulative penalty + the best candidate we found
        dp[j] = penalty[j] + best_candidate;
        previous[j] = best_previous;

        // then we can track the overall save
        if (dp[j] > best_saving) {
            best_saving = dp[j];
            best_idx = j;
        }
    }

    vector<int> result;
    if (best_saving <= 0) {
        return result; // should be an empty array
        // cause this would be if the best case scenario is to watch nothing at all
    }

    //otheerrrwise we gotta backtrack
    int curr = best_idx;
    while (curr != -1) {
        result.push_back(curr);
        curr = previous[curr];
    }

    // result is now in reverse order
    reverse(result.begin(), result.end()); // idk if this reverses in place or its time complexity but whatever

    for (int &episode : result) {
        episode++; // move everything forward an index for 1-indexxing  (i had to look up the for each syntax here)
    }

    return result;


}
