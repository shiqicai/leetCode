/**
 *
 *struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	created:2013Äê7ÔÂ2ÈÕ£¬20:49:56
	finished:59
	*/
class Solution {
public:
	int findSum(TreeNode *r,int res){
		int le,ri;
		if(r->left==NULL && r->right==NULL) 
			return res+val; 
		else if(r->left==NULL)
			return findSum(r->right,res+val);
		else if(r->right==NULL)
			return findSum(r->left,res+val);
		else{
			le=findSum(r->left,res+val);
			ri=findSum(r->right,res+val);
			return le>ri?le:ri;
		}
	}
	int maxPathSum(TreeNode *root){
		return findSum(root,0);
	}
};
