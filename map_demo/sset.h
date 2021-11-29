//
// Created by 高玉立 on 2021/11/3.
//

#ifndef UNTITLED7_SSET_H
#define UNTITLED7_SSET_H
#include "RBTree.h"

template<class K>   //K == int
class mySet
{
public:
    typedef K ValueType;    //ValueType == int
    struct KeyOfKey
    {
        const ValueType& operator()(const ValueType& key)
        {
            return key;
        }
    };
    typedef typename RBTree<K,K,KeyOfKey>::Iterator  Iterator;
    //如果没有typename，编译器就会去RBTree中去寻找Iterator,但是RBTree并没有实例化，所以找不到然后报错，
    // 所以typename是告诉编译器这个类型是一个模板的类型，现在先不要确定它的类型

    pair<Iterator,bool> Insert(const K& key)
    {
        return Tree.Insert(key);
    }

    Iterator Begin()
    {
        return Tree.Begin();
    }

    Iterator End()
    {
        return Tree.End();
    }

protected:
    RBTree<K,ValueType,KeyOfKey> Tree;
};

#endif //UNTITLED7_SSET_H
