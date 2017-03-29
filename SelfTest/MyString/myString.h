
#include <cstdlib>
#include <iostream>

class myString;

class myString
{
public:
	myString(void);
	myString(const char* input);
	~myString();
	myString operator+(const myString& input);
	
	myString operator=(myString input);
	myString operator+=(myString input);
	char operator[](int place);
	int getSize();

private:
	int size;
	char* container;
	int cal_str_size(const char* input);

};

myString::myString(void)
{
	std::cout << " \t myString(void) \n";
	size = 1;
	container = new char[size];	
}


myString::myString(const char* input)
{
	std::cout << " \t myString(const char * input) \n";
	auto n = cal_str_size(input);
	size = n + 1 ;

	container = new char[size];
	for (int i = 0; i < n; ++i) {
		container[i]= input[i];
	}	
}

myString::~myString()
{
	std::cout << " \t ~myString() \n";
	if (container != NULL) {
		delete[] container;
		container = (char*)NULL;
	}
}

myString myString::operator+(const myString &)
{
	std::cout << " \t operator+(const myString &) \n";

	return myString();
}

myString myString::operator=(myString input)
{
	std::cout << " \t operator=(const myString &) \n";
	
	auto n = input.getSize();


	return *this;
}

myString myString::operator+=(myString input)
{
	std::cout << " \t operator+=(const myString &) \n";

	auto n = input.getSize();
	
	auto big_n = n + size;
	
	auto temp = new char[big_n];
	for (int i = 0; i < n; ++i) {
		temp[i] = container[i];
	}


	delete[] container;
	container = temp;

	for (int i = n; i < big_n; ++i) {
		container[i] = input[i];
	}

	size = big_n;

	return *this;
}

char myString::operator[](int position)
{
	std::cout << " \t operator[](int position) \n";
	if (position < size - 1) {
		return container[position];
	}
	
	return 0;
}

int myString::getSize()
{
	return size - 1;
}

int myString::cal_str_size(const char * input)
{
	auto n = 0;
	while (input[n] != '\0') {
		++n;
	}
	return n;
}


myString operator+(const char* left, const myString & right)
{
	std::cout << "\t myString operator+(char * words, const myString &) " << '\n';

	myString input(left);

	input += right;

	return input;
}



std::ostream& operator<<(std::ostream& os, myString str)
{
	std::cout << "\t operator<<" << '\n';
	for (int i = 0; i < str.getSize(); ++i) {
		auto temp = str[i];
		std::cout << str[i] << '\n';
		os << temp;
	}
		
	return os;
}