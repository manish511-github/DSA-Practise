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
void helper(TreeNode * root,int &val,int &ans,int k)
{
    if (root==NULL)
    {
        return;
    }
    helper(root->left,val,ans,k);
    val++;

    if (val==k)
    {
        ans = root->val;

    }
    helper(root->right,val,ans,k);
}
    int kthSmallest(TreeNode* root, int k) {
        int val=0;
        int ans = -1;
        helper(root,val,ans,k);
        return ans;
        
    }
};