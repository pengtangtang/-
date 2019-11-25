/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：b_tree.cpp
*   创 建 者：pengtangtang
*   创建日期：2019年11月04日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <vector>

struct BinaryTreeNode:public std::enable_shared_from_this<BinaryTreeNode> {
	explicit BinaryTreeNode(const int value = 0)
	:value_(value),left{std::shared_ptr<BinaryTreeNode>{}},right{std::shared_ptr<BinaryTreeNode>{}}
	{}

	void insert(const int value)
	{
		if(value < value_){
			if(left){
				left->insert(value);
			}else{
				left = std::make_shared<BinaryTreeNode>(value);
			}
		}

		if(value > value_){
			if(right) {
				right->insert(value);
			}else{
				right = std::make_shared<BinaryTreeNode>(value);
			}
		}
	}

	void ldr()
	{
		if(left) {
			left->ldr();
		}

		std::cout << value_ << "\n";

		if(right) {
			right->ldr();
		}
	}

	void layer_print(){
		auto nodes = layer_contents();
		for(auto iter = nodes.begin();iter!=nodes.end();++iter){
			if(*iter){
				std::cout << (*iter)->value_ << " ";
			}else{
				std::cout << "\n";
			
			}
		}
	}

	int value_;

	std::shared_ptr<BinaryTreeNode> left;
	std::shared_ptr<BinaryTreeNode> right;
	private:
	std::vector<std::shared_ptr<BinaryTreeNode>> layer_contents()
	{
		std::vector<std::shared_ptr<BinaryTreeNode>> nodes;
		nodes.push_back(shared_from_this());
		node.push_back(nullptr);

		for(int index = 0;index<nodes.size();++index){
			if(!nodes[index]) {
				if(index==nodes.size()-1)
					break;
				nodes.push_back(nullptr);
				continue;
			}

			if(nodes[index]->left){
				nodes.push_back(nodes[index]->left);
			}
			if(nodes[index]->right){
				nodes.push_back(nodes[index]->right);
			}
		}
		return nodes;
	}
};


int main()
{
	auto root = std::make_shared<BinaryTreeNode>(3);
	root->insert(1);
	root->insert(2);
	root->insert(3);
	root->insert(4);
	root->insert(5);
	root->insert(6);
	root->insert(7);

	root->ldr();
	cout << endl;
	root->layer_print();
	return 0;
}
