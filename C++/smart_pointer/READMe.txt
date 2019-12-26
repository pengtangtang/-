
定义：
	smart_pointer是个特殊的类模板，重载了-> *运算符，实现了c++的自动回收内存机制



实现机制：
	引用计数：将一个计数器与类指向的对象相关联，引用计数器跟踪该类有多少个对象指向同一个对象。



分类：
	1）shared_ptr
	实质：是一种计数指针，当引用计数变为0时，shared_ptr所指向的对象就会被删除。在使用shared_ptr分配内存时建议使用make_shared(会自动调用类的复制构造函数)函数，最安全。理解为一片空间可以有多个shared_ptr指向。
	形式：shared_ptr<demo> p = make_shared<demo>(demo)
	      shared_ptr<demo> p (new demo);


	2)unique_ptr
	同一时刻只能有一个unique_ptr指向给定对象（禁止拷贝）
	有一个可以用于数组的变体：std::unique_ptr<double[]>pda(new double(5))


	3）week_ptr
	a:弱指针指向一个已经用shared_ptr进行管理的对象。
	b:只有当对象存在的时候，才需要对其进行访问。
	c:不会改变shared_ptr计数器
	d：可能被其他人修改释放，并且在最后一次使用之后调用其析构函数（用来释放不具名的内存）
	e：可以通过shared_ptr的构造函数或weak_ptr的成员函数lock()转化为一个shared_ptr指针；

	4）auto_ptr
	最好少用，没有其他指针安全；
	如：auto_ptr<string> p (new string("hello"));
	auto_ptr<string> q;
	q = p;//剥夺了p的所有权，使p成为一个空指针，当再次使用p时会出错。




注意事项：
	1）定义赋值运算符，使之执行深复制。这样两个指针将指向不同的对象，其中一个对象是另一个对象的副本。
	2）建立所有权概念，对于特定的对象，只能有一个智能指针可拥有它，这样只有拥有对象的智能指针的构造函数会删除该对象。然后，让赋值操作转换所有权。
	3）创建智能更高的指针，跟踪引用特定对象的智能指针数。称为引用计数。仅当最后一个指针过期时，才调用delete。这是shared_ptr的策略。
	4)三类智能指针不能混合使用。
	5)unique_ptr优于auto_ptr



警告：
	1）使用new分配内存时，才能使用auto_ptr和shared_ptr,使用new[]分配内存时，不能使用他们。不使用new分配内存时，不能使用auto_ptr或shared_ptr;不使用new或new[]分配内存时，不能使用unique_ptr.




smart_pointer的选择
	1）shared_ptr
	使用多个指向同一个对象的指针
	a---有一个指针数组，并使用一些辅助指针来标识特定的元素，如最大元素和最小元素；
	b---两个对象都包含指向第三个对象的指针
	c--STL容器包含指针
	2)unique_ptr
	如果函数使用new分配内存，并返回指向该内存的指针

