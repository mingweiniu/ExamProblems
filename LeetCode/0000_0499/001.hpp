//1. Two Sum
#include <unordered_map>
#include <vector>
class Solution {
public:
     std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //O(n) algorithm
        auto n = nums.size();
        std::unordered_map<int,decltype(n)> hash;
        for(int i=0; i <n; ++i ) hash[nums[i]] = i;
        
        std::vector<int> output;
        output.reserve(2);
        for(auto num: nums){
            if( (hash[target - num]) && (target != 2* num) ){
                output.push_back(hash[num]);
                output.push_back(hash[target - num]);
                return output;
            }
        }
        
        for(int i=0; i<n; ++i)
            if(target == 2* nums[i]) 
                output.push_back(i);
        return output;
    }
    
};
