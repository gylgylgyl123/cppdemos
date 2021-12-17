/*
9-7 STL容器的统计与二分查找
*/
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

void Display(int a)
{
	cout <<  a << endl;
}

int main()
{
	int ones[] = { 1,2,3,4,5 };
	int twos[] = { 10,20,30,40,50};
	int result[5];
	transform(ones, ones + 5, twos, result,std::plus<int>());		//这个地方std中的plus是一个仿函数
	//for_each(result, result + 5, Display);
	//不用上面的形式，使用ambda表达式,匿名函数，参考阅读链接：
	//https://www.cnblogs.com/jimodetiantang/p/9016826.html
	for_each(result, result + 5, 
		[](int a)->void 
		{cout << a << endl; });

	//find
	int arr[] = { 0,1,2,3,4,6,6,333,8,9 };
	vector<int> iA(arr+3, arr + 4);	
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "len = " << len << endl;
	cout << count(arr, arr + len, 333) << endl;//统计333的个数
	cout << count_if(arr, arr + len, bind2nd(less<int>(), 7)) << endl;//统计小于7的个数
	//二分查找，在数据结构和算法中要求是一个有序的序列
	cout << binary_search(arr, arr + len, 10) << endl;	//0
	cout << binary_search(arr, arr + len, 8) << endl;	//应该是1但是输出0？
	cout << binary_search(arr, arr + len, 0) << endl;	//1

	cout << *search(arr, arr + len, iA.begin(), iA.end()) << endl;
	return 0;
}




