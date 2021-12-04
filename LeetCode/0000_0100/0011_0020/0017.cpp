// 1678. Goal Parser Interpretation


class Solution {
public:
    string interpret(string command) {
		command = regex_replace(command, regex("[\(]+[\)]"), "o");
		return regex_replace(command, regex("[\(\)]"), "");
    }
};