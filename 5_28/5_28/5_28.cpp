#include<iostream>
using namespace std;
// 红黑树插入函数：插入键值对kv，成功返回true，失败返回false
bool Insert(const pair<K, V>& kv)
{
    // 1. 如果树是空的，直接创建根节点
    if (_root == nullptr)
    {
        // 新建节点，根节点必须是黑色
        _root = new Node(kv);
        _root->_col = BLACK;
        return true;
    }

    // 2. 非空树：先按二叉搜索树规则找到插入位置
    Node* parent = nullptr; // 记录父节点
    Node* cur = _root;      // 遍历指针，从根开始

    while (cur)
    {
        if (cur->_kv.first < kv.first)
        {
            // 要插入的值比当前节点大，往右子树走
            parent = cur;
            cur = cur->_right;
        }
        else if (cur->_kv.first > kv.first)
        {
            // 要插入的值比当前节点小，往左子树走
            parent = cur;
            cur = cur->_left;
        }
        else
        {
            // 键值重复，插入失败
            return false;
        }
    }
    // 3. 创建新节点，并挂到父节点下
    cur = new Node(kv);
    // 新节点默认设为红色（红黑树插入的通用规则，避免破坏黑高）
    cur->_col = RED;

    // 判断新节点是父节点的左孩子还是右孩子
    if (parent->_kv.first < kv.first)
    {
        parent->_right = cur;
    }
    else
    {
        parent->_left = cur;
    }
    // 设置新节点的父指针
    cur->_parent = parent;
    // 4. 插入后调整红黑树规则，循环向上处理，直到父节点为黑色（无冲突）
    while (parent && parent->_col == RED)
    {
        // 父节点是红色，说明一定存在祖父节点（根节点是黑色）
        Node* grandfather = parent->_parent;

        // 情况分支1：父节点是祖父节点的左孩子
        if (parent == grandfather->_left)
        {
            // 找到叔叔节点（父节点的兄弟节点，即祖父的右孩子）
            Node* uncle = grandfather->_right;

            // -------------------- 情况1：叔叔节点存在且为红色（仅变色） --------------------
            if (uncle && uncle->_col == RED)
            {
                // 父节点变黑，叔叔节点变黑，祖父节点变红
                parent->_col = uncle->_col = BLACK;
                grandfather->_col = RED;

                // 把祖父节点当成新的冲突节点，向上继续调整
                cur = grandfather;
                parent = cur->_parent;
            }
            else
            {
                // -------------------- 情况2：叔叔节点为黑/不存在，且cur和parent同侧（单旋+变色） --------------------
                if (cur == parent->_left)
                {
                    // 对祖父节点做右单旋
                    RotateRight(grandfather);
                    // 父节点变黑，祖父节点变红
                    parent->_col = BLACK;
                    grandfather->_col = RED;
                }
                // -------------------- 情况3：叔叔节点为黑/不存在，且cur和parent异侧（双旋+变色） --------------------
                else
                {
                    // 第一步：对父节点做左单旋，把结构掰直
                    RotateLeft(parent);
                    // 第二步：对祖父节点做右单旋
                    RotateRight(grandfather);
                    // 新节点cur变黑，祖父节点变红
                    cur->_col = BLACK;
                    grandfather->_col = RED;
                }
                // 情况2/3调整完成后，不会再向上产生冲突，直接break结束循环
                break;
            }
        }
        // 情况分支2：父节点是祖父节点的右孩子（上面的镜像场景）
        else
        {
            // 找到叔叔节点（父节点的兄弟节点，即祖父的左孩子）
            Node* uncle = grandfather->_left;

            // -------------------- 情况1：叔叔节点存在且为红色（仅变色） --------------------
            if (uncle && uncle->_col == RED)
            {
                parent->_col = uncle->_col = BLACK;
                grandfather->_col = RED;

                // 向上继续调整
                cur = grandfather;
                parent = cur->_parent;
            }
            else
            {
                // -------------------- 情况2：叔叔节点为黑/不存在，且cur和parent同侧（单旋+变色） --------------------
                if (cur == parent->_right)
                {
                    // 对祖父节点做左单旋
                    RotateLeft(grandfather);
                    // 父节点变黑，祖父节点变红
                    parent->_col = BLACK;
                    grandfather->_col = RED;
                }
                // -------------------- 情况3：叔叔节点为黑/不存在，且cur和parent异侧（双旋+变色） --------------------
                else
                {
                    // 第一步：对父节点做右单旋，把结构掰直
                    RotateRight(parent);
                    // 第二步：对祖父节点做左单旋
                    RotateLeft(grandfather);
                    // 新节点cur变黑，祖父节点变红
                    cur->_col = BLACK;
                    grandfather->_col = RED;
                }
                // 情况2/3调整完成，直接break
                break;
            }
        }
    }
    // 5. 循环结束后，强制根节点为黑色（防止根节点在调整中被设为红色）
    _root->_col = BLACK;

    return true;
}
