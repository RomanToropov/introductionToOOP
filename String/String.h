#pragma once
#include<iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;


// Class Declaration - объ€вление класса

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	int size;	//–азмер строки в Ѕайтах
	char* str;	//”казатель на строку в динамической пам€ти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constrcutors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);

	String(String&& other);

	String& operator=(String&& other);

	String& operator+=(const String& other);

	~String();

	//				Operators:

	String& operator=(const String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};
// CLASS DECLARATION END - конец объ€влени€ класса.
//----------------------------------------------------------------------------------------//