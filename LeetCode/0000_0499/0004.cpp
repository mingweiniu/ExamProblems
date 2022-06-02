// 1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(std::begin(candies), std::end(candies)); 
        vector<bool> output;
            for(auto i :candies )
            {
                output.push_back(i + extraCandies >= max );
            }
        return output;
    }
};