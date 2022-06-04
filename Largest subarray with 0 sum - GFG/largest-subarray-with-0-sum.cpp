// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        //Using Hashmap
        
        unordered_map<int, int>mp;
        int sum = 0;
        int maxC = 0;
        
        mp.insert({0,-1});
        
        for(int i = 0; i < n; i++){
            
            sum += A[i];
            
            if(mp.count(sum) > 0){
                
                int len = i - mp.find(sum)->second;
                if(len > maxC){
                    maxC = len;
                }
            }
            
            else{
                mp.insert({sum, i});
            }
        }
        
        return maxC;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends