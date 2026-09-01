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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)   return -1;
        queue<TreeNode*> q;
        q.push(root);
        int size , ans ;
        TreeNode* t;
        while(!q.empty()){
            size = q.size();
            for(int i = 0 ; i < size ; i++){
                t = q.front();
                q.pop();
                if(i == 0)  ans = t->val;
                if(t->left)    q.push(t->left);
                if(t->right)    q.push(t->right);
            }
        }
        return ans;
    }
};