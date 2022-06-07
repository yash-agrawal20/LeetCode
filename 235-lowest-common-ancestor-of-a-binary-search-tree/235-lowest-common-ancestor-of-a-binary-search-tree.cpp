//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/discuss/64980/C%2B%2B-Recursive-and-Iterative

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private: 
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root->val > p->val && root->val > q->val)
            return f(root->left, p, q);
        
        if(root->val < p->val && root->val < q->val)
            return f(root->right, p, q);
        
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //Iteratively
//         TreeNode* curr = root;
        
//         while(true){
            
//             if(curr->val > p->val && curr->val > q->val)
//                 curr = curr->left;
            
//             else if(curr->val < p->val && curr->val < q->val)
//                 curr = curr->right;
            
//             else 
//                 break;
//         }
        
//         return curr;
        
        //Recursively
        return f(root, p, q);
        
    }
};