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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solver(root,ans);
        return ans;
    }
    pair<int,int> solver(TreeNode* root , int& ans ){
        if(!root)   return {0,0};
        auto left  = solver(root->left,ans);
        auto right = solver(root->right,ans);
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;
        if(root->val == (sum/count))    ans++;
        return {sum,count};
    }
};