/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *典型的二叉树遍历题目 
 */
class Solution {
public:
    void calSum(TreeNode *r,int val,int& sum){        
        val*=10;
        val+=r->val;
        if(r->left!=NULL && r->right!=NULL){            
            calSum(r->left,val,sum);
            calSum(r->right,val,sum);
            return ;
        }
        if(r->left!=NULL){
            calSum(r->left,val,sum);
            return ;
        }
        if(r->right!=NULL){
            calSum(r->right,val,sum);
            return ;
        }
        sum+=val;
        return ;
        
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum=0;
        if(root==NULL) return 0;//最bt的判例:树直接为空
        calSum(root,0,sum);
        return sum;
    }
};
