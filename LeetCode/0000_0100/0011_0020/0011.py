# 1773. Count Items Matching a Rule

class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:            
        rule = {'type' : 0, 'color' : 1, 'name' : 2}            
        return sum([ruleValue == item[rule[ruleKey]] for item in items])


"""https://leetcode.com/problems/count-items-matching-a-rule/discuss/1085783/Python3-1-line"""
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        return sum(1 for t, c, n in items if (ruleKey, ruleValue) in (("type", t), ("color", c), ("name", n)))