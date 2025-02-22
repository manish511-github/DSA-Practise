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
    int helper(TreeNode * root,int val,unordered_map<TreeNode*,int> & mp)
    {
        if (root ==NULL)
        {
            return 0;
        }

        //notpick
        if (mp.find(root)!=mp.end())
        {
            return mp[root];
        }
        int notpick = helper(root->left, val,mp)+ helper(root->right,val,mp);
        int pick =root-> val;
        if (root->left)
        {
            pick+=helper(root->left->left,val,mp)+helper(root->left->right,val,mp);
        }
        if (root->right)
        {
            pick+=helper(root->right->right,val,mp)+helper(root->right->left,val,mp);
        }
        return mp[root] = max(pick, notpick);
    }
    int rob(TreeNode* root) {
        int val=0;
        unordered_map< TreeNode * ,int>mp; 
        return helper(root,val,mp);

        
    }
};