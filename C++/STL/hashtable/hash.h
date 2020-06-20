/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：hash.h
*   创 建 者：pengtangtang
*   创建日期：2020年05月06日
*   描    述：
*
*   更新日志：
*
================================================================*/
#ifndef _HASH_H
#define _HASH_H
#include <map>
#include <vector>
template<typename Key,typename Value>
class HashTable
{
	private:
		const static int upperTol = 3;
		const static int lowerTol = 1;
		const static int initCapacity = 1;
		const vector<int> capacity = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317,196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843,50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};
		int capacityIndex = 0;
		map<Key,Value> **hashtable;
		int M;
		int size;


	public:
		HashTable() 
		{
			M = capacity[capacityIndex],size = 0;
			this->hashtable = new map<Key,Value>* [M];
			for (int i = 0;i < M;i++)
				this->hashtable[i] = new map<Key,Value>;
		}

		~HashTable()
		{ free(M); }


		int hashFunc(Key key)
		{
			std::hash<Key> h;
			return (h(key) & 0x7fffffff) % M;
		}

		void add(Key key,Value value)
		{
			if (hashtable[hashFunc(key)] == NULL || hashtable[hashFunc(key)]->count(key) == 0)
			{
				if (hashtable[hashFunc(key)] == NULL)
					hashtable[hashFunc(key)] = new map<Key,Value>;
				size++;
				if (size >= maxCapacity() && capacityIndex+1 < capacity.size())
				{
					capacityIndex++;
					resize(capacity[M]);
				}
			}else{
				hashtable[hashFunc(key)]->erase(key);
				hashtable[hashFunc(key)]->insert(make_pair(key,value));

			}
		}

		Value remove(Key key)
		{
			Value ret = -1;
			if (contains(key))
			{
				hashtable[hashFunc(key)]->erase(key);
				size--;
				ret = 0;
				if (size < minCapacity() && capacityIndex-1 >= 0) 
				{
					capacityIndex--;
					resize(capacityIndex);
				}
			}
			return ret;
		}

		void set(Key key,Value value)
		{
			if (!contains(key))
				cout << "no this key\n";
			hashtable[hashFunc(key)]->erase(key);
			hashtable[hashFunc(key)]->insert(make_pair(key,value));
		}

		Value get(Key key)
		{
			if (contains(key))
				return hashtable[hashFunc(key)]->at(key);
			return 0;
		}

		bool contains(Key key)
		{
			return hashtable[hashFunc(key)]==NULL || this->hashtable[hashFunc(key)]->count(key)==0
				? false : true;
		}

		int getSize()
		{
			return size;
		}

		Value maxCapacity()
		{
			return M*upperTol;
		}

		Value minCapacity()
		{
			return M*lowerTol;
		}

		void resize(int newM)
		{
			cout << "resize = " << newM << endl;
			map<Key,Value>** newHashTable = new map<Key,Value>* [newM];
			for (int i = 0;i < newM;i++)
				newHashTable[i] = new map<Key,Value>;

			int oldM = M;
			this->M = newM;
			for (int i = 0;i < oldM;i++)
			{
				map<Key,Value> m = *(hashtable[i]);
				for (auto p : m)
					newHashTable[hashFunc(p.first)]->insert(make_pair(p.first,p.second));
			}

			free(oldM);
			this->hashtable = newHashTable;
		}
	private:
		void free(int M)
		{
			for (int i = 0;i < M;i++)
			{
				if (hashtable[i])
					delete hashtable[i];
			}
			delete []hashtable;
		}

		template<typename K,typename V>
		friend ostream& operator<<(ostream& out,HashTable<K,V>& hash);
};
		template<typename K,typename V>
		ostream& operator<<(ostream& out,HashTable<K,V>& hash)
		{
			out << hash.getSize() << endl ;
			return out;
		}
#endif
