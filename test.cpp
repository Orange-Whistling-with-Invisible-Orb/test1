#include<iostream>
using namespace std;

class Point
{
private:
	double x, y;
public:
	Point(double x = 0, double y = 0) :x(x), y(y) {}
	
	friend ostream& operator<<(ostream& out, const Point& p);
	//左置
	Point& operator++()
	{
		x++;
		y++;
		return *this;//没有形参，直接返回this指针的指针运算结果
	}
	Point& operator--()
	{
		x--;
		y--;
		return *this;
	}
	//右置
	Point operator++(int)
	{
		Point temp = *this;//副本
		x++;
		y++;
		return temp;
	}
	Point operator--(int)
	{
		Point temp = *this;
		x--;
		y--;
		return temp;
	}
	
	~Point() {};
};
ostream& operator<<(ostream& out, const Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

int main()
{
	Point p1(3, 4);
	cout << p1 << endl;
	Point p2(p1++);
	Point p3 = ++p1;
	cout << p2 << ";" << p3 << ";" << p1 << endl;
	Point p4 = --p1;
	Point p5 = p1--;
	cout << p4 << ";" << p5 << ";" << p1 << endl;
	return 0;
}
