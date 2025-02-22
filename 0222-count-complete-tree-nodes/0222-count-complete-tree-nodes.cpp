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
int helper1(TreeNode * root)
{
    int depth =0;
    while(root)
    {
        depth++;
        root=root->left;
    }
    return depth;
}
int helper2(TreeNode * root)
{
    int depth =0;
   while(root)
   {
    depth++;
    root=root->right;
   } 
   return depth;
}
    int countNodes(TreeNode* root) {
        if (root== NULL)
        {
            return 0;
        }
        int lh = helper1(root);
        int rh= helper2(root );
        if (lh == rh)
        {
            return ((1<<lh)-1);
        }
        return 1+countNodes(root->left)+countNodes(root->right);

     //Time Complexity    (O(logn^2))
    }
};