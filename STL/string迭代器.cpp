#include<iostream>
#include<string>
using namespace std;

void StringIterator() //string迭代器
{
	string str("asbasdf");

	string::iterator ite;//迭代器 vector::iterator::ite

						 /*char*a = str.c_str;*/
	ite = str.begin();//返回string首地址的迭代器
	for (ite; ite != str.end(); ite++)
	{
		cout << *ite << " ";
	}
	ite = str.begin();
	for (int i = 0; i < str.size(); i++)
	{
		cout << *ite << " ";
		ite++;
	}
	//end()最后一个的下一个


	//相当于一个指向string对象元素的指针 本质char*指针
	/*int a;*/
}

//int main()
//{
//	StringIterator();
//}