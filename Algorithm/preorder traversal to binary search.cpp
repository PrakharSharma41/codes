
// a preorder traversed array is given an construct a binary search tree from it
// week 3 leetcode see from errichto's video

#include<iostream>
using namespace std;

struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL);
};

class Solution{
	private:
		TreeNode* helper(const vector<int> &preorder,int &id,int limit){
			if(id==(int)preorder.size()||preorder[id]>limit)
			return NULL;
			int root_value=preorder[id];
			TreeNode* root=new TreeNode(root_value);
			id++;
			root->right=helper(preorder,id,limit);
			root->left=helper(preorder,id,root_value);
			return root;
		}
	public:
		TreeNode* bstfromPreorder(vector<int>& preorder){
			int id=0;
			return helper(preorder,id,INT_MAX);
		}
};
