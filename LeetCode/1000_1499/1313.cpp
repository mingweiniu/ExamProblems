//1313. Decompress Run-Length Encoded List

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        std::vector<int> output;
        int num = 0;
        for(size_t i = 0; i < nums.size();  i += 2)
        {
            num +=  nums[i];
        }
        output.reserve(num);
        
		for (size_t i = 0; i < nums.size();  i += 2)
		{
			output.insert(output.end(), nums[i], nums[i + 1]);
		}
		return output;
    }
};