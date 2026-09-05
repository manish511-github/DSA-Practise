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
vector<int> v;
    int helper(TreeNode* root) {
        if (root==NULL){
            return 0;
        }
        int left = helper(root->left); 
        int right = helper(root->right);
        if (left==-1 || right ==-1 ||left!=right){
            return -1;
        }
        int size = (1<<(left+1))-1;
        v.push_back(size);
        return left+1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        helper(root);
        sort(v.begin(),v.end(),greater<int>());
        if (v.size()<k){
            return -1;
        }
        // number_of_nodes_in_subtree = 2^(height_of_subtree) - 1
        return v[k-1];
    }
}; 