/*===============================================================
*   Copyright (C) 2020 All rights reserved.
*   
*   文件名称：file_stream.cpp
*   创 建 者：pengtangtang
*   创建日期：2020年05月13日
*   描    述：
*
*   更新日志：
*
================================================================*/
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int firstCharacterIndex(const string& s,int start)
{
	//字符串s从start位置开始返回第一个字母位置对应的index
	for (int i = start;i < s.length();i++) {
		if (isalpha(s[i]))
			return i;
	}
	return s.length();
}

//将字符串s中的所有字母转换成小写字母
string lower(const string& s)
{
	string ret = " ";
	for (int i = 0;i <s.length();i++)
		ret += tolower(s[i]);
	return ret;
}

//读取文件名称为filename中的内容，并将其中包含的所有词语放进words中
bool readFile(const string& filename,vector<string>& words)
{
	string line;
	string contents = " ";
	ifstream file(filename);
	if (file.is_open())
	{
		while (getline(file,line))
			contents += (line + "\n");
		file.close();
	}else {
		cout << "can not open file\n";
		return false;
	}

	int start = firstCharacterIndex(contents,0);
	for (int i = start+1;i <= contents.length();) {
		if (i == contents.length() ||
				!isalpha(contents[i]))
		{
			words.push_back(lower(contents.substr(start,i-start)));
			start = firstCharacterIndex(contents,i);
			i = start + 1;
		}else
			i++;
		return true;
	}
}

int main(int args,char** argv)
{
	vector<string> words;
	vector<string>::iterator  it = words.begin();
	cout << "main\n";
	if (readFile(argv[1],words))
	{
		//for (auto p : words)
		for (;it != words.end();it++)
			cout << *it << endl;
	}
		return 0;
}
