# 1108. Defanging an IP Address

"""https://leetcode.com/problems/defanging-an-ip-address/discuss/340369/Python-One-Line"""

class Solution:
    def defangIPaddr(self, address: str) -> str:
      return '[.]'.join(address.split('.'))
