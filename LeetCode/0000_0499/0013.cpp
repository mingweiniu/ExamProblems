// 1365. How Many Numbers Are Smaller Than the Current Number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		map<int, int> counter;
		for (auto n : nums) ++counter[n];
		
        int sum_tmp = {};
        map<int, int> sum_counter;
		for (auto& c : counter)
		{
            sum_counter[c.first] = sum_tmp;
			sum_tmp += c.second;			
		}

		for (size_t i = 0; i < nums.size(); i++)
		{
			nums[i] = sum_counter[nums[i]];
		}

		return nums;
        
    }
};