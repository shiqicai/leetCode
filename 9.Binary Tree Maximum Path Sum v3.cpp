/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 看题目不仔细,第一次以为只能从根节点出发,第二次以为只能是从上到下的一个路径,第三次才发现可以是子树
 finished:23:31
 */
class Solution {
    
public:
    int findSum(TreeNode *r,int& max){
    	int le,ri;
        int value;
        int leriMax,tmpMax;
        if(r->left==NULL && r->right==NULL) {
            value=r->val;
            if(value>max) max=value;
            if(value>0)
    		    return value;
            else
                return 0;
        }
        if(r->left==NULL){
            ri=findSum(r->right,max);
            if(ri>=0)
                value=ri+r->val;
            else
                value=r->val;
            if(value>max) max=value;
                return value;
        }
        if(r->right==NULL){
            le=findSum(r->left,max);
            if(le>=0)
                value=le+r->val;
            else
                value=r->val;
            if(value>max) max=value;
                return value;
        }
        le=findSum(r->left,max);
		ri=findSum(r->right,max);
        
        if(le>0 && ri>0)
            tmpMax=le+ri+r->val;
        else if(le>0)
            tmpMax=le+r->val;
        else if(ri>0)
            tmpMax=ri+r->val;
        else
            tmpMax=r->val;            
        if(tmpMax>max) max=tmpMax;
        
        leriMax=le>ri?le:ri;
        if(leriMax+r->val>0)
            return leriMax+r->val;
        else{
            if(r->val>0)
                return r->val;
            else
                return 0;
        }
	}
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max=INT_MIN;
        findSum(root,max);
        return max;        
    }
};
