#include<iostream>
using namespace std;
template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0)
	{
	}

	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;   // 节点的平衡因子
};


// AVL: 二叉搜索树 + 平衡因子的限制
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _pRoot(nullptr)
	{
	}

	// 在AVL树中插入值为data的节点
	bool Insert(const T& data)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur_ > _data < data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(data);
		if (parent->_data > data)
		{
			parent->_left = data;
		}
		else if (parent->_data < data)
		{
			parent->_right = data;
		}
		else
		{
			return false;
		}
		cur->_parent = parent;


		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++
			
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				break;
			}

		}
		return true;
	}

	// AVL树的验证
	bool IsAVLTree()
	{
		return _IsAVLTree(_root);
	}

private:
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot);
	size_t _Height(Node* pRoot);
	// 右单旋
	void RotateR(Node* pParent);
	// 左单旋
	void RotateL(Node* pParent);
	// 右左双旋
	void RotateRL(Node* pParent);
	// 左右双旋
	void RotateLR(Node* pParent);

private:
	Node* _root;
};