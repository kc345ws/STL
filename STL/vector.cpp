#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<array>
#include<ctime>  //time.h
using namespace std;

void fun(int n)
{
	cout << n;
}

void STLDefine() //定义vector
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

void STLConstructor() //vector构造函数
{
	vector<int> vec;

	/*cout << vec[8] << endl;*/

	vector<int> vec1(5); //默认为n个0

	for (int i = 0; i < 5; i++)
	{
		cout << vec1[i] << endl;
	}

	vector<int> vec2(5, 12); //5个12

	for (int i = 0; i < 5; i++)
	{
		cout << vec2[i] << endl;
	}

	vector<char> vec3(5, 'a'); //5个a
	for (int i = 0; i < 5; i++)
	{
		cout << vec3[i] << endl;
	}

	vector<int> vec4(vec1); //用另一个vector进行拷贝构造 类型必须相同
	for (int i = 0; i < 5; i++)
	{
		cout << vec4[i] << endl;
	}

	//==================================

	vector<int>::iterator ite = vec2.begin();//vector迭代器
	vector<int>::iterator ite1 = vec2.end();

	vector<int> vec5(ite, ite1);
	for (int i = 0; i < 5; i++)
	{
		cout << vec5[i] << endl;
	}
	//注意必须手动控制迭代器的位置
}

void STLCapacity() //vector容量
{
	vector<int> vec;
	cout << vec.capacity() << endl; //对象初始化个数就是容量大小

	vector<int> vec1(5); //五个0
	cout << vec1.capacity() << endl;
	
	vec1.push_back(1);//申请已存在空间的一半 5+ 5/2 =7

	cout << vec1.capacity() << endl;

	vec1.push_back(1);//不申请空间
	vec1.push_back(1);//再次申请空间的一半 7+ 7/2=10
	//vc增加一倍
	cout << vec1.capacity() << endl;

	vector<int> vec3(4); 
	vec3.reserve(11); //只能增大不能减小，数值是多少就修改为多大
	cout << vec3.capacity() << endl;
	//重新分配空间后迭代器失效，必须手动控制迭代器

	cout << vec3.size() << endl;//size()为元素个数
	vec.resize(3);//改变size,字符小于现有容量则容量不变
	cout << vec.empty() << endl; //空1非空0
}

void STLDO()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i); //向vector添加i
	}

	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << vec.at(i) << endl; //注意at为()而不是[]
	}

	cout << vec.back() << endl; //尾元素
	
	vector<int>::iterator ite;
	
	ite = vec.begin();

	for (ite; ite != vec.end(); ite++)
	{
		cout << *ite << endl;
	}
	ite = vec.begin();//必须手动控制迭代器位置

	for_each(vec.begin(),vec.end(),fun);
}

void STLADD()
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	vec.insert(vec.begin() + 2, 412);//插入第三个元素位置
	for_each(vec.begin(), vec.end(), fun);  //包含#include<algorithm>

	cout << endl;
	vec.insert(vec.begin() + 4, 10, 22);
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;

	vector<int> vec1(5, 1); //5个1
	vec1.insert(vec1.begin() + 2, vec.begin(), vec.begin() + 4);//被插入bein  插入起始  末尾
	for_each(vec1.begin(), vec1.end(), fun);
}

void STLDelete() //删除
{
	vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	vec.pop_back(); //删除最后一个元素
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;

	vec.erase(vec.begin()+3); //删除第n个元素
	for_each(vec.begin(), vec.end(), fun);

	cout << endl;

	vec.erase(vec.begin() + 5, vec.end()); //从第n个删除到最后一个
	for_each(vec.begin(), vec.end(), fun);

	vec.clear();//清楚所有元素
}

void STLChange() //修改
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

	//void assign();//重新复制，清除以前的
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
	vec1.swap(vec2); //交换
	
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
	sort(vec.begin(), vec.end());//从小到大排序
	cout << endl;
	for_each(vec.begin(), vec.end(),fun);
	cout << endl;
	sort(vec.begin(), vec.end(), greater<int>()); //包含#include<functional>
	for_each(vec.begin(), vec.end(), fun);
}

void RandomShuffle()
{
	int Sum = 0;
	vector<int> vec;
	for (int i = 0; i < 99; i++)
	{
		vec.push_back(0);
	}
	/*for_each(vec.begin(), vec.end(), fun);*/
	vec.push_back(1);
	srand((unsigned int)time(0));//调用系统时间
	random_shuffle(vec.begin(), vec.end()); //乱序排序
	/*for_each(vec.begin(), vec.end(), fun);*/
	vector<int>::iterator ite = vec.begin();
	for (ite; ite != vec.end(); ite++)
	{
		Sum++;
		cout << *ite;
		if (Sum == 10)
		{
			Sum %= 10;
			cout << endl;
		}

	}
	
}

////int main()
//{
//	/*STLDefine();
//	STLConstructor();*/
//	/*STLCapacity();*/
//	/*STLDO();*/
//	/*STLADD();*/
//	/*STLDelete();*/
//	/*STLChange();*/
//	/*STLSwap();*/
//	/*STLAlgo();*/
//	/*RandomShuffle();*/
//	return 0;
//}