
RTTI:运行阶段类型识别
支持RTTI的3个元素：
		dynamic_cast运算符将使用一个指向基类的指针来生成一个指向派生类的指针，否则该运算符返回0--空指针
		typeid运算符返回一个指向对象的类型的值
		type_info结构存储类有关特定类型的信息

警告：RTTI仅适用于包含虚函数的类

1：dynamic_cast
	1)通常。如果指向的对象（*pt）的类型为Type或者是从Type直接或间接派生而来的类型，则下面的表达式将指针pt转换为Type类型的指针：
	dynamic_cast<Type *>(pt)
	否则结果为0，即空指针
	2）也可用于引用
		但没有与空指针对应的引用值，因此无法使用特殊的引用值指示失败
		当请求不正确会引发bad_cast异常--从exception派生而来，在头文件typeinfo中，可以使用异常机制解决。

2:typeid运算符和type_info类#适用于dynamic_cast和virtual函数不能处理的情况
	1）typeid运算符使得能够确定两个对象是否为同一种类型。与sizeof类似，可以接收的参数：（1）类名 （2）结果为对象的表达式
	2）typeid运算符返回一个对type_info对象的引用。
	   type_info定义在头文件typeinfo中的一个类
	   type_info类重载了== ！=运算符
	   eg:typied(Magnificent) == typied(*pg) ---若pg指向的为一个Magnificent对象，则结果为true
	3)type_info类包含name()成员----返回一个随实现而异的字符串：通常是类的名字
