/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(int l , int r,vector<int>& inorder, vector<int>& postorder,int &post)
    {
        if (l>r)
        {
            return NULL;
        }
        int index;
        TreeNode * root = new TreeNode (postorder[post--]);
        for(int i=0;i<inorder.size();i++)
        {
            if (inorder[i]== root->val)
            {
                index =i;
                break;
            }
        }
        root->right= helper(index+1,r,inorder,postorder,post);
        root->left= helper(l,index-1,inorder,postorder,post);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= inorder.size();
        int post =n-1;
        return helper(0,n-1,inorder,postorder,post);
        
    }
};