class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Minimum is in left part including mid
            if (nums[mid] < nums[right]) {
                right = mid;
            }

            // Minimum is in right part
            else if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // Duplicates: cannot decide
            else {
                right--;
            }
        }

        return nums[left];
    }
};