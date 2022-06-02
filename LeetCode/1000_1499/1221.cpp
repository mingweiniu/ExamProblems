// 1221. Split a String in Balanced Strings


class Solution {
public:
    int balancedStringSplit(string s) {
        		int output = {};

		char start = {};
		int step = {};
		for (auto& letter:s)
		{
			if (0 == start)
			{
				start = letter;
				step = 1;
			}
			else if (start == letter)
			{
				step++;
			}
			else
			{
				--step;
				if (0 == step)
				{
					++output;
					start = 0;
				}
			}
		}
		return output;
    }
};