class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = INT_MIN;

        // Fix left column
        for (int left = 0; left < cols; left++) {

            vector<int> rowSum(rows, 0);

            // Extend right column
            for (int right = left; right < cols; right++) {

                // Build row sums
                for (int r = 0; r < rows; r++) {
                    rowSum[r] += matrix[r][right];
                }

                // Find max subarray <= k
                set<int> prefixSet;
                prefixSet.insert(0);

                int prefix = 0;

                for (int sum : rowSum) {

                    prefix += sum;

                    auto it = prefixSet.lower_bound(prefix - k);

                    if (it != prefixSet.end()) {
                        ans = max(ans, prefix - *it);
                    }

                    prefixSet.insert(prefix);
                }
            }
        }

        return ans;
    }
};