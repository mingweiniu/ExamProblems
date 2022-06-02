# 1470. Shuffle the Array

"""https://leetcode.com/problems/shuffle-the-array/discuss/674400/JavaPython-3-Straight-forward-code."""

class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [num for tup in zip(nums[: n], nums[n :]) for num in tup]