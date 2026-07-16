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
class BSTIterator {
public:
    vector<TreeNode*> A;
    int i = 0 , n ;
    BSTIterator(TreeNode* root) {
        inorder(root);
        n = A.size();
    }
     
    void inorder(TreeNode* root) {
        if(root->left) inorder(root->left);
        A.push_back(root);
        if(root->right) inorder(root->right);
    }
    
    int next() {
        return A[i++]->val;
    }
    
    bool hasNext() {
        return i < n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */