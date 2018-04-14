#include <iostream>

int main(){
	int n;
	while (std::cin >> n){
		int sum = n;
		while (n >= 3){
			sum += n / 3;
			n = n / 3 + n % 3;
		}
		if (n == 2){
			++sum;
		}
		std::cout << sum << '\n';
	}
	return 0;
}
