#include "for_loop_test.hpp"

void Solution::Test()
{
	std::vector<int> x(2000000);
	
	for (auto i :x){ 
		i = std::rand(); 
	}

	auto start_clock = std::clock();
	for (auto i = 0; i < x.size(); ++i){
		++x[i];
		++x[i];
	}
	auto end_clock = std::clock();
	std::cout << " for(int) " << end_clock - start_clock << '\n';
	system("PAUSE");

	start_clock = std::clock();
	for (auto i:x){
		++i;
		++i;
	}
	end_clock = std::clock();
	std::cout << " for(auto i) " << end_clock - start_clock << '\n';
	system("PAUSE");

	start_clock = std::clock();
	for (auto iter = x.begin(); iter != x.end(); ++iter){
		++(*iter);
		++(*iter);
	}
	end_clock = std::clock();
	std::cout << " for(iter) " << end_clock - start_clock << '\n';
	system("PAUSE");

	start_clock = std::clock();
	std::for_each(x.begin(), x.end(), [](auto i) {
		++i;
		++i;
	});
	end_clock = std::clock();
	std::cout << " for_each " << end_clock - start_clock << '\n';
	system("PAUSE");

}
