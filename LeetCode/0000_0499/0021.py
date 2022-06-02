# 1389. Create Target Array in the Given Order

"""https://leetcode.com/problems/create-target-array-in-the-given-order/discuss/560890/Python-3-in-one-line"""

class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:    
        return functools.reduce(lambda r, p: r.insert(p[0], p[1]) or r, zip(index, nums), [])