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
#include <cmath>

namespace VECTOR
{
	const double Rad_to_deg = 45.0/atan(1.0);/*atan()反正切函数。rad_to_deg:弧度到角度的比率
	弧度到角度值的转换： 角度 = 弧度值*rad_to_deg

	45度角的正切=1，反正切atan(1.0)得到的是45度角的弧度值
	所以：1弧度 = 45.0/atan(1.0)度

	弧度 = 角度/rad_to_deg;
	类在使用角度时以度为单位
	*/

	void Vector::set_mag()
	{
		mag = sqrt(x*x+y*y);
	}

	void Vector::set_ang()
	{
		if(x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y,x);
		/*tan2函数返回的是原点至点(x,y)的方位角，即与 x 轴的夹角。也可以理解为复数 x+yi 的辐角。返回值的单位为弧度，取值范围为[-PI,PI]  */
	}

	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	
	/*状态成员*/
	Vector::Vector(double n1,double n2,Mode form)
	{
		mode = form;
		if(form == RECT){
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if(form == POL){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else{
			cout << "Incorrect 3rd argument  to Vector\n";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1,double n2,Mode form)
	{
		mode = form;
		if(form == RECT){
			x = n1;
			y = n2;
			set_ang();
			set_mag();
		}
		else if(form == POL){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else{
			cout << "Incorrect 3rd argument  to Vector\n";
			cout << "vector set to 0\n";
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

	Vector Vector::operator + (const Vector &b)const
	{
		return Vector(x+b.x,y+b.y);
	}

	Vector Vector::operator - (const Vector &b)const
	{
		return Vector(x-b.x,y-b.y);
	}

	Vector Vector::operator - ()const
	{
		return Vector(-x,-y);
	}

	Vector Vector::operator *(double n)const
	{
		return Vector(x*n,y*n);
	}

	Vector operator *(double n,const Vector &a)
	{
		return a*n;
	}

	ostream& operator << (ostream& os,const Vector& v)
	{
		if(v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << "," << v.y << ")";
		else if(v.mode == Vector::POL)
			os << "(m,a) = (" << v.mag << "," << v.ang*Rad_to_deg << ")";
		else
			os << "Vector object is invalid\n";

		return os;
	}
}
