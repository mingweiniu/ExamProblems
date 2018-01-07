
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
string prefix(const vector<string> & input);
string pop(stack<string> & target);

int main() {
	
	const char * input = 
		"- * + 23 % 45 10 6 / 77 12\n"
		"+ *234 56\n"
		".\n";
	istringstream input_stream(input);
	

	string temp;
	vector<vector<string>> inputData;
	
	while ( getline(input_stream, temp)) {
		if (temp == ".") break;
		// spilt string to several part
		istringstream cutter(temp);
		istream_iterator<string> begin(cutter), end;
		vector<string> test(begin, end);
		inputData.push_back(test);
	}

	// start calculate each input line
	for (int i = 0; i < inputData.size(); ++i) {
		string ans = prefix(inputData[i]);
		cout << ans;
		if (i < inputData.size() - 1) cout << '\n';
	}

}

bool is_symble(const string & input) {
	if (input == "+") return true;
	if (input == "-") return true;
	if (input == "*") return true;
	if (input == "/") return true;
	if (input == "%") return true;
	return false;
}

string cal(const string & left, const string & right, const string & oper) {

	int output;

	if (oper == "+") output = stoi(left) + stoi(right);
	if (oper == "-") output = stoi(left) - stoi(right);
	if (oper == "*") output = stoi(left) * stoi(right);
	if (oper == "/") output = stoi(left) / stoi(right);
	if (oper == "%") output = stoi(left) % stoi(right);
	

	return to_string(output);
}


string prefix(const vector<string> & input) {
	stack<string> left;
	stack<string> right;
	for (int i = 0; i < input.size(); ++i) {
		left.push(input[i]);
	}

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


}

string pop(stack<string> & target) {
	string output = target.top();
	target.pop();
	return output;
}
