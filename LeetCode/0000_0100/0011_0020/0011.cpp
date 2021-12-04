// 1773. Count Items Matching a Rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int rule = {};
		if (ruleKey[0] == 'c') rule = 1;
		if (ruleKey[0] == 'n') rule = 2;

		return count_if(begin(items), end(items),[&ruleValue, &rule](vector<string>& item) {
			return !ruleValue.compare(item[rule]);
			});
    }
};