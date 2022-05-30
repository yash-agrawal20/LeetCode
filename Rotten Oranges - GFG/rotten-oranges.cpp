// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        //Indexes of x, y to be used
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        
        //Storing all the values where 2 occurs
        queue<pair<int, int>> q;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        //Minimum time required so that all orranges turn rotten
        int ans = 0;
        
        while(!q.empty()){
            
            int n = q.size();
            int flag = 0;
            
            while(n--){
                
                auto curr = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    
                    int index_x = curr.first + x[i];
                    int index_y = curr.second + y[i];
                    
                    if(index_x >= 0 && index_x < grid.size() &&
                       index_y >= 0 && index_y < grid[0].size() &&
                       grid[index_x][index_y] == 1){
                           
                           q.push({index_x, index_y});
                           grid[index_x][index_y] = 2;
                           flag = 1;
                       }
                }
            }
            
            if(flag == 1){
                ans++;
            }
        }
        
        for(int i = 0; i < grid.size(); i++){
            
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends