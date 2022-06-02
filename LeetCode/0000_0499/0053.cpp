// 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // for boundary case
        nums.insert(nums.begin(), 0);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            nums[i + 1] += nums[i];
        }

        // https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
        // Maximum difference found so far
        int max_diff = nums[1] - nums[0];

        // Minimum number visited so far
        int min_element = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - min_element > max_diff)
                max_diff = nums[i] - min_element;

            if (nums[i] < min_element)
                min_element = nums[i];
        }

        return max_diff;
    }
};
