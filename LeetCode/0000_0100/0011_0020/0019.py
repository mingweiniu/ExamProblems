# 414. Third Maximum Number

"""https://leetcode.com/problems/third-maximum-number/discuss/90201/A-python-amusing-solution-which-actually-beats-98..."""

class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = set(nums)
        if len(nums) < 3:
            return max(nums)
        nums.remove(max(nums))
        nums.remove(max(nums))
        return max(nums)