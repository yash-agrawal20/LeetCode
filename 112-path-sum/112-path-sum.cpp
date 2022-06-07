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
private:
    bool f(TreeNode* node, int t){
        
        //Base Condtion
        if(node == NULL)
            return false;
        
        //Stuff
        t = t-node->val;
        
        if(node->left == NULL && node->right == NULL && t == 0)
            return true;
        
        return f(node->left, t) || f(node->right, t);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        
        return f(root, targetSum);
    }
};