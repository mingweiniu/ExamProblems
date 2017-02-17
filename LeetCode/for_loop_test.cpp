#include "for_loop_test.hpp"

#include <functional>

void func(int i, int b) { ++i; b += i; }

void Solution::Test()
{
	int b = 0;
	std::vector<int> x(2000000);

	for (auto i : x) {
		i = std::rand();
	}

	auto start_clock = std::clock();
	for (auto i = 0; i < x.size(); ++i) {
		++x[i];
		b += x[i];
	}
	auto end_clock = std::clock();
	std::cout << " for(int) " << end_clock - start_clock << '\n';


	start_clock = std::clock();
	for (auto i : x) {
		++i;
		b += i;
	}
	end_clock = std::clock();
	std::cout << " for(auto i) " << end_clock - start_clock << '\n';


	start_clock = std::clock();
	for (auto iter = x.begin(); iter != x.end(); ++iter) {
		++(*iter);
		b += (*iter);
	}
	end_clock = std::clock();
	std::cout << " for(iter) " << end_clock - start_clock << '\n';


	start_clock = std::clock();
	std::for_each(x.begin(), x.end(), std::bind(&func, std::placeholders::_1, b));
	end_clock = std::clock();
	std::cout << " for_each(bind) " << end_clock - start_clock << '\n';



	start_clock = std::clock();
	std::for_each(x.begin(), x.end(), [&b](auto i) {
		++i;
		b += i;
	});
	end_clock = std::clock();
	std::cout << " for_each(lambda) " << end_clock - start_clock << '\n';

	system("PAUSE");

}
