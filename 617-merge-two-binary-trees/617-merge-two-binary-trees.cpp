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
    TreeNode* f(TreeNode* n1, TreeNode* n2){
        
        if(!n1 && !n2)
            return NULL;
        
        int val1 = 0, val2 = 0;
        
        if(n1)
            val1 = n1->val;
        if(n2)
            val2 = n2->val;
        
        TreeNode* n3 = new TreeNode(val1 + val2);
        
        //Important - Taking into consideration the NULL pointer
        if(n1 && n2){
            n3->left = f(n1->left, n2->left);
            n3->right = f(n1->right, n2->right);
        }
        
        if(n1 && !n2){
            n3->left = f(n1->left, NULL);
            n3->right = f(n1->right, NULL);
        }
        
        if(!n1 && n2){
            n3->left = f(NULL, n2->left);
            n3->right = f(NULL, n2->right);
        }
        
        return n3;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        //Recursive Approach
        return f(root1, root2);
    }
};