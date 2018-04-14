#include <iostream>
#include <vector>
using namespace std;

int Pt = 1, P[5500];
void sieve() {
	char mark[50000] = {};
	int i, j;
	for (i = 2; i < 50000; i++) {
		if (!mark[i]) {
			P[Pt++] = i;
			for (j = 2 * i; j < 50000; j += i)
				mark[j] = 1;
		}
	}
}

void print_vector(vector<int> input) 
{
	cout << "print vector:";
	for (int i = 0; i < input.size(); ++i) 
	{
		cout << input[i];
	}

	cout << '\n';
}

int main()
{
	sieve();
	P;
	int n = 3501;
	vector<int> perpare;

	for (int i = 0;i < n;++i)
	{
		perpare.push_back(i+1);
	}

	int x;
	while(cin >> x)
	{
		if (x == 0) break;
		vector<int> test(perpare.begin(), perpare.begin() + x);
		int current = 0;
		for (int i = 0; i< x - 1; ++i)
		{
			//cout << i << "round\n";
			//print_vector(test);
			int kill = current + P[i + 1] - 1;
			int array_size = test.size();
			test.erase(test.begin() + (kill % array_size));

			//cout << "kill, current, size " << kill << '\t' << current << '\t' << array_size << '\n';


			//print_vector(test);

			current = kill % array_size;
		}
		cout << test[0] << '\n';
	}


	return 0;
}
