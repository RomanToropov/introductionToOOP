#include"String.h"






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
	String str3 = str1 + str2;	//Ќе€вно вызываем оператор +
	cout << "\n-----------------------------------------------\n";
	cout << str3 << endl;
	//cout << operator+(str1, str2) << endl;	//явный вызов оператора +

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