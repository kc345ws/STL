#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
void fun(char);

int main()
{
	string str("asdvasdaf");

	for_each(str.begin(), str.end(), fun);//遍历对象中的每一个元素

	sort(str.begin(), str.end()); //排序算法默认从小到大

	cout << " " << endl;

	for_each(str.begin(), str.end(), fun);

	sort(str.begin(), str.end(), greater<char>()); //从大到小排序

	cout << " " << endl;

	for_each(str.begin(), str.end(), fun);
}

void fun(char c) //容器元素的类型
{
	cout << c;
}