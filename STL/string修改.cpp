#include<iostream>
#include<string>
using namespace std;

void StringChange() //stringĞŞ¸Ä
{
	string str("abcdefg");
	str[2] = 'h';
	cout << str << endl;
	str.at(3) = 'q';
	cout << str << endl;	
	str.insert(str.begin(), 'q'); //²åÈë
}

//int main()
//{
//	StringChange();
//}

