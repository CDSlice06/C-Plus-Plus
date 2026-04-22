#include"BinaryResearch.h"
int main()
{
	BSTree<int> t;

	t.Insert(5);
	t.Insert(3);
	t.Insert(7);
	t.Insert(2);
	t.Insert(4);
	t.Insert(6);
	t.Insert(8);

	cout << "中序遍历(升序): ";
	t.InOrder();

	t.Erase(5);
	cout << "删除根节点5后: ";
	t.InOrder();

	t.Erase(3);
	cout << "删除3后: ";
	t.InOrder();
}