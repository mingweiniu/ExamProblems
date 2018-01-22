#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <iterator>

#include <cstdlib>

using namespace std;

bool is_symble(const string & input);
string cal(const string & left, const string & right, const string & oper);
string prefix_expression(const vector<string> & input);
string pop(stack<string> & target);


template<class T>
void turn(const std::string & input, T & output)
{
	std::istringstream(input) >> output;
}

template<class T>
void turn(const T & input, std::string & output )
{
	std::ostringstream oss;
	oss << input;
	output = oss.str();
}

int main() {

	const char * input =
		"- * + 23 % 45 10 6 / 77 12\n"
		"+ * 234 56\n"
		".\n";
	istringstream input_stream(input);


	string temp;
	vector<vector<string> > inputData;

	// change "input_stream" to "cin" when upload
	while (getline(cin, temp)) {
		if (temp == ".") break;
		// spilt string to several part
		istringstream cutter(temp);
		istream_iterator<string> begin(cutter), end;
		vector<string> test(begin, end);
		inputData.push_back(test);
	}

	// start calculate each input line
	for (int i = 0; i < static_cast<int>(inputData.size()); ++i) {
		string ans = prefix_expression(inputData[i]);
		cout << ans << "\n";
		//if (i < inputData.size() - 1) cout << '\n';
	}
	
	//auto x = 3;

}

bool is_symble(const string & input) {
	if (input == "+") return true;
	if (input == "-") return true;
	if (input == "*") return true;
	if (input == "/") return true;
	if (input == "%") return true;
	return false;
}

string cal(const string & left_in, const string & right_in, const string & oper) {

	int left, right;
	turn(left_in, left);
	turn(right_in, right);

	if (oper == "+") left += right;
	if (oper == "-") left -= right;
	if (oper == "*") left *= right;
	if (oper == "/") left /= right;
	if (oper == "%") left %= right;

	string output;
	turn(left, output);

	return output;
}


string prefix_expression(const vector<string> & input) {

	// init left
	stack<string> left;
	stack<string> right;
	for (int i = 0; i < static_cast<int>(input.size()); ++i) {
		left.push(input[i]);
	}

	// doing the answer
	while (!(left.empty() && right.empty()))
	{
		if (left.empty())
		{
			if (right.size() == 1) {
				return right.top();
			}
			else
			{
				return "illegal";
			}
		}
		else // left not empty
		{
			string z = pop(left);

			if (is_symble(z))
			{
				//cout << z << "is symble\n";
				if (right.size() >= 2) {
					string x = pop(right);
					string y = pop(right);
					right.push(cal(x, y, z));
				}
				else // right has not enough 
				{
					return "illegal";
				}
			}
			else
			{
				//cout << z << "is not symble\n";
				right.push(z);
			}
		}
	}
	return "illegal";
}

string pop(stack<string> & target) {
	string output = target.top();
	target.pop();
	return output;
}
