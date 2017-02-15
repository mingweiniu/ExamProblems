#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif //for VS14
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <ctime>

//#include "algorithms/104.hpp"
#include "for_loop_test.hpp"

int main(int argc, char **argv) {
	/*
	Solution sol{};
	std::clock_t start_clock, end_clock;

	start_clock = std::clock();
	for (int i = 0;i<5000;++i)
		sol.MySolution(nullptr);
	end_clock = std::clock();
	std::cout << "mytime = " << end_clock - start_clock << '\n';


	start_clock = std::clock();
	for (int i = 0;i<5000;++i)
		//sol.OtherSolution(sol.test_arg1, sol.test_arg2);
		end_clock = std::clock();
	std::cout << "other = " << end_clock - start_clock << '\n';
	*/


	Solution sol{};
	sol.Test();

	



	
	return 0;
}