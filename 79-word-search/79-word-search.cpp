//https://leetcode.com/problems/word-search/discuss/1507900/C%2B%2B-DFS-Solution-oror-TLE-explanation

class Solution {
private:
    bool check(vector<vector<char>>& board, string word, int i, int j, int index){
        
        if(index == word.size())
            return true;
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[index])
            return false;
        
        board[i][j] = '0';
        
        bool status = check(board, word, i+1, j, index+1) || //right
                      check(board, word, i-1, j, index+1) || //left
                      check(board, word, i, j+1, index+1) || //down
                      check(board, word, i, j-1, index+1); //up
        
        board[i][j] = word[index];
        
        return status;            
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(board[i][j] == word[0] && check(board, word, i, j, 0))
                    return true;
            }
        }        
        
        return false;
    }
};