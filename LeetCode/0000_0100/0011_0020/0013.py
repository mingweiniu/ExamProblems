# 1365. How Many Numbers Are Smaller Than the Current Number

"""https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/discuss/524865/Clean-Python-3-sorting-and-counting"""

# 看不懂

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        indices = {}
        for idx, num in enumerate(sorted(nums)):
            indices.setdefault(num, idx)
        return [indices[num] for num in nums]“”“