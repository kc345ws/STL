#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

void fun(int i)
{
	cout << i;
}

void STLDefine() //����vector
{
	struct STU
	{
		int age;
	};

	vector<int> vec;
	/*vector<struct STU> vec;*/
	/*vector<int*> vec;*/
	/*vector<string> vec;*/ //==vector<char> vec;
}

void STLConstructor() //vector���캯��
{
	vector<int> vec;

	/*cout << vec[8] << endl;*/

	vector<int> vec1(5); //Ĭ��Ϊn��0

	for (int i = 0; i < 5; i++)
	{
		cout << vec1[i] << endl;
	}

	vector<int> vec2(5, 12); //5��12

	for (int i = 0; i < 5; i++)
	{
		cout << vec2[i] << endl;
	}

	vector<char> vec3(5, 'a'); //5��a
	for (int i = 0; i < 5; i++)
	{
		cout << vec3[i] << endl;
	}

	vector<int> vec4(vec1); //����һ��vector���п������� ���ͱ�����ͬ
	for (int i = 0; i < 5; i++)
	{
		cout << vec4[i] << endl;
	}

	//==================================
	vector<int>::iterator ite = vec2.begin();//vector������
	vector<int>::iterator ite1 = vec2.end();

	vector<int> vec5(ite, ite1);
	for (int i = 0; i < 5; i++)
	{
		cout << vec5[i] << endl;
	}
	//ע������ֶ����Ƶ�������λ��
}

void STLCapacity() //vector����
{
	vector<int> vec;
	cout << vec.capacity() << endl; //�����ʼ����������������С

	vector<int> vec1(5); //���0
	cout << vec1.capacity() << endl;
	
	vec1.push_back(1);//�����Ѵ��ڿռ��һ�� 5+ 5/2 =7

	cout << vec1.capacity() << endl;

	vec1.push_back(1);//������ռ�
	vec1.push_back(1);//�ٴ�����ռ��һ�� 7+ 7/2=10
	//vc����һ��
	cout << vec1.capacity() << endl;

	vector<int> vec3(4); 
	vec3.reserve(11); //ֻ�������ܼ�С����ֵ�Ƕ��پ��޸�Ϊ���
	cout << vec3.capacity() << endl;
	//���·���ռ�������ʧЧ�������ֶ����Ƶ�����

	cout << vec3.size() << endl;//size()ΪԪ�ظ���
	vec.resize(3);//�ı�size,capacity����
	cout << vec.empty() << endl; //��1�ǿ�0
}

void STLDO()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i); //��vector���i
	}

	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << vec.at(i) << endl; //ע��atΪ()������[]
	}

	cout << vec.back() << endl; //βԪ��
	
	vector<int>::iterator ite;
	
	ite = vec.begin();

	for (ite; ite != vec.end(); ite++)
	{
		cout << *ite << endl;
	}
	ite = vec.begin();//�����ֶ����Ƶ�����λ��

	for_each(vec.begin(),vec.end(),fun);
}

void STLADD()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	vec.insert(vec.begin() + 2, 412);//���������Ԫ��λ��
	for_each(vec.begin(), vec.end(), fun);  //����#include<algorithm>

	cout << endl;
	vec.insert(vec.begin() + 4, 10, 22);
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;

	vector<int> vec1(5, 1); //5��1
	vec1.insert(vec1.begin() + 2, vec.begin(), vec.begin() + 4);//������bein  ������ʼ  ĩβ
	for_each(vec1.begin(), vec1.end(), fun);
}

void STLDelete() //ɾ��
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	vec.pop_back(); //ɾ�����һ��Ԫ��
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;

	vec.erase(vec.begin()+3); //ɾ����n��Ԫ��
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;

	vec.erase(vec.begin() + 5, vec.end()); //�ӵ�n��ɾ�������һ��
	for_each(vec.begin(), vec.end(), fun);

}

void STLChange() //�޸�
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	vector<int>::iterator ite;
	ite = vec.begin();
	for (ite; ite != vec.end(); ite++)
	{
		*ite = 3;
	}
	for_each(vec.begin(), vec.end(),fun);
}

void STLSwap()
{
	vector<int> vec1;
	for (int i = 0; i < 5; i++)
	{
		vec1.push_back(i);
	}
	vector<int> vec2;
	for (int i = 5; i < 10; i++)
	{
		vec2.push_back(i);
	}
	for_each(vec1.begin(), vec1.end(), fun);
	cout << endl;
	for_each(vec2.begin(), vec2.end(), fun);
	vec1.swap(vec2); //����
	
	cout << endl;

	for_each(vec1.begin(), vec1.end(), fun);
	cout << endl;
	for_each(vec2.begin(), vec2.end(), fun);

	cout << endl;

	cout << (vec1 > vec2) << endl;
}

void STLAlgo()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(4);
	for_each(vec.begin(), vec.end(), fun);
	sort(vec.begin(), vec.end());//��С��������
	cout << endl;
	for_each(vec.begin(), vec.end(),fun);
	cout << endl;
	sort(vec.begin(), vec.end(), greater<int>()); //����#include<functional>
	for_each(vec.begin(), vec.end(), fun);
}

int main()
{
	/*STLDefine();
	STLConstructor();*/
	/*STLCapacity();*/
	/*STLDO();*/
	/*STLADD();*/
	/*STLDelete();*/
	/*STLChange();*/
	/*STLSwap();*/
	STLAlgo();
	return 0;
}