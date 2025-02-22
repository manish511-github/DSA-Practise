/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

TreeNode * helper(TreeNode * root,TreeNode * p, TreeNode * q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val== p->val || root->val == q->val)
    {
        return root;

    }
    TreeNode * lh = helper(root->left,p,q);
    TreeNode * rh = helper(root->right,p,q);
    if (lh!=NULL && rh!= NULL)
    {
        return root;
    }
    if (lh !=NULL && rh == NULL)
    {
        return lh;
    }
    if (rh != NULL && lh == NULL)
    {
        return rh;
    }
    return NULL;

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return helper(root,p,q);
        
    }
};