#include<iostream>
using namespace std;

void StringCapacity() //string����
{
	string str1(1, 'a'); //С��15������15����15+n*16
						 //vc����31����ÿ������32��
	str1.reserve(16);//�޸�����ֻ�������ܼ�С
	cout << str1.capacity() << endl;
	str1.resize(3);//�ضϸı��ַ������ȣ���������
	cout << str1.length() << endl;//�ַ�������
	cout << str1.size() << endl;//�ַ�����==length
}
//int main()
//
//{
//	StringCapacity();
//}