#include <algorithm>
#include <iostream>

using namespace std;
//c++方式
bool MySort(int a, int b)
{
	return a < b;
}

void Display(int a)
{
	cout << a << " ";
}

//C++泛型
template<class T>
inline bool MySortT(T const& a, T const& b)			//GYL需要注意这里inline和传递常引用的两个优化点,同时注意这个地方const&位置有点奇怪,ls写的是T const& a.我先试了const&T,行不通，改成T const& a后通过
{
	return a < b;
}

template<class T>
inline void DisplayT(T const& a)
{
	cout << a << " ";
}

//C++仿函数
struct SortF
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct DisplayF
{
	void operator()(int a)
	{
		cout << a << " ";
	}
};

//C++仿函数模板
template<class T>
struct SortTF
{
	inline bool operator()(T const& a, T const& b) const
	{
		return a < b;
	}
};

template<class T>
struct DisplayTF
{
	inline void operator()(T const& a) const
	{
		cout << a << " ";
	}
};




int main()
{
	//c++方式
	int arr[] = { 4,23,2,6,7 };
	sort(arr, arr + 5, MySort);
	for_each(arr, arr + 5, Display);
	cout << endl;

	//C++泛型
	int arr2[] = { 4,23,2,6,7 };
	sort(arr2, arr2 + 5, MySortT<int>);
	for_each(arr2, arr2 + 5, DisplayT<int>);
	cout << endl;

	//C++仿函数
	int arr3[] = { 4,23,2,6,7 };
	sort(arr3, arr3 + 5,SortF());
	for_each(arr3, arr3 + 5, DisplayF());
	cout << endl;
	
	//C++仿函数模板
	int arr4[] = { 4,23,2,6,7 };
	sort(arr4, arr4 + 5, SortTF<int>());
	for_each(arr4, arr4 + 5, DisplayTF<int>());
	cout << endl;
	return 0;
}




