#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

struct Node
{
	int a;
	char c;

	Node(int d, char e) //定义构造函数后，只能用构造函数赋值
	{
		a = d;
		c = e;
	}

	Node() //结构体必须有默认构造函数
	{

	}

	bool operator == (const Node& f)  //用来支持remove()函数
	{
		if (f.a == this->a&& f.c == this->c)
		{
			return true;
		}
		else
			return false;
	}

	bool operator< (const Node&f) //用来支持sort()函数
	{
		if (f.a < this->a && f.c < this->c)
		{
			return true;
		}
		else
			return false;
	}
};

void Fun(Node& d)
{
	cout << d.a << " " << d.c << endl;
}

void Fun1(int i)
{
	cout << i << " ";
}

void ListDefine() //list定义
{
	list<Node> ls(5);
	Node no(123, 'qwe');
	list<Node> ls1(6, no);
	

	list<Node>::iterator ite = ls1.begin();
	ite++;//从第二个元素开始
	ite++;//从第三个元素开始
	list<Node> ls2(ite , ls1.end());
	//不能使用ite+2

	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;
	for_each(ls2.begin(), ls2.end(), Fun);
}

void ListSize()  //list大小
{
	Node no(12, 'qq');
	list<Node> ls(5, no);
	cout << ls.size() << endl;
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.resize(4);//重新设置元素个数
	cout << ls.size() << endl;
	for_each(ls.begin(), ls.end(), Fun);

	cout << endl;
	cout << ls.empty() << endl;//空1非空0
}

void ListCoutAdd() //list输出
{
	Node no(1, 'w');
	list<Node> ls(5, no);
	//list不支持下表运算不支持随机访问
	for (list<Node>::iterator ite = ls.begin(); ite != ls.end(); ite++)
	{
		cout << ite->a << " " << ite->c << endl;
	}
	cout << endl;

	cout << ls.back().a << " "<< ls.back().c <<endl; //返回尾元素
	cout << endl;

	cout << ls.front().a << " " << ls.front().c << endl; //返回首元素
	cout << endl;

	list<Node> ls1;
	ls1.push_front(Node(38, 'a'));//首添加
	ls1.push_front(Node(22, 'asd'));//首添加，后添加的在先添加的前面
	ls1.push_back(Node(512, 'qwe'));//尾添加
	ls1.push_back(Node(6212, 'scvd'));//尾添加，后添加的在先添加的后面
	list<Node>::iterator ite;
	ite = ls1.begin();
	ls1.insert(ite, Node(123, 'p'));//添加元素后迭代器自动向后移动一格
	ite++;
	ls1.insert(ite, Node(777, 'tty'));
	ls1.insert(ite, 3, Node(8769, 'hh')); //插入多个
	for_each(ls1.begin(), ls1.end(), Fun);
}

void ListChange() //list修改
{
	list<Node> ls;
	ls.push_back(Node(0, 'a'));
	ls.push_back(Node(1, 'b'));
	ls.push_back(Node(2, 'c'));
	ls.push_back(Node(3, 'd'));
	ls.push_back(Node(4, 'e'));
	ls.push_back(Node(5, 'f'));
	ls.push_back(Node(5, 'f'));
	ls.push_back(Node(6, 'g'));
	ls.push_back(Node(7, 'h'));
	ls.push_back(Node(8, 'i'));
	ls.push_back(Node(9, 'j'));


	ls.pop_back();//尾部删除
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.pop_front();//首部删除
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	list<Node>::iterator ite = ls.begin();
	ite++;
	ls.erase(ite);//删除迭代器指定的位置
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ite = ls.begin();
	//ls.erase(ite , --ls.end()); //删除到--ls.end()前面那个元素为止
	//end()指向末尾元素的下一个
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.remove(Node(6, 'g'));//删除与参数相同的元素
	//必须重载运算符==
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.unique();//删除相同元素只剩一个
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.clear();//全部清除
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.assign(3, Node(522, 'tg'));//重新复制，原来的清除
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	list<Node> ls1;
	ls1 = ls; //赋值运算符进行修改
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;

	ite = ls.begin();
	ite++;
	ls1.assign(ite, ls.end());//通过迭代器修改
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;

}

void ListDo() //list交换
{
	list<Node> ls;
	ls.push_back(Node(0, 'a'));
	ls.push_back(Node(1, 'b'));
	ls.push_back(Node(2, 'c'));
	ls.push_back(Node(3, 'd'));
	ls.push_back(Node(4, 'e'));
	ls.push_back(Node(5, 'f'));
	ls.push_back(Node(5, 'f'));
	ls.push_back(Node(6, 'g'));
	ls.push_back(Node(7, 'h'));
	ls.push_back(Node(8, 'i'));
	ls.push_back(Node(9, 'j'));

	list<Node> ls1;
	ls1.push_back(Node(123, 'qw'));
	for_each(ls.begin(), ls.end(), Fun);
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;

	ls.reverse();//翻转元素 注意区分reserve()元素个数
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.sort();//必须重载<运算符
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls1.swap(ls);
	for_each(ls.begin(), ls.end(), Fun);
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;
	
	
}

void ListMerge()//list合并
{
	list<Node> ls, ls1;
	ls.push_back(Node(1, 'a'));
	ls.push_back(Node(2, 'b'));
	ls1.push_back(Node(3, 'c'));


	ls.sort();
	ls1.sort();
	ls.merge(ls1);//合并必须先sort
	//for_each(ls.begin(), ls.end(), Fun);
	cout << endl;


	list<int> c1{ 10,11 };
	list<int> c2{ 20,21,22 };
	list<int> c3{ 30,31 };
	list<int> c4{ 40,41,42,43 };
	list<int>::iterator where_iter = c2.begin();
	list<int>::iterator first_iter = c3.begin();
	list<int>::iterator last_iter = c4.end();
	where_iter++;
	c2.splice(where_iter, c1);//拼接函数 将c1拼接到c2上并清空c1 (拼接位置，被拼接list)
	for_each(c1.begin(), c1.end(), Fun1);
	cout << endl;
	for_each(c2.begin(), c2.end(), Fun1);
	cout << endl;

	c2.splice(where_iter, c3, first_iter);//(拼接位置 ， 被拼接list ，被拼接list的元素)
	for_each(c2.begin(), c2.end(), Fun1);
	cout << endl;

	first_iter = c4.begin();
	
	c2.splice(where_iter, c4, first_iter, last_iter); //(拼接位置 ，被拼接list ，被拼接list的起始元素 , 被拼接list结束元素)
	for_each(c2.begin(), c2.end(), Fun1);
	cout << endl;
}

void ListFind() //list查找
{
	list<Node> ls;
	ls.push_back(Node(0, 'a'));
	ls.push_back(Node(1, 'b'));
	ls.push_back(Node(2, 'c'));
	ls.push_back(Node(3, 'd'));
	ls.push_back(Node(4, 'e'));
	ls.push_back(Node(5, 'f'));
	ls.push_back(Node(5, 'f'));
	ls.push_back(Node(6, 'g'));
	ls.push_back(Node(7, 'h'));
	ls.push_back(Node(8, 'i'));
	ls.push_back(Node(9, 'j'));

	list<Node>::iterator iter = find(ls.begin(), ls.end(), Node(6, 'g'));

	cout <<iter->c << " "<<endl;
	//没找到则崩溃
}
//int main(int argc , char* argv)
//{
//	/*ListDefine();*/
//	/*ListSize();*/
//	/*ListCoutAdd();*/
//	/*ListChange();*/
//	/*ListDo();*/
//	/*ListMerge();*/
//	ListFind();
//	return 0;
//}