#include<iostream>
using namespace std;

void StringCopy() //string复制比较
{
	string str1("dacd");
	string str2("dbce");

	cout << (str1 < str2) << endl; //真返回1，假返回0
	cout << (str1.compare(str2)) << endl; //前大于后返回1,等于0小于-1
	cout << (str1.compare(2, 3, str2)) << endl;//第几位进行比较

	char arrStr[6] = { 0 };
	str2.copy(arrStr, 1, 2); //个数，起始位置
	cout << arrStr << endl;
}
//int main()
//{
//	StringCopy();
//}