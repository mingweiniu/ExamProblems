// 1281. Subtract the Product and Sum of Digits of an Integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int multi = 1;
        while( n )
        {
            int pos = n % 10;
            sum += pos;
            multi *= pos;
            n /= 10;
        }
        return multi- sum;

    }
};