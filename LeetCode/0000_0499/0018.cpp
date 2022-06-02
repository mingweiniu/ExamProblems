// 7. Reverse Integer


class Solution {
public:
    int reverse(int x) {
		long long output = 0;
        
        // special case return
        if(x == std::numeric_limits<int>::min()) return 0;

		while (x)
		{
			output = 10 * output + x % 10;
			x /= 10;
		}

		// larger then int max return
        if (output > std::numeric_limits<int>::max()) return 0;

        // overflow return 
		if (output < 0) return 0;

		return output;
    }
};