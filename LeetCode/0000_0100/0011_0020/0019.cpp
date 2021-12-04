// 414. Third Maximum Number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
		std::set<int> res;
		for (auto n : nums)
		{
			res.insert(n);
		}
		auto back_iter = res.end();
		back_iter--;

		if (res.size() > 2)
		{
			back_iter--;
			back_iter--;		
		}
			
		return *back_iter;
		
    }
};