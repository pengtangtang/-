/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：BST.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _BST_H
#define _BST_H
//二叉搜索查找树
//二叉查找树（BST：Binary Search Tree）是一种特殊的二叉树，它改善了二叉树节点查找的效率。二叉查找树有以下性质：
//
//对于任意一个节点 n，
//
//其左子树（left subtree）下的每个后代节点（descendant node）的值都小于节点 n 的值；
//其右子树（right subtree）下的每个后代节点的值都大于节点 n 的值。
//所谓节点 n 的子树，可以将其看作是以节点 n 为根节点的树。子树的所有节点都是节点 n 的后代，而子树的根则是节点 n 本身。


//查找结点：BST 算法查找时间依赖于树的拓扑结构。最佳情况是 O(log­2n)，而最坏情况是 O(n)。
//插入结点：BST 的插入算法的复杂度与查找算法的复杂度是一样的：最佳情况是 O(log­2n)，而最坏情况是 O(n)。因为它们对节点的查找定位策略是相同的。
//删除结点：和查找、插入算法类似，删除算法的运行时间也与 BST 的拓扑结构有关，最佳情况是 O(log­2n)，而最坏情况是 O(n)。
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template<typename Key,template Value>
class BST{
	private:
		struct Node {
			Key key;
			Value value;
			Node* left;
			Node* right;

			Node(Key k,Value v) {
				key = k;
				value = v;
				left = right = NULL;
			}

			Node(Node* node) {
				key = node->key;
				value = node->value;
				left = node->left;
				right = node->right;
			}
		};

		Node* root;
		int count;

	public:
		BST() {
			root = NULL;
			count = 0;
		}

		~BST() {
			destory(root);
		}

		int size() {
			return count;
		}

		bool isEmpty() {
			return 0 == count;
		}

		void insert(Key key,Value value) {
			root = insert(root,key,value);
		}

		bool contain(Key key) {
			return contain(root,key);
		}

		Value* search(Key key) {
			bool f = contain(key);
			if (f) 
				search(root,key);
		}

		void set(Key key,Value value) {
			Node* node = Search(root,key);
			if (node)
				node->value = value;
		}

	private:
		enum Tag { visit,print };
		struct Command {
			Tag tag;
			Node* node;

			Common(Tag t,Node* n) : tag(t),node(n) {}
		};

	public:
		//前序遍历----上层与命令结合
		vector<pair<Key,value> > _preOrder() {
			vector<pair<Key,Value> > res;
			if (NULL == root)  return res;

			stack<Command> stack;
			stack.push(Command(visit,root));
			while (!stack.empty()) {
				Command command = stack.top();
				stack.pop();
				if (command.tag == print)
					res.push_back(make_pair(command.node->key,command.node->value));
				else {
					if (command.node->right)
						stack.push(Command(visit,command.node->right));
					if (command.node->left)
						stack.push(Command(visit,command.node->left));
					stack.push(Command(print,command.node));
				}
			}
			return res;
		}

		vector<pair<Key,Value> > preOrder() {
			vector<pair<Key,Value> > res;
			preOrder(root,res);
			return res;
		}

		//中序遍历--与相关命令结合
		vector<pair<Key,Value> > _inOrder() {
			vector<pair<Key,Value> > res;
			if (NULL == root) return res;
			stack<Command> stack;
			stack.push(Command(visit,root));
			while (!stack.empty()) {
				Command command = stack.top();
				stack.pop();
				if (command.tag == print)
					res.push_back(make_pair(command.node->key,command.node->value));
				else {
					if (command.node->right)
						stack.push(Command(visit,command.node->right));
					stack.push(Command(print,command.node));
					if (command.node->left)
						stack.push(Command(visit,command.node->left));
				}
			}

			return res;
		}

		vector<pair<Key,Value> > inOrder() {
			vector<pair<Key,Value> > res;
			inOrder(root,res);
			return res;
		}

		//后序遍历---上层
		vector<pair<Key,Value> > _postOrder() {
			vector<pair<Key,Value> > res;//保存后续遍历结果
			if (root == NULL) return res;
			stack<Command> stack;//根据tag确定入栈还是放入vector

			stack.push(Command(visit,root));
			while (!stack.empty()) {
				Command command = stack.top();
				stack.pop();
				if (command.tag == print)
					res.push_back(make_pair(command.node->key,command.node->value));
				else {
					stack.push(Command(print,command.node));
					if (command.node->right)
						stack.push(Command(visit,command.node->right));
					if (command.node->left)
						stack.push(Command(visit,command.node->left);
				}
			}
		}

		vector<pair<Key,Value> > postOrder() {
			vector<pair<Key,Value> > res;
			postOrder(root,res);
			return res;
		}

		//层序遍历---将每一层的结点放入队列然后依次出队，
		vector<pair<Key,Value> > levelOrder() {
			vector<pair<Key,Value> > res;
			queue<Node*> q;
			q.push(root);

			while (!q.empty()) {
				Node* node = q.front();
				q.pop();
				res.push_back(make_pair(node->key,node->value));
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			return res;
		
		}

		//寻找最大值--向右找
		Key maximum() {
			assert(count != 0);
			Node* maxNode = maximum(root);
			return maxNode->key;
		}

		//寻找最小指--向左找
		Key minimum() {
			assert(count != 0);
			Node* minNode = minimum(root);
			return minNode->key;
		}

		void removeMin() {
			if (root)
				root = removeMin(root);
		}

		void removeMax() {
			if (root)
				root = removeMax(root);
		}

		Value* remove(Key key) {
			root = remove(root,key);
			return &root->value;
		}

		Node* predecessor(Key key) {
			return predecessor(root,key);
		}

		Node* successor(Key key) {
			return successor(root,key);	
		}

		Node* ceil(Key key) {
			if (0==count || key>maximum()) return NULL;
			return ceil(root,key);
		}

		Node* floor(Key key) {
			if (0==count || key<minimum()) return NULL;
			return floor(root,key);
		}

	private:
		//递归插入
		Node* insert(Node* node,Key key,Value value) {
			if (node == NULL)
			{
				count++;
				return new Node(key,value);
			}

			if (key == node->key)
				node->value = value;
			else if (key < node->key)
				node->left = insert(node->left,key,value);
			else
				node->right = insert(node->right,key,value);

			return node;
		}

		//非递归插入
		Node* Non_Recursion_InsertNode(Node* node,Key key,Value value)
		{
			if (node == NULL)
			{
				node = new Node(key,value);
				count++;
				return node;
			}
			Node* pre = node;
			Node* cur = node;

			while (cur) {//直到分支结束，找到一个合适的叶子结点
				pre = cur;
				if (key == pre->key) {//该结点已经存在
					pre->value = value;
					return node;
				}
				else if (key < pre->key)
					cur = cur->left;
				else
					cur = cur->right;
			}
			if (key < pre->key)
				pre->left = new Node(key,value);
			else
				pre->right = new Node(key,value);
			count++;
			return node;
		}

		//递归查找key是否存在
		bool contain(Node* node,Key key) {
			if (node == NULL)  return false;
			if (key == node->key) return true;
			else if (key < node->key)
				return contain(node->left,key);
			else
				return contain(node->right,key);
		}

		//非递归查找
		bool Non_Recursion_Contain(Node* node,Key key) {
			if (node == NULL) return false;

			Node* cur = node;
			while (cur) {
				if (key == cur->key)
					return true;
				else if (key < cur->key)
					cur = cur->left;
				else
					cur = cur->right;
			}
			return true;
		}

		Value* search(Node* node,Key key) {
			if (node == NULL) return NULL;

			if (key == node->key) return &node->value;
			else if(key < node->key)
				return search(node->left,key);
			else
				return search(node->right,key);
		}

		Node* Search(Node* node,Key key) {
			if (node == NULL) return NULL;

			if (node->key == key)
				return node;
			else if(key < node->key)
				return Search(node->left,key);
			else
				return Search(node->right,key);
		}

		void preOrder(Node* node,vector<pair<Key,Value> >& res)
		{
			if (node) {
				res.push_back(make_pair(node->key,node->value));
				preOrder(node->left,res);
				preOrder(node->right,res);
			}
		}

		void inOrder(Node* node,vector<pair<Key,Value> >& res)
		{
			if (node) {
				inOrder(node->left,res);
				res.push_back(make_pair(node->key,node->value));
				inOrder(node->right,res);
			}
		}

		void postOrder(Node* node,vector<pair<Key,Value> >& res)
		{
			if (node) {
				postOrder(node->left,res);
				postOrder(node->right,res);
				res.push_back(make_pair(node->key,node->value));
			}
		}

		void destroy(Node* node) {
			if (node) {
				destroy(node->left);
				destroy(node->right);
				delete node;
				count--;
			}
		}

		Node* minimum(Node* node) {
			if (node == NULL) return node;
			return minimum(node->left);
		}

		Node* Non_Recursion_Minimum(Node* node) {
			Node* currentNode = node;
			if (currentNode == NULL)
				return NULL;

			while (currentNode->left != NULL)
				currentNode = currentNode->left;

			return currentNode;
		}

		Node* maximum(Node* node) {
			if (node == NULL) return node;
			return maximum(node->right);
		}

		Node* Non_Recursion_Maximum(Node* node) {
			Node* currentNode = node;
			if (currentNode == NULL)
				return NULL;

			while (currentNode->right != NULL)
				currentNode = currentNode->right;

			return currentNode;
		}

		Node* removeMin(Node* node) {
			if (node->left == NULL) {
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}
			node->left = removeMin(node->left);
			return node;
		}

		Node* Non_Recursion_RemoveMin(Node* node) {
			Node* root = node;
			Node* currentNode = node,*p = node;
			Node* parentNode = node;

			if (currentNode == NULL)
				return NULL;
			//迭代：结点左孩子不为空，一直迭代
			while (currentNode->left != NULL)
			{
				parentNode = currentNode;
				currentNode = currentNode->left;
			}
			
			//左孩子为空
			if (currentNode == parentNode) {
				Node* tmp = currentNode->right;
				delete currentNode;
				count--;
				return tmp;
			}
			//传递进来的左孩子不为空，而是通过迭代找到最小
			parentNode->left = currentNode->right;
			delete currentNode;
			count--;
			return p;
		}

		Node* removeMax(Node* node) {
			if (node->right == NULL) {
				Node* lefhtNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			node->right = removeMin(node->right);
			return node;
		}

		Node* Non_Recursion_RemoveMax(Node* node) {
			Node* currentNode = node,*p = node;
			Node* parentNode = node;

			if (currentNode == NULL)
				return NULL;
			//迭代：结点右孩子不为空，一直迭代
			while (currentNode->right != NULL)
			{
				parentNode = currentNode;
				currentNode = currentNode->right;
			}
			
			//右孩子为空
			if (currentNode == parentNode) {
				Node* tmp = currentNode->left;
				delete currentNode;
				count--;
				return tmp;
			}
			//传递进来的左孩子不为空，而是通过迭代找到最小
			parentNode->right = currentNode->left;
			delete currentNode;
			count--;
			return p;
		}

		//删除结点
		Node* remove(Node* node,Key key) {
			if (node == NULL) return NULL;

			if (key < node->key){//左孩子查找
				node->left = remove(node->left,key);
				return node;
			}else if (key > node->right) {//右孩子查找
				node->right = remove(node->right,key);
				return node;
			} else {//key == node->key--找到了结点
				if (node->left == NULL) {
					Node* rightNode = node->right;
					delete node;
					count--;
					return rightNode;
				}
				if (node->right == NULL) {
					Node* leftNode = node->left;
					delete node;
					count--;
					return leftNode;
				}
				//左右孩子均不为空--》左孩子最大或右孩子最小
				//右孩子子树中最小
				Node* successor = new Node(minimum(node->right));
				count++;
				successor->right = removeMin(node->right);
				successor->left = node->left;
				delete node;
				count--;
				return successor;

				/*左孩子子树最大
				Node* successor = new Node(maximum(node->right));
				count++;
				successor->left = removeMin(node->left);
				successor->right = node-->right;
				delete node;
				count--;
				return successor;
				 *
				 * */
			}
		}

		//天花板：以node为根的二叉搜索树中，寻找key的ceil值
		//所处的结点
		Node* ceil(Node* root,Key key) {
			if (root == NULL) return NULL;

			if (key == root->key) return root;

			if (root->key < key) return ceil(root->right,key);


			Node* tmpNode = ceil(root->left,key);
			if (tmpNode) return tmpNode;
			return root;
		}

};
#endif
