// 1528. Shuffle String


class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string output;
        output.resize(n);
        for(int i = 0; i< n; ++i)
        {
            output[indices[i]] = s[i];
        }
        return output;
    }
};