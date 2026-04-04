#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

//写之前先声明,模版类的生命和定义通常不能分离,必须写在同一个.h文件里

namespace CD
{

    template<class T>
    class vector
    {

    public:

        // construct and destroy

    /*    vector()
        {

        }*/
        //C++11前置生成默认构造,上面的功能和这个完全等价(目前)
        vector() = default;

        //带参构造
        vector(int n, const T& val = T())
        {
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                push_back(val);
            }
        }
        //类模板的成员函数,还可以继续是函数模版
        //这句话的意思是:一个类本身是模板 → 这个类里的成员函数，还可以再套一层模板
        template<class InputIterator>
       //last是有效元素的下一个位置
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }
        //拷贝构造
        vector(const vector<T>& v)
        {
            reserve(v.size());
            for (auto& ch : v)
            {
                push_back(ch);
            }
        }
        //赋值重载
        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endofStorage = v._endofStorage);
        }
        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            if (_start)
            {
                delete[]_start;
                _start = _finish = _endofStorage = nullptr;
            }
        }

        void clear()
        {
            _finish = _start;
        }
            // Vector的迭代器是一个原生指针

        typedef T* iterator;

            typedef const T* const_iterator;
       

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator cbegin()const
        {
            return _start;
        }

        const_iterator cend() const
        {
            return _finish;
        }


            // capacity

        bool empty()const
        {
            return size() == 0;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            _endofStorage - _start;
        }

        void reserve(size_t n)
        {
            //vs只支持扩容不支持缩容,因此这里不写缩容
            if (n > capacity())
            {
                //为什么这里要用一个olde_size来存当前的size()
                //因为在new处新空间,把_start指向新空间的那一刻,size()函数的结果就变了
                //如果不提前存old_size,后面的代码就全错了
                //size_t size()const
                //{
                    //return _finish - _start;
                //}
                //指针的减法必须指向同一块内存空间才能进行运算
                //当我们开辟了一个新空间,此时已经不指向同一块空间了,而我们又把tmp赋值给了_start
                //此时的size()已经完全是错的了,不能用size(),因此只能提前先存下来
                size_t old_size = size();
                T* tmp = new T[n];
                //memcpy的拷贝只是浅拷贝,一个字节一个字节的拷贝,这里就会存在问题
                //memcpy(tmp, _start, old_size * sizof(T));
                //必须要深拷贝
                for (size_t i = 0; i < old_size; i++)
                {
                    tmp[i] = _start[i];
                }
                delete[]_start;
                _start = tmp;
                _finish = tmp + old_size;
                _endofStorage = tmp + n;
            }
        }

        void resize(size_t n, const T& val = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                {
                    while (_finish < _start + n)
                    {
                        *_finish = val;
                        _finish++;
                    }
                }

            }
        }



            ///////////////access///////////////////////////////

        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            assert(pos < size());
            return _start[pos];
        }



            ///////////////modify/////////////////////////////

        //这里需要考虑的迭代器失效问题最多

        void push_back(const T& x)
        {
            if (_finish == _endofStorage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            ++_finish;
        }
        void pop_back()
        {
            assert(!empty());
            _finish--;
        }

        iterator insert(iterator pos, const T& x)
        {
            assert(pos >= _start);
            assert(pos <= _finish);
            if (_finish == _endofStorage)
            {
                //这里必须事先将len(相对偏移量)的的值给保存下来
                //因为我们不知道具体是否会扩容,一旦扩容,那_start将指向新的空间
                //pos就失效了,因为它指向的是旧空间,而空间已经释放了
                //这个时候pos就是个野指针,再使用就会崩溃
                size_t len = pos - _start;
                reserve(capacity() == 0 ? 4 : capacity() * 2);
                pos = _start + len;
            }
            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos < _finish);
            iterator it = pos + 1;
            while (it != end())
            {
                *(it - 1) = *it;
                ++it;
            }
            --_finish;
            return pos;
        }

    private:

        iterator _start; // 指向数据块的开始

        iterator _finish; // 指向有效数据的结尾的下一个位置

        iterator _endofStorage; // 指向存储容量的尾

    };

}