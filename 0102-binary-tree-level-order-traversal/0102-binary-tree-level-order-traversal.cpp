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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode *>q;
        if (root ==NULL)
        {
            return v;
        }
        q.push (root);

        while(!q.empty())
        {
            vector<int> ans;

            int w= q.size();
            for(int i=0;i<w;i++)
            {
                TreeNode * curr= q.front();
                ans.push_back(curr->val);
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);

                }
                q.pop();
            }

            v.push_back(ans);
        }
        return v;
        
    }
};