// 1480. Running Sum of 1d Array

// https://leetcode.com/problems/running-sum-of-1d-array/discuss/686276/C%2B%2BPython-Partial-Sum

vector<int> runningSum(vector<int>& nums) {
    partial_sum(nums.begin(), nums.end(), nums.begin());
    return nums;
}
