//1. Two Sum
#include <unordered_map>
#include <vector>
class Solution {
public:
     std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //O(n) algorithm
        auto n = nums.size();
        std::unordered_map<int,decltype(n)> input;
        for(int i=0; i <n; ++i ) input[nums[i]] = i;
        
        std::vector<int> output;
        for(auto num: nums){
            if( (input[target - num]) && (target != 2* num) ){
                output.push_back(input[num]);
                output.push_back(input[target - num]);
                return output;
            }
        }
        
        for(int i=0; i<n; ++i)
            if(target == 2* nums[i]) 
                output.push_back(i);
        return output;
    }
    
};
