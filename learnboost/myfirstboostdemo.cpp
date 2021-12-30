
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
    /*int ii;
    ii = lexical_cast<int>("abcd");
    cout << ii << endl;
    */
    //处理办法，使用异常来处理
    int ii;
    try
    {
        ii = lexical_cast<int>("abcd"); //会报一个boost::bad_lexical_cast的异常
    }
    catch (boost::bad_lexical_cast& e)
    {
        cout << e.what() << endl;//打印这个异常对象中的信息
    }

    return 0;
}

/*
输出结果为：
123
12.4
bad lexical cast: source type value could not be interpreted as target
*/
