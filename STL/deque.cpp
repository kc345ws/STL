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
//���λ�ò��� ɾ��Ч�ʲ��� ������521
//֧��������ʱ�vector�� ��ΪҪ������ת
//�������ṹ���� ���ͷ���Ч��
//֧��ͷ��Ӻ�β���

//������ʲ���Ƶ�ʸ�ѡ��vector
//����ɾ��Ƶ�ʸߣ�ͷβ���ѡlist��list��֧���������
//�������+ͷ���ѡdeque

//û��capacity��size
//����push_back��pop_back
//��������һ��

