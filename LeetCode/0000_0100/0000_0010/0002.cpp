// 1108. Defanging an IP Address

// https://leetcode.com/problems/defanging-an-ip-address/discuss/328855/C%2B%2B-1-liner-(regex_replace)

class Solution {
public:
    string defangIPaddr(string address) {
        return regex_replace(address, regex("[.]"), "[.]");
    }
};
