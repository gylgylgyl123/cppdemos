//
// Created by 高玉立 on 2021/11/1.
//

#ifndef UNTITLED7_MMAP_H
#define UNTITLED7_MMAP_H
#include "RBTree.h"
template<class K,class V>
class MakeMap
{
public:
    typedef pair<K,V> ValueType;//K==int,V==string,ValueType==pair<int,string>

    struct KeyOfValue
    {
        const K& operator()(const ValueType&kv)
        {
            return kv.first;
        }
    };

    typedef typename RBTree<K,ValueType,KeyOfValue>::Iterator Iterator;

    pair<Iterator, bool> Insert(const ValueType& v)
    {
        return _Tree.Insert(v);
    }

    V& operator[](const K& key)
    {
        pair<Iterator,bool> ret = _Tree.Insert(make_pair(key, V()));
        //模板参数的V() 缺省值.
        return ret.first;
    }
    Iterator Begin()
    {
        return _Tree.Begin();
    }

    Iterator End()
    {
        return _Tree.End();
    }
private:
    RBTree<K, ValueType, KeyOfValue> _Tree;
};


#endif //UNTITLED7_MMAP_H
