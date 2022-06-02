// 771. Jewels and Stones

class Solution {
private:
    static constexpr auto ansi_A = 65;
    static constexpr auto ansi_z = 122;
    size_t counter[ansi_z - ansi_A + 1];
public:
    int numJewelsInStones(string jewels, string stones) {
        for(auto &i : stones)
        {
            ++counter[i - 'A'];
        }
        size_t output = {};
                
        for(auto &i : jewels)
        {
            output += counter[i - 'A'];
        }
        return output;
    }
};