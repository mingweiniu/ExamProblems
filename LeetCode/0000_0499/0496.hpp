#include <vector>
#include <set>
#include <map>
#include <unordered_map>

class Solution {

public:
	std::vector<int> test_arg1{ 4, 1, 2 };//{3,1,0,99,90,77,56,4,2};
	std::vector<int> test_arg2{ 1, 3, 4, 2 };//{15,4,2,6,30,77,56,33,7,3,1,0,90,99,88};

	std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums) {
		std::vector<int> output;
		std::set<int> tree;
		std::unordered_map<int, int> next_big;

		for (auto i : nums)
		{
			auto it = tree.upper_bound(i);
			if ((it != tree.end()) && (it != tree.begin()))
			{
				for (auto iter = tree.begin(); iter != it; ++iter)
				{
					next_big[*iter] = i;
				}
				tree.erase(tree.begin(), it);
			}
			if (i > *tree.begin())
			{
				for (auto j : tree)
				{
					next_big[j] = i;
				}
				tree.clear();
			}
			tree.insert(i);
		}
		for (auto i : tree)
		{
			next_big[i] = -1;
		}

		for (auto i : findNums)
		{
			output.push_back(std::move(next_big[i]));
		}
		return output;
	}
	

	decltype(auto) OtherSolution(std::vector<int>& findNums, std::vector<int>& nums) {
		std::unordered_map<int, int> start;
		for (int i = 0; i<nums.size(); ++i) start[nums[i]] = i + 1;

		std::vector<int> gtr;
		for (int i = 0; i < findNums.size(); ++i) {
			int j = start[findNums[i]];

			while (j < nums.size() && findNums[i] >= nums[j]) ++j;

			if (j < nums.size()) gtr.push_back(nums[j]);
			else gtr.push_back(-1);
		}

		return gtr;
	}


};
