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
    int f(TreeNode* node, int &d){
        
        if(!node)
            return 0;
        
        int lh = f(node->left, d);
        int rh = f(node->right, d);
        
        d = max(d, lh+rh);
        
        return 1 + max(lh, rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d = 0;
        f(root, d);
        
        return d;       

    }
};