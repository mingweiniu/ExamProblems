#include <vector>

class Solution {

public:
	std::vector<std::vector<int>> test_case{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,1,0,0 },{ 1,1,0,0 } };
	int MySolution(std::vector<std::vector<int>>& grid) {
		auto width = grid[0].size();
		auto height = grid.size();
		auto edge = 0;

		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				if (grid[i][j]) {
					if (i > 0) edge += !grid[i - 1][j];
					else  ++edge;

					if (i < height - 1) edge += !grid[i + 1][j];
					else ++edge;

					if (j > 0) edge += !grid[i][j - 1];
					else ++edge;

					if (j < width - 1)edge += !grid[i][j + 1];
					else ++edge;

				}
			}
		}
		return edge;
	}


	int OtherSolution(std::vector<std::vector<int>>& grid) {
		int count = 0, repeat = 0;
		for (int i = 0;i<grid.size();i++)
		{
			for (int j = 0; j<grid[i].size();j++)
			{
				if (grid[i][j] == 1)
				{
					count++;
					if (i != 0 && grid[i - 1][j] == 1) repeat++;
					if (j != 0 && grid[i][j - 1] == 1) repeat++;
				}
			}
		}
		return 4 * count - repeat * 2;
	}


};
