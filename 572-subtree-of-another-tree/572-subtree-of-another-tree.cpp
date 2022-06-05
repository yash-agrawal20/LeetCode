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
    bool f(TreeNode* node1, TreeNode* node2){
        
        if(!node1 || !node2)
            return node1 == NULL && node2 == NULL;
        
        else if(node1->val == node2->val){
            
            return f(node1->left, node2->left) && f(node1->right, node2->right);
        }
        
        else
            return false;
        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //O(n*m)
        if(!root)
            return false;
        
        else if(f(root, subRoot))
            return true;
        
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};