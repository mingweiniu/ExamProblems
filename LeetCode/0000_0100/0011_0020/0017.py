# 1678. Goal Parser Interpretation

"""https://leetcode.com/problems/goal-parser-interpretation/discuss/961441/Python-one-liner"""

class Solution:
    def interpret(self, command: str) -> str:
        return command.replace('()','o').replace('(al)','al')