#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
void fun(char);

int main()
{
	string str("asdvasdaf");

	for_each(str.begin(), str.end(), fun);//���������е�ÿһ��Ԫ��

	sort(str.begin(), str.end()); //�����㷨Ĭ�ϴ�С����

	cout << " " << endl;

	for_each(str.begin(), str.end(), fun);

	sort(str.begin(), str.end(), greater<char>()); //�Ӵ�С����

	cout << " " << endl;

	for_each(str.begin(), str.end(), fun);
}

void fun(char c) //����Ԫ�ص�����
{
	cout << c;
}