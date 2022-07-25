#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

using namespace std;

template <typename T>
class container
{
public:
    void add(T element)
    {
        lock_guard<recursive_mutex> lock(_mtx);
        _elements.push_back(element);
    }

    void addrange(int num, ...)
    {
        va_list arguments;
        va_start(arguments, num);
        for (int i = 0; i < num; i++)
        {
            lock_guard<recursive_mutex> lock(_mtx);
            add(va_arg(arguments, T));
        }
        va_end(arguments);
    }

    void dump()
    {
        lock_guard<recursive_mutex> lock(_mtx);
        for (auto e : _elements)
            cout << e << endl;
    }

private:
    recursive_mutex _mtx;
    vector<T> _elements;
};

void func(container<int> &cont)
{
    cont.addrange(3, rand(), rand(), rand());
}

int main()
{
    srand((unsigned int)time(0));
    container<int> cont;
    thread t1(func, ref(cont));
    thread t2(func, ref(cont));
    thread t3(func, ref(cont));
    t1.join();
    t2.join();
    t3.join();
    cont.dump();
    return 0;
}