#include<iostream>
using namespace std;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
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

int String:: get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String:: get_str()
{
	return str;
}

//				Constrcutors
String::String(int size) :size(size), str(new char[size] {})
{
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstruct:\t" << this << endl;
}
String:: String(const char* str) : size(strlen(str) + 1), str(new char[size] {})
{
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String:: String(const String& other)
{
	//Deep copy:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}

String::String(String&& other) : size(other.size), str(other.str)
{
	this->size = other.size;
	this->str = other.str;//�������� ��������� �� ��� ���������� ������, ������������� ������� �������.
	other.str = nullptr; // �������� ��������� � ������ �������, ����� ���������� �� ���� ������� ������, ������� ��� �����������.
	other.size = 0;
	cout << "MoveConstructor: " << this << endl;
}

String& String:: operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size = 0;
	cout << "MoveAssignment:\t" << this << endl;
}

String& String:: operator+=(const String& other)
{
	return *this = *this + other;
}

String::~String()
{
	delete[] this->str;
	this->str = nullptr;
	this->size = 0;
	cout << "Destructor:\t" << this << endl;
}

//				Operators:

String& String:: operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	//Deep copy:
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

const char& String:: operator[](int i)const
{
	return str[i];
}
char& String:: operator[](int i)
{
	return str[i];
}

//				Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
//#define OPERATOR+CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str(5);	//Default constrcutor
	str.print();

	String str1 = "Hello";
	str1 = str1;
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;		//CopyConstructor
	cout << str2 << endl;
	//Deep copy
	//Shallow copy

	String str3;
	str3 = str2;			//CopyAssignment (operator=)
	str3.operator=(str2);
	cout << str3 << endl;

	int a = 2;
	int b = 3;
	a = b;
	cout << a << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR+CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;	//������ �������� �������� +
	cout << "\n-----------------------------------------------\n";
	cout << str3 << endl;
	//cout << operator+(str1, str2) << endl;	//����� ����� ��������� +

	//str1 += str2;
	//cout << str1 << endl;  
#endif // OPERATOR+CHECK

	String str1;
	cout << str1 << endl;

	String str2 = "Hello";
	cout << str2 << endl;

	String str3 = str2;
	cout << str3 << endl;

	
}