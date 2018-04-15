#include<iostream>
#include<string>
using namespace std;

void StringOstream()
{
	string str1("abcdefg1");

	cout << str1 << endl;

	cout << str1.c_str() << endl; //返回str首地址

	cout << str1[0] << endl;

	cout << str1.at(3) << endl; //返回下表的地址

	try
	{
		str1.at(123); //抛出一个out_of_range
	}

	catch (...)
	{
		cout << "越界" << endl;
	}

}

//int main()
//{
//	StringOstream();
//}