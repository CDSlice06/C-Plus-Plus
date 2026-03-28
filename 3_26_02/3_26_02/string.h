#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
namespace CD
{
   
    class string
        
    {
    public:
        friend ostream& operator<<(ostream& out, const string& s);
        typedef char* iterator;

    public:

        string(const char* str = "")
            :_size(strlen(str))
            ,_capacity(_size)
            ,_str(new char[_capacity+1])
        {
            //这里用初始化列表,质量更高
            //_size = strlen(str);
            //_capacity不包括\0
            //_capacity = _size;
            //_str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        

        string(const string& s)
            :_size(s._size)
            , _capacity(s._capacity)
            ,_str(new char[_capacity+1])
        {
            //这里也可以用初始化列表写.质量更高
         /*   _capacity = s._capacity;
            _size = s._size;
            _str = new char[_capacity + 1];
            */
            
            strcpy(_str, s._str);
        }

        string& operator=(const string& s)
        {
            if (this != &s)
            {
                delete[]_str;
                _capacity = s._capacity;
                _size = s._size;
                _str = new char[_capacity + 1];
                strcpy(_str, s._str);
            }
            return *this;
        }

        ~string()
        {
            delete[]_str;
            _str = NULL;
            _capacity = _size = 0;
        }



        //////////////////////////////////////////////////////////////

        // iterator

        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }



        /////////////////////////////////////////////////////////////

        // modify

        void push_back(char c);

        string& operator+=(char c);

        void append(const char* str);

        string& operator+=(const char* str);

        void clear();

        void swap(string& s);

        const char* c_str()const;



        /////////////////////////////////////////////////////////////

        // capacity

        size_t size()const;

        size_t capacity()const;

        bool empty()const;

        void resize(size_t n, char c = '\0');

        void reserve(size_t n);



        /////////////////////////////////////////////////////////////

        // access

        char& operator[](size_t index);

        const char& operator[](size_t index)const;



        /////////////////////////////////////////////////////////////



        // 返回c在string中第一次出现的位置

        size_t find(char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const;

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c);

        string& insert(size_t pos, const char* str);



        // 删除pos位置上的元素，并返回该元素的下一个位置

        string& erase(size_t pos, size_t len);
        static const size_t npos;
        string substr(size_t pos, size_t len);
    private:

        size_t _size;

        size_t _capacity;

        char* _str;

    };
   
  
    void swap(string& a, string& b);
    //relational operators

    bool operator<(const string& s1, const string& s2);

    bool operator<=(const string& s1, const string& s2);

    bool operator>(const string& s1, const string& s2);

    bool operator>=(const string& s1, const string& s2);

    bool operator==(const string& s1, const string& s2);

    bool operator!=(const string& s1, const string& s2);

    ostream& operator<<(ostream& out, const string& s);

    istream& operator>>(istream& in, string& s);
}
