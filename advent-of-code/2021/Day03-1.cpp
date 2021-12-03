#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <string>

std::vector<int> inputs{
  0b111011110101, 0b011000111010,0b001101100001,
};

int main() {

	std::array<int, 12> bits = {};

	for (auto i : inputs)
	{
		for (size_t b = 0; b < 12; b++)
		{
			auto mask = 1 << b;
			if (i & mask)
			{
				++bits[b];
			}
		}
	}

	auto gamma = 0;
	auto epsilon = 0;

	for (size_t b = 0; b < 12; b++)
	{
		if (bits[b] > inputs.size() / 2)
		{
			gamma += 1 << b;
		}
		else
		{
			epsilon += 1 << b;
		}
	}
	
	std::cout << gamma * epsilon;


	return 0;
}
