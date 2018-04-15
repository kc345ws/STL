#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

struct Node
{
	int a;
	char c;

	Node(int d, char e) //���幹�캯����ֻ���ù��캯����ֵ
	{
		a = d;
		c = e;
	}

	Node() //�ṹ�������Ĭ�Ϲ��캯��
	{

	}

	bool operator == (const Node& f)  //����֧��remove()����
	{
		if (f.a == this->a&& f.c == this->c)
		{
			return true;
		}
		else
			return false;
	}

	bool operator< (const Node&f) //����֧��sort()����
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

void ListDefine() //list����
{
	list<Node> ls(5);
	Node no(123, 'qwe');
	list<Node> ls1(6, no);
	

	list<Node>::iterator ite = ls1.begin();
	ite++;//�ӵڶ���Ԫ�ؿ�ʼ
	ite++;//�ӵ�����Ԫ�ؿ�ʼ
	list<Node> ls2(ite , ls1.end());
	//����ʹ��ite+2

	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;
	for_each(ls2.begin(), ls2.end(), Fun);
}

void ListSize()  //list��С
{
	Node no(12, 'qq');
	list<Node> ls(5, no);
	cout << ls.size() << endl;
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.resize(4);//��������Ԫ�ظ���
	cout << ls.size() << endl;
	for_each(ls.begin(), ls.end(), Fun);

	cout << endl;
	cout << ls.empty() << endl;//��1�ǿ�0
}

void ListCoutAdd() //list���
{
	Node no(1, 'w');
	list<Node> ls(5, no);
	//list��֧���±����㲻֧���������
	for (list<Node>::iterator ite = ls.begin(); ite != ls.end(); ite++)
	{
		cout << ite->a << " " << ite->c << endl;
	}
	cout << endl;

	cout << ls.back().a << " "<< ls.back().c <<endl; //����βԪ��
	cout << endl;

	cout << ls.front().a << " " << ls.front().c << endl; //������Ԫ��
	cout << endl;

	list<Node> ls1;
	ls1.push_front(Node(38, 'a'));//�����
	ls1.push_front(Node(22, 'asd'));//����ӣ�����ӵ�������ӵ�ǰ��
	ls1.push_back(Node(512, 'qwe'));//β���
	ls1.push_back(Node(6212, 'scvd'));//β��ӣ�����ӵ�������ӵĺ���
	list<Node>::iterator ite;
	ite = ls1.begin();
	ls1.insert(ite, Node(123, 'p'));//���Ԫ�غ�������Զ�����ƶ�һ��
	ite++;
	ls1.insert(ite, Node(777, 'tty'));
	ls1.insert(ite, 3, Node(8769, 'hh')); //������
	for_each(ls1.begin(), ls1.end(), Fun);
}

void ListChange() //list�޸�
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


	ls.pop_back();//β��ɾ��
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.pop_front();//�ײ�ɾ��
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	list<Node>::iterator ite = ls.begin();
	ite++;
	ls.erase(ite);//ɾ��������ָ����λ��
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ite = ls.begin();
	//ls.erase(ite , --ls.end()); //ɾ����--ls.end()ǰ���Ǹ�Ԫ��Ϊֹ
	//end()ָ��ĩβԪ�ص���һ��
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.remove(Node(6, 'g'));//ɾ���������ͬ��Ԫ��
	//�������������==
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.unique();//ɾ����ͬԪ��ֻʣһ��
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.clear();//ȫ�����
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.assign(3, Node(522, 'tg'));//���¸��ƣ�ԭ�������
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	list<Node> ls1;
	ls1 = ls; //��ֵ����������޸�
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;

	ite = ls.begin();
	ite++;
	ls1.assign(ite, ls.end());//ͨ���������޸�
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;

}

void ListDo() //list����
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

	ls.reverse();//��תԪ�� ע������reserve()Ԫ�ظ���
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls.sort();//��������<�����
	for_each(ls.begin(), ls.end(), Fun);
	cout << endl;

	ls1.swap(ls);
	for_each(ls.begin(), ls.end(), Fun);
	for_each(ls1.begin(), ls1.end(), Fun);
	cout << endl;
	
	
}

void ListMerge()//list�ϲ�
{
	list<Node> ls, ls1;
	ls.push_back(Node(1, 'a'));
	ls.push_back(Node(2, 'b'));
	ls1.push_back(Node(3, 'c'));


	ls.sort();
	ls1.sort();
	ls.merge(ls1);//�ϲ�������sort
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
	c2.splice(where_iter, c1);//ƴ�Ӻ��� ��c1ƴ�ӵ�c2�ϲ����c1 (ƴ��λ�ã���ƴ��list)
	for_each(c1.begin(), c1.end(), Fun1);
	cout << endl;
	for_each(c2.begin(), c2.end(), Fun1);
	cout << endl;

	c2.splice(where_iter, c3, first_iter);//(ƴ��λ�� �� ��ƴ��list ����ƴ��list��Ԫ��)
	for_each(c2.begin(), c2.end(), Fun1);
	cout << endl;

	first_iter = c4.begin();
	
	c2.splice(where_iter, c4, first_iter, last_iter); //(ƴ��λ�� ����ƴ��list ����ƴ��list����ʼԪ�� , ��ƴ��list����Ԫ��)
	for_each(c2.begin(), c2.end(), Fun1);
	cout << endl;
}

void ListFind() //list����
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
	//û�ҵ������
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