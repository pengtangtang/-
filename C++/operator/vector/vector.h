/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：vector.h
*   创 建 者：pengtangtang
*   创建日期：2019年11月16日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _VECTOR_H
#define _VECTOR_H
#include <iostream>

namespace VECTOR
{
	class Vector{
		public:
			enum Mode {RECT,POL};
			Vector();
			Vector(double n1,double n2,Mode form = RECT);
			void reset(double n1,double n2 ,Mode form = RECT);
			~Vector();

			double xval()const{return x;}
			double yval()const{return y;}
			double magval()const{return mag;}
			double angval()const{return ang;}
			void polar_mode();
			void rect_mode();

			Vector operator + (const Vector &b)const;
			Vector operator - (const Vector &b)const;
			Vector operator - ()const;
			Vector operator * (double n)const;

			friend Vector operator * (double n,const Vector &a);
			friend ostream& operator << (ostream &os,const Vector &v);

			
		private:
			double x;
			double y;
			double mag;
			double ang;

			Mode mode;

			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
	};
}

#endif
