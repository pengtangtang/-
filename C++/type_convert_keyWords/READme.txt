
自定义转换函数：
1：语法
	operator typeName();
2:注意
	1）转换函数必须是类方法
	2）转换函数不能指定返回类型
	3）转换函数不能有参数
3:自动应用类型转换
	1）当同时提供多个自定义转换函数时，若使用隐式转换会产生二义性。（如:operator int()const; operator double()const;
	    long gone = pop;）
	2)当类定义了多种转换时，使用显示强制类型转换。
	如：long gone = int(pop);
4:提醒
	1）应该谨慎使用隐式转换函数。最好将选择仅在被显式地调用时才会执行的函数。
	2）构造函数只允许从某种类型到类的转换，反过来需要自定义转换函数。

5:分类
	1）基本数据类型之间的转换
	2)类之间类型转换
用于pointer, reference, nor a pointer-to-data-member type 类型转换

1:dynamic_cast
	使得能够在类层次结构中进行向上转换（由于is_a关系，这种转换是安全的）

2:const_cast
	1)语法和dynamic_cast类似
	const_cast<type-name>(expration)   ---type-name和expration类型必须相同，除了有无const和volatile特征外
	2)使用场景：有时需要这样一个值，它在大多时候是一个常量，而有时可以修改的。在这种情况下，可以将这个值声明为const，并在需要它的时候，使用const_cast
	3)注意const_cast不是万能的，它可以修改指向一个值的指针，但修改const值的结果是不确定的.我们可能调用了一个参数不是const的函数，而我们要传进去的实际参数确实const的，但是我们知道这个函数是不会对参数做修改的。于是我们就需要使用const_cast去除const限定，以便函数能够接受这个实际参数。
	使用const_cast去除const限定的目的绝对不是为了修改它的内容，只是出于无奈
	eg:1)const int i = 2;
	     int* p = const_cast<int *>(&i);
	     *p = 3;
	     cout << i << ' ' << *P << endl;
	     输出：2 3
	     2）const int m;
	     	cin >> m;
		int *mp = const_cast<int *>(&m);
		(*mp)++;
		cout << m << ' ' << *mp << endl;
		输入：4 输出：5

3:static_cast
	static_cast<type-name>(expression) ---仅当type-name和expression其中一个可以隐士转换为另一个时，转换才成功
	可用于其他各种数值转换

4：reinterpret_cast
	1）适用于依赖于实现底层编程技术
	eg:struct dat { short a; short b; };
	   long value = 0xA224B118;
	   dat* pd = reinterpret_cast<dat *>(value);
	   cout << pd->a;
	2)可以将指针类型转换为足以存储指针表示的整形，反之不行
	3）不能将函数指针与整数指针互相转换
