// 1672. Richest Customer Wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int output = 0;
        for(auto &i : accounts)
        {
            output = max(output, accumulate(i.begin(), i.end(), 0));
        }
            return output;
    }
};