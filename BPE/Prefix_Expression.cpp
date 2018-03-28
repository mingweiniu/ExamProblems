#include <cstdlib>
#include <cmath>

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

template<class T>
void Convert(const string & input, T & output)
{
	istringstream(input) >> output;
}

template<class T>
void Convert(const T & input, string & output)
{
	ostringstream oss;
	oss << input;
	output = oss.str();
}

vector<string> SpiltStringStream(const string &input)
{
	istringstream buffer(input);
	istream_iterator<string> begin(buffer), end;
	return vector<string>(begin, end);
}


bool IsSymble(const string & input);
string Calculator(const string & left, const string & right, const string & oper);
string CalPrefixExpression(const vector<string> & input);
string PopStack(stack<string> & target);

int main() {

	istringstream test_stream(
		"- * + 23 % 45 10 6 / 77 12\n"
		"+ * 234 56\n"
		// "." terminate
		".\n");


	string one_line;
	vector<vector<string> > inputData;

	// change "test_stream" to "cin" when upload
	while (getline(test_stream, one_line)) {
		if (one_line == ".") break;
		inputData.push_back(SpiltStringStream(one_line));
	}


	int data_set_num = static_cast<int>(inputData.size());
	for (int i = 0; i < data_set_num; ++i) {
		cout << CalPrefixExpression(inputData[i]);
		if (i < data_set_num - 1)
		{
			cout << '\n';
		}
	}
}

bool IsSymble(const string & input) {
	if (input == "+") return true;
	if (input == "-") return true;
	if (input == "*") return true;
	if (input == "/") return true;
	if (input == "%") return true;
	return false;
}

string Calculator(const string & left_in, const string & right_in, const string & oper) {

	int left, right;
	Convert(left_in, left);
	Convert(right_in, right);

	if (oper == "+") left += right;
	if (oper == "-") left -= right;
	if (oper == "*") left *= right;
	if (oper == "/") left /= right;
	if (oper == "%") left %= right;

	string output;
	Convert(left, output);

	return output;
}


string CalPrefixExpression(const vector<string> & input) {

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
		else 
		{
			// left not empty
			string z = PopStack(left);

			if (IsSymble(z))
			{
				//cout << z << "is symble\n";
				if (right.size() >= 2) {
					string x = PopStack(right);
					string y = PopStack(right);
					right.push(Calculator(x, y, z));
				}
				else 
				{
					// right has not enough 
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

string PopStack(stack<string> & target) {
	string output = target.top();
	target.pop();
	return output;
}
