#include<iostream>
using namespace std;


namespace CD
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode<T>* _pre;
        ListNode<T>* _next;
        T _data;

        ListNode(const T& data = T())
            :_pre(nullptr)
            ,_next(nullptr)
            ,_data(data);
        {}
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* Node;
        typedef ListIterator<T, Ref, Ptr> Self;
        Node* _node;
        ListIterator(Node* node = nullptr)
            :_node(node)
        { }
        //容器迭代器的拷贝构造
        ListIterator(const Self& l)
            :_pre(l._pre)
            ,_next(l._next)
            ,_data(l._data)
        { }
        Ref operator*()
        {
            //this->_node->_data;
            return _node->_data;//注意
        }
        Ptr operator->()
        {
            return &_node->_data;//注意
        }
        Self& operator++()
        {
            _node = _node->_next;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp(*this);//注意
            _node = _node->_next;
            return tmp;
        }
        Self& operator--()
        {
            _node = _node->_pre;
            return *this;
        }
        Self operator--(int)
        {
            Self tmp(*this);
            _node = _node->next;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return _node->_data != l._node
        }
        bool operator==(const Self& l)
        {
            return _node == l._node;
        }
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
    public:
        typedef ListIterator<T, T&, T*> iterator;//注意
        typedef ListIterator<T, const T&, const T*> const_iterator;//注意
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            empty_init();
        }
        list(int n, const T& value = T())
        {
            empty_init();
            for (int i = 0; i < n; i++)
            {
                push_back(value);
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            empty_init();
            for (; first != last; first++)
            {
                push_back(*first);
            }
        }
        list(const list<T>& l)
        {
            empty_init();
            for (auto& e : l)//注意理解
            {
                push_back(e);
            }
        }
        void swap(list<T>& l)
        {
            std::swap()
        }
        list<T>& operator=(const list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }
        void clear()
        {
            auto it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }

        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _head->_next;//都发生了隐式类型转换,前提是你有单参数构造函数
        }//只有单参数构造函数可以发生隐式类型转换
        iterator end()
        {
            return _head;//同上
        }
        const_iterator begin()
        {
            return _head->_next;
        }
        const_iterator end()
        {
            return _head;
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return 
        }
        const T& front()const;
        T& back();
        const T& back()const;


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val);
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos);
        void clear();
        void swap(list<T>& l);
    private:
        void empty_init()
        {
            _head = new Node;
            _head->_next = _head;
            _head->pre = _head;
            _size = 0;
        }
        Node* _head;
        size_t _size;
    };
};