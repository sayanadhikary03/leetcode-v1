class Solution {
public:

    // This function checks whether vector 'a' is better than vector 'b'
    // when both have the same total weight.
    //
    // We need the lexicographically smaller vector.
    bool isSmaller(vector<int>& a, vector<int>& b) {
        return lexicographical_compare(a.begin(), a.end(),
                                       b.begin(), b.end());
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        /*
            We store:

            [left, right, weight, original_index]

            original_index is important because the final answer
            must contain indices from the ORIGINAL input.
        */
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],   // left
                intervals[i][1],   // right
                intervals[i][2],   // weight
                i                  // original index
            });
        }

        /*
            Sort by starting position.

            Why?

            After sorting, for every interval i we can binary-search
            the first interval whose starting position is > arr[i][1].
        */
        sort(arr.begin(), arr.end(),
             [](const auto& a, const auto& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];

                 // Tie-breaking is not strictly necessary,
                 // but makes ordering deterministic.
                 return a[1] < b[1];
             });


        /*
            starts[i] = starting position of sorted interval i.

            This lets us use upper_bound() to find the next
            non-overlapping interval.
        */
        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }


        /*
            next[i] = first interval j such that

                    arr[j][0] > arr[i][1]

            Notice the use of upper_bound().

            lower_bound(r) would find >= r,
            but we need STRICTLY greater than r.
        */
        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            next[i] =
                upper_bound(starts.begin(), starts.end(), arr[i][1])
                - starts.begin();
        }


        /*
            DP definition:

            dp[i][k] = best result we can obtain using intervals
                       from index i onward, choosing at most k intervals.

            Each state stores:

                first  -> maximum total weight
                second -> lexicographically smallest list of indices
        */

        using State = pair<long long, vector<int>>;

        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );


        /*
            Base case:

            If i == n, there are no intervals left.

            Choosing nothing gives weight 0 and empty vector.
        */
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }


        /*
            Fill DP from right to left.

            At every interval we have two choices:

            1. Skip this interval.
            2. Take this interval, then jump to next[i].

            We can take at most k intervals.
        */
        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // -------------------------------------------------
                // OPTION 1: SKIP current interval
                // -------------------------------------------------

                State skip = dp[i + 1][k];


                // -------------------------------------------------
                // OPTION 2: TAKE current interval
                // -------------------------------------------------

                State take = dp[next[i]][k - 1];

                /*
                    Add the current interval's weight.
                */
                take.first += arr[i][2];

                /*
                    Add the ORIGINAL index of the current interval
                    to the selected indices.
                */
                take.second.push_back((int)arr[i][3]);

                /*
                    The vector must be sorted because the final
                    answer needs lexicographical comparison based
                    on increasing original indices.
                */
                sort(take.second.begin(), take.second.end());


                // -------------------------------------------------
                // Choose the better option
                // -------------------------------------------------

                if (take.first > skip.first) {

                    // Taking gives a larger total weight.
                    dp[i][k] = take;

                }
                else if (take.first < skip.first) {

                    // Skipping gives a larger total weight.
                    dp[i][k] = skip;

                }
                else {

                    /*
                        Same weight.

                        Therefore choose the lexicographically
                        smaller list of original indices.
                    */
                    if (isSmaller(take.second, skip.second))
                        dp[i][k] = take;
                    else
                        dp[i][k] = skip;
                }
            }
        }


        /*
            dp[0][4] = best answer using all intervals,
            with at most 4 intervals.
        */
        return dp[0][4].second;
    }
};