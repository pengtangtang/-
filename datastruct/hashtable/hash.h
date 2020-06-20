/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：hash.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _HASH_H
#define _HASH_H
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

template<typename Key,typename Value>
class HashTable
{
	private:
		const static int upperTol = 3;
		const static int lowerTol = 1;
		const static int initCapacity = 1;
		map<Key,Value>** hashtable;//表示整个表
		int M;
		int size;
	public:
		//argument construct
		HashTable(int m) : M(m),size(0) {
			//this->hashtable = new map<Key,Value>** [M]();//自动初始化
			this->hashtable = new map<Key,Value>* [M];
			for (int i = 0;i < M;i++)
				this->hashtable[i] = new map<Key,Value>;
		}
		//default construct
		HashTable() {
			HashTable(initCapacity);
		}

		//destruct
		~HashTable()
		{
			free(M);
		}
	public:
		//get size
		int getSize() {
			return size;
		}

		//add new argument
		void add(Key key,Value value) {
			//没有拉链法出来的map,则分配空间；若有，且map中没有key对应的结点，则插入
			if (hashtable[hashFunc(key)] == NULL ||
					hashtable[hashFunc(key)]->count(key))
			{
				if (hashtable[hashFunc(key)] == NULL)
					hashtable[hashFunc(key)] = new map<Key,Value>;
				hashtable[hashFunc(key)]->insert(make_pair(key,value));
				size++;
				if (size >= maxCapacity())
					resize(2*M);

			}else {
				hashtable[hashFunc(key)]->erase(key);
				hashtable[hashFunc(key)]->insert(make_pair(key,value));
			}
		}

		//remove key
		Value remove(Key key) {
			Value ret = -1;
			if (contains(key)) {
				hashtable[hashFunc(key)]->erase(key);
				size--;
				if (0 == size)
					delete hashtable[hashFunc(key)];
				ret = 0;
				if (size < minCapacity() && M/2 >= initCapacity)
					resize(M/2);
			}
			return ret;
		}

		//set value
		void set(Key key,Value value) {
			if (contains(key))
				cout << "key not exist!\n";
			hashtable[hashFunc(key)]->erase(key);
			hashtable[hashFunc(key)]->insert(make_pair(key,value));
		}

		//if contains key
		bool contains(Key key) {
			return (hashtable[hashFunc(key)]==NULL || hashtable[hashFunc(key)]->count(key)==0) ? false : true;
		}

		//get value
		Value get(Key key) {
			if (contains(key))
				return hashtable[hashFunc(key)]->at(key);
			return 0;
		}

		//max capacity
		int maxCapacity() {
			return M*upperTol;
		}

		//min capacity
		int minCapacity() {
			return M*lowerTol;
		}

	private:
		//hash func
		int hashFunc(Key key) {
			std::hash<Key> h;//hash func----返回对应的哈析值 
			return (h(key) & 0x7fffffff) % M;

		}

		// operator <<
		template<typename K,typename V>
		friend ostream& operator<<(ostream& out,HashTable<K,V>& hashtable);

		void print() {
			string res = "{";
			for (int i = 0;i < this->M;i++) {
				if (this->hashtable[i]) {
					for (auto m:*(this->hashtable[i]))
						res += m.first + ":" + to_string(m.second) + ",";
				}
				res.replace(res.size()-1,string::npos,"}");
				cout << res << endl;
			}
		}

		//resize size
		void resize(int newM) {
			cout << "resize " << newM << endl;
			map<Key,Value>** newHashTable = new map<Key,Value>* [newM];
			for (int i = 0;i < newM;i++) 
				newHashTable[i] = new map<Key,Value>;
			int oldM = M;
			this->M = newM;
			for (int i = 0;i < oldM;i++) {
				map<Key,Value> m = *(hashtable[i]);
				for (auto p:m)
					newHashTable[hashFunc(p.first)]->insert(make_pair(p.first,p.second));
			}
			free(oldM);
			this->hashtable = newHashTable;
		}

	private:
		//free size
		void free(int M) {
			for (int i = 0;i < M;i++) {
				if (hashtable[i])
					delete hashtable[i];
			}
			delete [] hashtable;
		}

};

template<typename K,typename V>
ostream& operator<<(ostream& out,HashTable<K,V>& hashTable)
{
	hashTable.print();
	return out;
}

#endif
