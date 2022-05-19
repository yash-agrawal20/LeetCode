class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> temp = board;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> dir = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                int count = 0;
                for(int k = 0; k < 8; k++){
                    
                    int col = j + dir[k][1];
                    int row = i + dir[k][0];
                    
                    if(col >= 0 && col < n && row >= 0 && row < m && board[row][col] == 1){
                        
                        count++;
                        //To save time
                        if(count > 3)
                            break;
                    }
                }
                
                // cout << i << ' ' << j << ' ' << count << endl;
                if(board[i][j] == 0 && count == 3)
                    temp[i][j] = 1;
                
                else if(board[i][j] == 1 && (count < 2 || count > 3))
                    temp[i][j] = 0;
                    
            }
        }
        
        board = temp;        
    }
};