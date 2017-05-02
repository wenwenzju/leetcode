#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
	TreeNode* search(TreeNode* root, int x)
	{
		if (root == nullptr || root->val == x) return root;
		if (root->val > x) return search(root->left, x);
		else return search(root->right, x);
	}
	TreeNode* minimum(TreeNode* root)
	{
		if (root == nullptr) return root;
		while (root->left) root = root->left;
		return root;
	}
	TreeNode* maximum(TreeNode* root)
	{
		if (root == nullptr) return root;
		while (root->right) root = root->right;
		return root;
	}
	TreeNode* insertNode(TreeNode* root, int x)
	{
		TreeNode* pre = nullptr;
		TreeNode* r = root;
		while(r)
		{
			pre = r;
			if (r->val > x) r = r->left;
			else r = r->right;
		}
		if (pre == nullptr) return new TreeNode(x);
		if (x < pre->val) pre->left = new TreeNode(x);
		else pre->right = new TreeNode(x);
		return root;
	}
	TreeNode* deleteNode(TreeNode* root, int x)
	{
		if (root == nullptr) return root;
		if (x<root->val) root->left = deleteNode(root->left, x);
		else if (x>root->val) root->right = deleteNode(root->right, x);
		else
		{
			if (root->left == nullptr)
			{
				TreeNode* right = root->right;
				delete root;
				return right;
			}
			else if (root->right == nullptr)
			{
				TreeNode* left = root->left;
				delete root;
				return left;
			}
			TreeNode* minNode = minimum(root->right);
			root->val = minNode->val;
			root->right = deleteNode(root->right, minNode->val);
		}
		return root;
	}
	TreeNode* build(vector<int>& data)
	{
		TreeNode* root = nullptr;
		for (int i = 0; i < data.size(); ++i)
		{
			root = insertNode(root, data[i]);
		}
		return root;
	}
	void free(TreeNode* root)
	{
		if (root == nullptr) return;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		delete root;
		free(left);
		free(right);
	}
};

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	BinarySearchTree t;
	TreeNode* tree = t.build(v);
}