#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BSTNode
{
	T _key;
	BSTNode<T>* _left;
	BSTNode<T>* _right;

	BSTNode(const T& key)
		:_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{
	}
};
 template<class T>
 class BSTree
 {
	 using Node = BSTNode<T>;
 public:
	 //强制生成默认构造,这样才能生成空树
	 BSTree() = default;
	 //赋值重载
	 BSTree& operator=(BSTree tmp)
	 {
		 swap(_root, tmp._root);
		 return *this;
	 }
	 //拷贝构造
	 BSTree(const BSTree& t)
	 {
		 _root = Copy(t._root);
	 }
	 ~BSTree()
	 {
		 Destroy(_root);
		 _root = nullptr;
	 }
	 bool Insert(const T& key)
	 {
		 if (_root == nullptr)
		 {
			 _root = new Node(key);
			 return true;
		 }
		 Node* parent = nullptr;//拿来记录当前所在的节点
		 Node* cur = _root;//拿来遍历树
		 while (cur)
		 {
			 if (cur->_key < key)
			 {
				 parent = cur;
				 cur = cur->_right;
			 }
			 else if (cur->_key > key)
			 {
				 parent = cur;
				 cur = cur->_left;
			 }
			 else
			 {
				 return false;//有重复值
			 }
		 }
		 cur = new Node(key);
		 if (parent->_key < key)
			 parent->_right = cur;
		 else
			 parent->_left = cur;
		 return true;
	 }
	 bool Find(const T& key)
	 {
		 Node* cur = _root;
		 while (cur)
		 {
			 if (cur->_key < key)
				 cur = cur->_right;
			 else if (cur->_key > key)
				 cur = cur->_left;
			 else return true;
		 }
		 return false;
	 }

	 //1.只有左孩子
	 //2.只有右孩子
	 //3.两个孩子
	 //4.无孩子的情况最简单,直接删即可
	 bool Erase(const T& key)
	 {
		 Node* parent = nullptr;//
		 Node* cur = _root;
		 //这个是先找到要删除的节点,当然这里直接用Find也行,但只不过要改
		 while (cur)
		 {
			 if (cur->_key > key)
			 {
				 parent = cur;
				 cur = cur->_left;
			 }
			 else if (cur->_key < key)
			 {
				 parent = cur;
				 cur = cur->_right;
			 }
			 else {
				 //这里是找到了
				 break;
			 }
		 }
		 //没找到
		 if(cur==nullptr)
		 return false;
		 //左孩子为空
		 if (cur->_left == nullptr)
		 {
			 if (cur == _root)
			 {
				 _root = cur->_right;
			 }
			 else
			 {
				 if (parent->_left == cur)
					 parent->_left = cur->_right;
				 else
					 parent->_right = cur->_right;
			 }
			 delete cur;
		 }
		 //右孩子为空
		 else if (cur->_right == nullptr)
		 {
			 if (cur == _root)
			 {
				 _root = cur->_left;
			 }
			 else
			 {
				 if (parent->_left == cur)
					 parent->_right = cur->_left;
				 else
					 parent->_left = cur->_left;
			 }
			 delete cur;
		 }
		 //两个孩子
		 else
		 {
			 Node* replaceparent = cur;
			 Node* replace = cur->_right;
			 while (replace->_left)
			 {
				 replaceparent = replace;
				 replace = replace->_left;
			 }
			 cur->_key = replace->_key;
			 if (replaceparent->_left == replace)
				 replaceparent->_left = replace->_right;
			 else
				 replaceparent->_right = replace->_right;
			 delete replace;
		 }
		 return true;
	 }
	 void InOrder()
	 {
		 _InOrder(_root);
		 cout << endl;
	 }
 private:
	 void _InOrder(Node* root)
	 {
		 if (root == nullptr)
			 return;
		 _InOrder(root->_left);
		 cout << root->_key << " ";
		 _InOrder(root->_right);
	 }
	 void Destroy(Node* root)
	 {
		 if (root == nullptr)
			 return;
		 Destroy(root->_left);
		 Destroy(root->_right);
		 delete root;
	 }
	 Node* Copy(Node* root)
	 {
		 if (root == nullptr)
			 return nullptr;
		 Node* newnode = new Node(root->_key);
		 newnode->_left = Copy(root->_left);
		 newnode->_right = Copy(root->_right);
		 return newnode;
	 }
	

 private:
	 Node* _root = nullptr;
 };