#include<iostream>
#include<string>

using namespace std;

void StringFind() //string查找字符
{
	string str1("asavwesad");
	string str2("sad");

	cout << str1.find(str2, 0) << endl;//在前面string查找后面返回位数

	cout << str1.substr(0, 10) << endl;//下表，打印个数

	str2.swap(str1);//交换

	cout << str1 << endl;

	cout << str1 + str2 << endl;//加法连接
}
//int main()
//{
//	StringFind();
//}