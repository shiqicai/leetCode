/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 看题目不仔细,第一次以为只能从根节点出发,第二次以为只能是从上到下的一个路径,第三次才发现可以是子树
 */
class Solution {
    
public:
    int findSum(TreeNode *r,int cur,int max){
    	int le,ri;
        int value;
        value=cur+r->val;
        if(value>max) max=value;
        if(value<0) value=0;
		if(r->left==NULL && r->right==NULL) 
			return max; 
		else if(r->left==NULL)
			return findSum(r->right,value,max);
		else if(r->right==NULL)
			return findSum(r->left,value,max);
		else{
			le=findSum(r->left,value,max);
			ri=findSum(r->right,value,max);
			return le>ri?le:ri;
		}
	}
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //int max=INT_MIN;
        //findSum(root,0,max);
        //return max;
        return findSum(root,0,INT_MIN);
    }
};
