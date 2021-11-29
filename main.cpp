
//测试Map代码
#include <iostream>
#include "sset.h"
#include "mmap.h"
#include "RBTree.h"
using namespace std;
int main()
{

    MakeMap<int,string> dict;
    dict.Insert(make_pair(1,"gao"));
    dict.Insert(make_pair(3,"yu"));
    dict.Insert(make_pair(2,"li"));

    MakeMap<int,string>::Iterator it = dict.Begin();
    while(it != dict.End())
    {
        cout << it->second << " ";
        ++it;
    }

    //测试Set代码
    mySet<int> T;

    T.Insert(1);
    T.Insert(5);
    T.Insert(2);
    T.Insert(4);
    T.Insert(3);
    mySet<int>::Iterator  it1 = T.Begin();
    while(it1 != T.End())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;//1 2 3 4 5
    return 0;
}


/*
//测试Set代码
#include <iostream>
#include "mmap.h"
#include "sset.h"
using namespace std;
int main()
{
    mySet<int> T;

    T.Insert(1);
    T.Insert(5);
    T.Insert(2);
    T.Insert(4);
    T.Insert(3);
    mySet<int>::Iterator  it = T.Begin();
    while(it != T.End())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;//1 2 3 4 5
    return 0;
}
 */