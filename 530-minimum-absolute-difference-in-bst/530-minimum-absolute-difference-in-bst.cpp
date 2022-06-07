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
    int f(TreeNode* root, int& minN, int& val){
        
        if(root->left)
            f(root->left, minN, val);

        if(val >= 0)
            minN = min(minN, root->val - val);
        
        val = root->val;
        
        if(root->right)
            f(root->right, minN, val);
        
        return minN;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        
        //Using recursion
        //Inorder Traversal
        int min = INT_MAX;
        int val = -1;
        
        return f(root, min, val);
        
    }
};