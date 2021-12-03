#include <iostream>
#include <sstream>

#include <vector>
#include <string>

int main() {
	unsigned long long horizontal = 0;
	unsigned long long depth = 0;
	int aim = 0;

	for (size_t i = 0; i < 1000; i++)
	{
		auto direction_str = std::string(inputs[2 * i]);
		int data = 0;

		std::stringstream ss;
		ss << std::string(inputs[2 * i + 1]);
		ss >> data;

		if (direction_str.compare("forward") == 0) 
		{
			horizontal += data;
			depth += aim * data;
		}
		else if (direction_str.compare("down") == 0)
		{
			aim += data;
		}
		else if (direction_str.compare("up") == 0)
		{
			aim -= data;
		}

	}


	std::cout << depth  * horizontal ;
	return 0;
}
