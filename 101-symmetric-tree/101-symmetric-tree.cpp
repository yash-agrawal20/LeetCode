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
    
    bool isSymmetricCheck(TreeNode* left, TreeNode* right){
        
        if(left == NULL || right == NULL) return left == right;
        
        if(left->val != right-> val) return false;
        
        return isSymmetricCheck(left->left, right->right) 
            && isSymmetricCheck(left->right, right->left);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        
        //Recursive Approach
        // return isSymmetricCheck(root->left, root->right);
        
        //Iterative Approach
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty()){
            
            TreeNode* temp1 = q1.front();
            q1.pop();
            
            TreeNode* temp2 = q2.front();
            q2.pop();
            
            if(!temp1 && !temp2)
                continue;
            
            if(!temp1 || !temp2)
                return false;
            
            if(temp1->val != temp2->val)
                return false;
            
            q1.push(temp1->left);
            q2.push(temp2->right);
            
            q1.push(temp1->right);
            q2.push(temp2->left);
        }
        
        return true;
              
    }
};