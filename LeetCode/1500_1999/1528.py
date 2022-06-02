# 1528. Shuffle String

"""https://leetcode.com/problems/shuffle-string/discuss/803446/Python-3-one-liner"""

class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        return ''.join([v for (_,v) in sorted(zip(indices, s))])