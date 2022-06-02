# 1313. Decompress Run-Length Encoded List

"""https://leetcode.com/problems/decompress-run-length-encoded-list/discuss/477055/Python-1-Line-with-Intuition"""

class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        return [x for a, b in zip(nums[::2], nums[1::2]) for x in [b] * a]