
#include <tuple>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;



void continued_fraction(const int &);


int main() {
	int x;
	std::cin >> x;
	continued_fraction(x);
}

void continued_fraction(const int & input) {

	// s = integer A + Fraction  B / (C + sign(D) * abs(D)^(1/2))
	// Continued Fraction of a number square;

	using Num = std::array<int, 4>;

	auto get_next_num = [](const std::array<int, 4> & input) {
		
		auto A = static_cast<float>(input[0]);
		auto B = static_cast<float>(input[1]);
		auto C = static_cast<float>(input[2]);
		auto D = static_cast<float>(input[3]);

		//       C + D^0.5
		// x1 =  --------- = A + x2^-1
		//           B

		
		
		auto new_C = -C + B*A ;
		auto new_B = (D - new_C * new_C )/ B;
		
		auto new_A = (new_C + pow(D, 0.5)) / new_B;

		std::array<int, 4> output{ new_A ,new_B,new_C, D };

		return output;
	};

	//auto s = static_cast<float>(x);
	//auto y = static_cast<int>(pow(s, 0.5));

	//Num x = make_tuple(static_cast<int>(pow(x, 0.5)), , );

	//int lower = x - y*y;
	//Num x0 = { 3, 1, 0, 14 };
	Num x1 = { 1, 5, 3, 14 };
	Num x2 = { 2, 2, 2, 14 };
	Num x3 = { 1, 5, 2, 14 };
	Num x4 = { 6, 1, 3, 14 };

	auto y1 = get_next_num(x1);
	auto y2 = get_next_num(x2);
	auto y3 = get_next_num(x3);
	auto y4 = get_next_num(x4);
	auto y5 = get_next_num(y4);
	while (true) {
		y5 = get_next_num(y5);
	}
	

}
