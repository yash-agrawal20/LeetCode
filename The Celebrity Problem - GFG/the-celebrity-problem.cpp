// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    int rowCheck(vector<vector<int> >& M, int i){
        
        for(int j = 0; j < M.size(); j++){
            
            if(M[i][j] == 1){
                return 0;
            }
        }
        
        return 1;
    }
    
    int columnCheck(vector<vector<int> >& M, int i){
        
        int count = 0;
        for(int j = 0; j < M.size(); j++){
            
            if(M[j][i] == 0){
                count++;
            }
            if(count == 2){
                return count;
            }
        }
        return 1;
    }
    
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i = 0; i < n; i++){
            
            //Check if the row has only zeroes
            if(rowCheck(M, i)){
                
                //Check if there is only one zero in the column
                if(columnCheck(M, i) == 1){
                    return i;
                }
            }
        }
        
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends