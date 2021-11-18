#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this-> x = x;
	}
	void set_y(double y)
	{
		this-> y = y;
	}


	//Point()
	//{
	//	x = y = double();
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}

	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstructor:\t" << this << endl;
	//}

	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	void print() const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	//Operators:

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	//increment/ Decrement

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

};

double distance(Point A, Point B)
{
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

Point& operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;

}
Point& operator-(const Point& left, const Point& right)
{
	Point result(left.get_x()- right.get_x(), left.get_y()-right.get_y());
	return result;
}

Point operator* (const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X= " << obj.get_x() << "\tY = " << obj.get_y();
	return os;
}

//#define delimiter"\n----------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	//cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	//cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	//cout << delimiter << endl;
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	//cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	//cout << delimiter << endl;  
#endif // DISTANCE_CHECK



#ifdef CONSTRUCTORS_CHECK
	cout << int() << endl;
	Point A;	//Default constructor
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;
	B.print();

	Point C(7);
	C.print();

	Point D(4, 5);
	D.print();

	Point E = D;
	E.print();

	Point F;
	F = E;
	F.print();
#endif // CONSTRU

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << "\n-----------------------------------------------\n" << endl;
	A = B = C = Point(2, 3);
	cout << "\n-----------------------------------------------\n" << endl;
#endif // ASSIGNMENT_CHECK

#define ARITHMETICAL_OPERATORS_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	Point B(3, 4);
	for (Point i = 0; i.get_x() < 10; i++)
	{
		i.print();
	}
	A += B;
	A.print();
	B = A++;
	//A.print();
	//B.print();
	cout << A <<endl;
	cout << B <<endl;
	Point C = A + B;
	C.print();
	Point D = A - B;
	D.print();
	(A * B).print();
#endif ARITHMETICAL_OPERATORS_CHECK
}