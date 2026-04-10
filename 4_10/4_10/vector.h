#include<iostream>
#include<assert.h>
using namespace std;

namespace bit

{

    template<class T>

    class vector

    {

    public:

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



            // construct and destroy

            vector()
            {}
            //vector()=default;
            //c++11前置生成默认构造

            vector(int n, const T& val = T())
            {
                reserve(n);
                for (int i = 0; i < n; i++)
                {
                    push_back(val);
                }
            }

            template<class InputIterator>

            vector(InputIterator first, InputIterator last)
            {
                for (; first < last; first++)
                {
                    push_back(*first);
                }
            }

            vector(const vector<T>& v)
            {
                _start = v._start;
                _finish = v._finish;
                _endOfStorage = v._endOfStorage;
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
                    delete _start;
                    _start = _finish = _endOfStorage = nullptr;
                }

            }

            // capacity

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endOfStorage - _start;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t old_size = size();
                T* tmp = new T[n];
                //memcpy(tmp,_start,old_size*sizeof(T));
                //memcpy是浅拷贝
                for (size_t i = 0; i < old_size; i++)
                {
                    tmp[i] = _start[i];
                }
                delete _start;
                _finish = tmp + old_size;
                _endOfStorage = tmp + n;
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
                while (_finish < _start + n)
                {
                    *_finish = val;
                    _finish++;
                }
            }
        }
        bool empty()const
        {
            return _start==_finish;
        }


            ///////////////access///////////////////////////////

        T& operator[](size_t pos)
        {
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            return _start[pos];
        }



            ///////////////modify/////////////////////////////

        void push_back(const T& x)
        {
            if (_finish == _endOfStorage)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = x;
            _finish++;
        }

        void pop_back()
        {
            assert(!empty());
            _finish--;
        }

            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_endOfStorage, v._endOfStorage);
            }

            iterator insert(iterator pos, const T& x)
            {
                assert(pos >= _start);
                assert(pos <= _finish);
                if (_finish == _endOfStorage)
                {

                    reserve(capacity() == 0 ? 4 : capacity() * 2);

                }
                while (end > pos)
                {
                    *(end) = *(end-1);
                    --end;
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

        iterator _finish; // 指向有效数据的尾

        iterator _endOfStorage; // 指向存储容量的尾

    };

}