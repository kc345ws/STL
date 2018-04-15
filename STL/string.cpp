#include<iostream>
#include<string>

using namespace std;

void StringDefine() //定义string
{
	string str; //只针对字符串

	cout << str << " " << str.empty() << endl; //empty空返回1非空返回0

	string str1(5, 'a'); //赋值5个a

	cout << str1 << " " << str1.empty() << endl;

	string str2("abcdefg");

	cout << str2 << endl;

	string str3("asdasd", 3); //截断

	cout << str3 << endl;

	string str4(str2, 2, 4); //赋值第3-5个

	cout << str4 << endl;

	string str5(str2); //调用拷贝构造

	cout << str5 << endl;



}

//int main()
//{
//	StringDefine();
//}