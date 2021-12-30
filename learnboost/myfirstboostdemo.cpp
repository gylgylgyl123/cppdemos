
#include <iostream>
#include <boost/lexical_cast.hpp>
using namespace std;
using boost::lexical_cast;

int main()
{
    int i = lexical_cast<int>("123");
    cout << i << endl;

    string s = lexical_cast<string>(12.4);
    cout << s << endl;

    //但是有的情况不一定会成功,下面情况就会出错
    int ii;
    ii = lexical_cast<int>("abcd");
    cout << ii << endl;


    return 0;
}

