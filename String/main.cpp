#include<iostream>
using namespace std;

class String
{
	int size;
	char* str;
public:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size]{};
		cout << "DefaultConstruct:\t" << this << endl;
	}

	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor:\t" << this << endl;
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	String str (5); // Default constructor
	str.print();


	String str1 = "Hello";
}