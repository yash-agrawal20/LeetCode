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
    bool isBalanced(TreeNode* root) 
    {
        int val;
        return isBalanced(root, val);
    }
    
    bool isBalanced(TreeNode *node, int &height)
    {
        if (node == nullptr)
        {
            height = 0;
            return true;
        }
        int lh = 0, rh = 0;
        if (isBalanced(node->left, lh) && isBalanced(node->right, rh) && abs(lh - rh) <= 1)
        {
            height = max(lh, rh) + 1;
            return true;
        }
        return false;
    }
};