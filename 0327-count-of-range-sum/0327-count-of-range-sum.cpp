class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return mergeSort(prefix, 0, n, lower, upper);
    }

private:
    int mergeSort(vector<long long>& prefix, int left, int right,
                  int lower, int upper) {

        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int count = 0;

        count += mergeSort(prefix, left, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, right, lower, upper);

        int j = mid + 1;
        int k = mid + 1;

        // Count valid ranges
        for (int i = left; i <= mid; i++) {

            while (j <= right &&
                   prefix[j] - prefix[i] < lower) {
                j++;
            }

            while (k <= right &&
                   prefix[k] - prefix[i] <= upper) {
                k++;
            }

            count += (k - j);
        }

        // Merge step
        vector<long long> temp;

        int p1 = left;
        int p2 = mid + 1;

        while (p1 <= mid && p2 <= right) {

            if (prefix[p1] <= prefix[p2]) {
                temp.push_back(prefix[p1++]);
            } else {
                temp.push_back(prefix[p2++]);
            }
        }

        while (p1 <= mid)
            temp.push_back(prefix[p1++]);

        while (p2 <= right)
            temp.push_back(prefix[p2++]);

        for (int i = left; i <= right; i++) {
            prefix[i] = temp[i - left];
        }

        return count;
    }
};