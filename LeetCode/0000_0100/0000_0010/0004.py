## 1431. Kids With the Greatest Number of Candies

"""https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/discuss/792205/Python-Most-Optimum-Solution"""

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        	high_enough = max(candies) - extraCandies
	        return [i >= high_enough for i in candies]