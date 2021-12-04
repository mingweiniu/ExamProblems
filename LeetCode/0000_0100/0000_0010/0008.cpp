// 1512. Number of Good Pairs

// https://leetcode.com/problems/number-of-good-pairs/discuss/731561/JavaC%2B%2BPython-Count

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, 
                          [count = unordered_map<int, int> {}] (auto a, auto b) mutable {
            return a + count[b]++;
        });
    }
};