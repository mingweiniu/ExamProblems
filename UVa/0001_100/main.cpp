#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //for VS14

#include "stdio.h"
#include "stdlib.h"
#include <algorithm>
#include <iostream>

//#define DEBUG //uncomment this to see what happened

int main(int argc, char **argv) {
	long long i = 0 , j = 0;
	while (scanf("%lli%lli", &i, &j) != EOF) {
		printf("%lli %lli ", i, j);
		if (i > j) { std::swap(i, j); }
		
		int output = 0;
		for (long long k = j;k >= i;--k) {
			int count = 1;
			long long n = k;
			while (n > 1) {
				++count;
#if defined(DEBUG)
				std::cout << std::endl << n << " ";
#endif
				if (n % 2) { // k%2 == 1 
					n = n * 3 + 1;
				}else {// k%2 == 0
					n /= 2;
				}
			}
#if defined(DEBUG)
				std::cout << n << " ";
#endif		
			if (output < count) {
				output = count;
			}
		}//enf of for (long long k = j;k >= i;--k)
		printf("%lli\n", output);
#if defined(DEBUG)
		system("PAUSE");
#endif	
	}//end of while (scanf("%lli%lli", &i, &j))
	return 0;
}//end of main
