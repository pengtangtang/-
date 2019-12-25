/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：sales.h
*   创 建 者：pengtangtang
*   创建日期：2019年12月18日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _SALES_H
#define _SALES_H

#include <stdexcept>//定义类logic_error runtim_error----从exception类继承来
#include <string>
/*
 *说明：基类Sales 派生类LabeledSales
 嵌套类：基类bad_index  派生类nbad_index -----------用来抛出异常，都继承于logic_error,在重载运算符[]时判断并抛出异常
 * */

class Sales{
	public:
		enum {MONTHS = 12};//枚举变量为十二个月

		class bad_index : public std::logic_error//嵌套的类，用于异常处理
		{
			private:
				int bi;
			public:
				explicit bad_index(int ix,const std::string& s = "Index error in Sales object\n");
				int bi_val() const {return bi;} //返回错误号
				virtual ~bad_index()
					throw(){}//在析构时抛出异常
		};
		
		//构造函数--初始化
		explicit Sales(int yy = 0);
		Sales(int yy,const double* gr,int n);

		virtual ~Sales() {}
		int Year() const {return year;}
		
		//[]重载-----会实例化bad_index抛出异常
		virtual double operator [] (int i) const;
		virtual double& operator[] (int i);
	private:
		double gross[MONTHS];//存储销售量
		int year;//年份
};

class LabeledSales:public Sales//继承而来的子类
{
	public:
		class nbad_index:public Sales::bad_index{//继承嵌套类而来的子类，异常处理类
			private:
				string lbl;
			public:
				nbad_index(const std::string& lb,int ix,
						const std::string& s= "Index error in LabelSales object\n");
				
				const std::string& label_val() const { return lbl; }

				virtual ~nbad_index()
					throw() {}
		};
		
		//构造函数
		explicit LabeledSales(const std::string& lb = "none",int yy = 0);
		LabeledSales(const std::string& lb,int yy,const double *gr,int n);
		
		virtual ~LabeledSales() {}

		const std::string& Label() const { return label; }

		//实例化nbad_index，抛出异常
		virtual double operator[] (int i) const;
		virtual double& operator[] (int i);
	private:
		std::string label;
};

#endif
