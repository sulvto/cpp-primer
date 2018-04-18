#include <iostream>
#include <string>

using namespace::std;

class TreeNode {
public:

	TreeNode(): count(0), left(nullptr), right(nullptr) {}

	TreeNode(const string &v): value(v), count(0), left(nullptr), right(nullptr)	{
		// count ??
	}

	TreeNode(const TreeNode &tn): value(tn.value), count(tn.count), 
		left(tn.left), right(tn.right)  {
			// count ??
		}




	~TreeNode();

private:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode::~TreeNode() 
{
	delete left;
	delete right;
}
		

class BinStrTree {
public:
	BinStrTree(): root(nullptr) {}

	BinStrTree(TreeNode *tn): root(tn) {}

	BinStrTree(const BinStrTree &bst): root(bst.root) {}

	~BinStrTree() = default;
private:
	TreeNode *root;
};

int main () 
{
	BinStrTree bst;
}
