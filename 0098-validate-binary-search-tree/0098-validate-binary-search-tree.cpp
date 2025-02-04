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
bool helper(TreeNode * root, long mini ,long maxi)
{
    if (root==NULL){
        return true;
    }

        if (root->val <= mini || root->val >=maxi)
    {
        return false;
    }
    bool left = helper(root->left,mini,root->val);

    bool right = helper(root->right,root->val,maxi);
    return left && right;

}
    bool isValidBST(TreeNode* root) {
   // for valid bst left < root< right
   return helper(root,LONG_MIN,LONG_MAX);

        
    }
};