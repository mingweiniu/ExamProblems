# 1720. Decode XORed Array

"""https://leetcode.com/problems/decode-xored-array/discuss/1075067/Python-1-Liner-(List-Comprehension-with-Assignment-Expresion)"""

class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        return [first] + [first:= first ^ x for x in encoded]