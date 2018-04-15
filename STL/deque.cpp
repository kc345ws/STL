#include<deque>
#include<iostream>
using namespace std;

int main(int argc, char* argv)
{
	deque<int> de;
	de.push_back(12);

	deque<int>::iterator iter = de.begin();

	for (iter; iter != de.end(); iter++)
	{
		cout << *iter << endl;
	}
}
//随机位置插入 删除效率不高 数据量521
//支持随机访问比vector慢 因为要做堆跳转
//迭代器结构复杂 降低访问效率
//支持头添加和尾添加

//随机访问操作频率高选择vector
//插入删除频率高，头尾添加选list，list不支持随机访问
//随机访问+头添加选deque

//没有capacity和size
//多了push_back和pop_back
//其他函数一样

