// 1720. Decode XORed Array

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
    	encoded.insert(encoded.begin(), first);
		for (size_t i = 1; i < encoded.size(); i++)
		{
			encoded[i] ^= encoded[i - 1];
		}
		
		return encoded;
        
    }
};