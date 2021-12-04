// 1389. Create Target Array in the Given Order

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		vector<int> output;
		output.reserve(nums.size());

		for (size_t i = 0; i < nums.size(); i++)
		{
			output.insert(output.begin() + index[i], nums[i]);
		}
		return output;
    }
};