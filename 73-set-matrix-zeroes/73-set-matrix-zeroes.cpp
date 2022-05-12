class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        unordered_set<int> row;
        unordered_set<int> column;
        
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                //Identifying the row and column where 0 occurs
                if(matrix[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        
        //Setting the corresponding row to 0
        for(auto i : row){
            for(int j = 0; j < n; j++){
                
                matrix[i][j] = 0;
            }
        }
        
        for(auto j : column){
            for(int i = 0; i < m; i++){
                
                matrix[i][j] = 0;
            }
        }
        
    }
};