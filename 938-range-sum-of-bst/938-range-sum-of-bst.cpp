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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        //Iterative Approach
//         queue<TreeNode*> q;
//         q.push(root);
//         int sum = 0;
        
//         while(!q.empty()){
            
//             TreeNode* temp = q.front();
//             q.pop();
            
//             if(temp->val >= low && temp->val <= high)
//                 sum += temp->val;
            
//             if(temp->left)
//                 q.push(temp->left);
            
//             if(temp->right)
//                 q.push(temp->right);
//         }
        
//         return sum;
        
        //Using the properties of BST
        queue<TreeNode*> q;
        
        q.push(root);
        int sum = 0;
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->val >= low && temp->val <= high){
                sum += temp->val;
                
                if(temp->right)
                    q.push(temp->right);
                
                if(temp->left)
                    q.push(temp->left);
            }
            
            if(temp->val > high && temp->left)
                q.push(temp->left);
            
            if(temp->val < low && temp->right)
                q.push(temp->right);
        }
        
        return sum;        
    }
};