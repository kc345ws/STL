#include<iostream>
#include<string>
using namespace std;

void StringInsert() //string插入
{
	string str("abcdefgh");
	string str1("zxcbnm");
	str.insert(str.begin() + 2, 4, 'q'); //起始位置 插入个数 插入字符
	cout << str << endl;

	str.insert(str.begin() + 2, str1.begin(), str1.end()); //被插入数组位置 插入数组起始位置末尾位置
	cout << str << endl;
}
//
//int main()
//{
//	StringInsert();
//}