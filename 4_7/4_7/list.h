#include<iostream>
#include<assert.h>
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
            , _next(nullptr)
            , _data(data)
        {
        }
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T> Node;
        typedef ListIterator<T, Ref, Ptr> Self;
        Node* _node;
        ListIterator(Node* node = nullptr)
            :_node(node)
        {}
        //容器迭代器的拷贝构造
        ListIterator(const Self& l)
            :_node(l._node)

        {
        }
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
            _node = _node->pre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return _node != l._node;
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
            std::swap(_head, l._head);
            std::swap(_size, l._size);
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
        const_iterator begin()const
        {
            return _head->_next;
        }
        const_iterator end()const
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
            return _head->_next->_data;
        }
        const T& front()const
        {
            return _head->_next->_data;
        }
        T& back()
        {
            return _head->_pre->_data;
        }
        const T& back()const
        {
            return _head->_pre->_data;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val)
        {
            insert(end(), val);
        }
        void pop_back()
        {
            erase(--end());
        }
        void push_front(const T& val)
        {
            insert(begin(), val);
        }
        void pop_front()
        {
            erase(begin());
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* cur = pos._node;
            Node* pre = cur->_pre;
            Node* newnode = new Node(val);
            newnode->_next = cur;
            cur->_pre = newnode;
            newnode->_pre = pre;
            pre->_next = newnode;
            ++_size;
            return newnode;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos != end());
            Node* next = pos._node->_next;
            Node* pre = pos._node->_pre;
            next->_pre = pre;
            pre->_next = next;
            delete pos._node;
            --_size;
            return next;
        }
    private:
        void empty_init()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_pre = _head;
            _size = 0;
        }
        Node* _head;
        size_t _size;
    };


    template <class Container>//这里的Container这个占位参数,我们希望传进来的都是容器
    void print_container(const Container& con)
    {
        //这里的::不是在Container这个模版参数里面的const_iterator,而是指我们传进来的容器里
        //必须已经写好了const_iteraotr,调用这个容器自己的常量迭代器
        typename Container::const_iterator it = con.begin();
        //typename auto it1=con.begin() 这样写是错的
        //auto：自动推导类型（编译器自己猜）
        //typename：告诉编译器这是个类型（你强行指定）
        //因此只能这么写
        //auto it=con.begin(),这样就少写很多了
        while (it != con.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
        for (auto e : con)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    
}


