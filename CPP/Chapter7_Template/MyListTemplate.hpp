#ifndef    __MYLIST_HPP__
#define    __MYLIST_HPP__
#include <iostream>
#include <cstdlib>

using namespace std;

namespace listspace {

template<class ItemType>
class GenericList;

template<class ItemType>
ostream &operator<<(ostream &outs, const GenericList<ItemType> &the_list);

template<class ItemType>
class GenericList {
    public:
        GenericList(int max);
        ~GenericList();
        int length() const;
        void add(ItemType new_item);
        bool full() const;
        void erase();
        friend ostream &operator<<<>(ostream &outs, const GenericList<ItemType> &the_list);
    private:
        ItemType *_item;
        int _maxLength;
        int _curIdx;
};

}//listspace

namespace listspace {

template<class ItemType>
GenericList<ItemType>::GenericList(int max)
    : _maxLength(max), _curIdx(0) {
    _item = new ItemType[max];
}

template<class ItemType>
GenericList<ItemType>::~GenericList() {
    delete[] _item;
}

template<class ItemType>
int GenericList<ItemType>::length() const {
    return (_curIdx);
}

template<class ItemType>
void GenericList<ItemType>::add(ItemType new_item) {
    if (full()) {
        cout << "Error: adding to a full list.\n";
        exit(1);
    } else {
        _item[_curIdx] = new_item;
        _curIdx = _curIdx + 1;
    }
}

template<class ItemType>
bool GenericList<ItemType>::full() const {
    return (_curIdx == _maxLength);
}

template<class ItemType>
void GenericList<ItemType>::erase() {
    _curIdx = 0;
}

template<class ItemType>
ostream &operator<<(ostream &outs, const GenericList<ItemType> &the_list) {
    for (int i = 0; i < the_list._curIdx; i++)
        outs << the_list._item[i] << endl;
    return outs;
}

}

#endif