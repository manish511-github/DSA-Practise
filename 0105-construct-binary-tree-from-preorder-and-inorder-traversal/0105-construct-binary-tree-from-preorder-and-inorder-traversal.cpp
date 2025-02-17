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

    TreeNode* helper(int l,int r,vector<int> &inorder,vector<int>& preorder,int &pre)
    {
        if (l>r)
        {
            return NULL;
        }
        TreeNode * root =new TreeNode (preorder[pre++]);
      int index;

        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]== root->val)
            {
                index =i;
                break;

            }
        }
        root->left = helper(l,index-1,inorder,preorder,pre);
        root->right= helper(index+1,r,inorder,preorder,pre);
        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= inorder.size();
        int pre=0;
    return helper(0,n-1,inorder,preorder,pre);

        
    }
};