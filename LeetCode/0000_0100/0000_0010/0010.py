# 771. Jewels and Stones

"""https://leetcode.com/problems/jewels-and-stones/discuss/113574/1-liners-PythonJavaRuby"""

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(map(jewels.count,  stones))