# 1281. Subtract the Product and Sum of Digits of an Integer

"""https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/discuss/446372/JavaC%2B%2BPython-Straight-Forward-Solution"""

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        A = list(map(int, str(n)))
        return reduce(operator.mul, A) - sum(A)