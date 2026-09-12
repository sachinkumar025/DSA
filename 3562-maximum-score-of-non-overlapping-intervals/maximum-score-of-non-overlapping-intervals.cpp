class Solution {
public:
    struct State {
        long long sum = 0;
        vector<int> ids;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0], // start
                intervals[i][1], // end
                intervals[i][2], // weight
                i                 // original index
            });
        }

        // Sort by start
        sort(a.begin(), a.end());

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        // next[i] = first interval whose start > a[i].end
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip
                State skip = dp[i + 1][k];

                // Option 2: take
                State take = dp[nxt[i]][k - 1];

                take.sum += a[i][2];
                take.ids.push_back(a[i][3]);

                // Keep indices sorted
                sort(take.ids.begin(), take.ids.end());

                // Compare
                if (take.sum > skip.sum) {
                    dp[i][k] = take;
                }
                else if (take.sum < skip.sum) {
                    dp[i][k] = skip;
                }
                else {
                    // Same score -> lexicographically smaller
                    if (take.ids < skip.ids)
                        dp[i][k] = take;
                    else
                        dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].ids;
    }
};