/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：vector.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月16日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include "vector.h"
namespace VECTOR
{
	Vector::Vector()
	{
		x = y = ang = mag = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1,double n2,Mode form)
	{
		mode = form;
		if(RECT == form){
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if(POL == form){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else{
			cout << "Incorrect 3rd argument to Vector()--\n";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1,double n2,Mode form)
	{
		mode = form;
		if(RECT == form){
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if(POL == form){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else{
			cout << "Incorrect 3rd argument to Vector()--\n";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{}

	void Vector::polar_mode()
	{
		mode = POL;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator + (const Vector& b) const
	{
		return Vector(x+b.x,y+b.y);
	}

	Vector Vector::operator - (const Vector& b) const
	{
		return Vector(x-b.x,y-b.y);
	}

	Vector Vector::operator - () const
	{
		return Vector(-x,-y);
	}
	Vector Vector::operator * (double n) const
	{
		return Vector(n*x,n*y);
	}

	Vector operator * (double n,const Vector& a)
	{
		return a*n;
	}

	ostream& operator << (ostream &os ,const Vector& v)
	{
		if(v.mode == Vector::RECT){
			os << "(x,y) = (" << v.x << ", " << v.y << ")\n";
		}
		else if(v.mode == Vector::POL){
			os << "(m,a) = (" << v.mag << ", " << v.ang << ")\n";
		}
		else{
			os << "vector mode is invalid\n";
		}

		return os;
	}

	void Vector::set_mag()
	{
		mag = sqrt(x*x+y*y);
	}

	void Vector::set_ang()
	{
		if(x == 0.0 && y == 0.0)
			ang = 0;
		else
			ang = atan2(y,x);
	}

	void Vector::set_x()
	{
		x = mag*cos(ang);
	}

	void Vector::set_y()
	{
		y = mag*sin(ang);
	}
}
