#include <iostream>
using namespace std;

// 模板二叉搜索树 节点
template<class T>
struct BSTNode
{
    T _key;               // 存储关键字
    BSTNode<T>* _left;    // 左孩子
    BSTNode<T>* _right;   // 右孩子

    // 构造函数
    BSTNode(const T& key)
        : _key(key)
        , _left(nullptr)
        , _right(nullptr)
    {
    }
};

// 模板 二叉搜索树类
template<class T>
class BSTree
{
    // 类型重定义，简化代码
    typedef BSTNode<T> Node;

private:
    Node* _root;  // 根节点

    // 中序遍历 子函数（递归）
    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;

        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }

public:
    // 构造
    BSTree()
        : _root(nullptr)
    {
    }

    // 1. 插入数据
    bool Insert(const T& key)
    {
        // 1. 空树：直接新建根节点
        if (_root == nullptr)
        {
            _root = new Node(key);
            return true;
        }

        Node* cur = _root;
        Node* parent = nullptr;

        // 2. 寻找合适插入位置
        while (cur != nullptr)
        {
            // 待插入值更小，往左走
            if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_left;
            }
            // 待插入值更大，往右走
            else if (key > cur->_key)
            {
                parent = cur;
                cur = cur->_right;
            }
            // 存在重复值，set/map规则：不允许插入
            else
            {
                return false;
            }
        }

        // 3. 新建节点，挂载到父节点
        cur = new Node(key);
        if (key < parent->_key)
            parent->_left = cur;
        else
            parent->_right = cur;

        return true;
    }

    // 2. 查找数据
    Node* Find(const T& key)
    {
        Node* cur = _root;
        while (cur != nullptr)
        {
            if (key < cur->_key)
                cur = cur->_left;
            else if (key > cur->_key)
                cur = cur->_right;
            else
                return cur; // 找到目标节点
        }
        return nullptr; // 遍历到空，查找失败
    }

    // 3. 删除数据
    bool Erase(const T& key)
    {
        Node* cur = _root;
        Node* parent = nullptr;

        // 1. 先找到要删除的节点
        while (cur != nullptr)
        {
            if (key < cur->_key)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (key > cur->_key)
            {
                parent = cur;
                cur = cur->_right;
            }
            // 找到需要删除的节点 cur
            else
            {
                // 情况1：左子树为空
                if (cur->_left == nullptr)
                {
                    // 判断是否为根节点
                    if (cur == _root)
                        _root = cur->_right;
                    else if (parent->_left == cur)
                        parent->_left = cur->_right;
                    else
                        parent->_right = cur->_right;

                    delete cur;
                }
                // 情况2：右子树为空
                else if (cur->_right == nullptr)
                {
                    if (cur == _root)
                        _root = cur->_left;
                    else if (parent->_left == cur)
                        parent->_left = cur->_left;
                    else
                        parent->_right = cur->_left;

                    delete cur;
                }
                // 情况3：左右子树都不为空（最难）
                else
                {
                    // 找右子树最左节点 -> 中序后继
                    Node* minParent = cur;
                    Node* minRight = cur->_right;
                    while (minRight->_left != nullptr)
                    {
                        minParent = minRight;
                        minRight = minRight->_left;
                    }

                    // 覆盖替换要删除节点的值
                    cur->_key = minRight->_key;

                    // 删掉后继节点
                    if (minParent->_left == minRight)
                        minParent->_left = minRight->_right;
                    else
                        minParent->_right = minRight->_right;

                    delete minRight;
                }
                return true;
            }
        }
        // 没找到该值，删除失败
        return false;
    }

    // 对外提供中序遍历接口
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }
};

// 测试代码
int main()
{
    BSTree<int> bst;
    int arr[] = { 5, 3, 8, 1, 4, 7, 9 };

    // 批量插入
    for (auto& x : arr)
    {
        bst.Insert(x);
    }

    cout << "中序遍历：";
    bst.InOrder();

    // 测试删除
    bst.Erase(5);
    cout << "删除5后：";
    bst.InOrder();

    return 0;
}