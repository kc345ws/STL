#include<iostream>
using namespace std;

void StringCapacity() //string容量
{
	string str1(1, 'a'); //小于15个申请15个，15+n*16
						 //vc至少31个，每次增加32个
	str1.reserve(16);//修改容量只能增大不能减小
	cout << str1.capacity() << endl;
	str1.resize(3);//截断改变字符串长度，容量不变
	cout << str1.length() << endl;//字符串长度
	cout << str1.size() << endl;//字符个数==length
}
//int main()
//
//{
//	StringCapacity();
//}