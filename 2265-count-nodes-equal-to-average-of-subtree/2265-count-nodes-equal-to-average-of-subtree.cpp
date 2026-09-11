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
    void solver(TreeNode* root , int& ans ){
        if(!root)   return;
        solver(root->left,ans);
        solver(root->right,ans);
        long long sum = 0 ;
        if(root->left)  sum += root->left->val;
        if(root->right) sum += root->right->val;
        long long t = root->val;
        root->val += sum + 1000001;
        if(t == (root->val%1000001)/(root->val/1000001))    ans++;
        return;
    }
};