//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise

class Solution {
private:
    int f(vector<vector<int>>& matrix, int m){
        
        int cnt = 0;
        int col = matrix.size()-1;
        
        for(int r = 0; r < matrix.size(); r++){
            
            while(col >= 0 && matrix[r][col] > m)
                col--;
            
            cnt += (col + 1);
        }        
        
        return cnt;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //Using Max Heap
        //Time Complexity: O(n^2logK)
        //Space Complexity: O(k)
//         priority_queue<int> maxh;
        
//         for(int i = 0; i < matrix.size(); i++){
            
//             for(int j = 0; j < matrix.size(); j++){
                
//                 maxh.push(matrix[i][j]);
                
//                 if(maxh.size() > k){
                    
//                     maxh.pop();
//                 }
                    
//             }
//         }
        
//         return maxh.top();
        
        //Using binary search
        //Space Complexity: O(1)
        
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int ans = -1;
        
        while(left <= right){
            
            int mid = (left + right)/2;
            
            if(f(matrix, mid) >= k){
                
                ans = mid;
                right = mid-1;
            }
            else
                left = mid + 1;
        }
        
        return ans;        
    }
};