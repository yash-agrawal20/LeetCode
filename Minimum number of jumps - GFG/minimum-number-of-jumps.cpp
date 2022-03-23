// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  private:
  int max(int x, int y){
      
      //return (x > y) ? x : y;
      if(x > y) return x;
      else return y;
  }
  
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        if(n <= 1) return 0;
        
        if(arr[0] == 0) return -1;
        
        //Maximal reachable index in the array
        int maxReach = arr[0];
        
        //Stores the number of steps
        int step = arr[0];
        
        //Stores the max number of jumps
        int jumps = 1;
        
        //Start traersing the array
        int i = 1;
        for(i = 1; i < n; i++){
            
            //Check if we have reached the last node
            if(i == (n-1)) return jumps;
            
            maxReach = max(maxReach, i + arr[i]);
            
            step--;
            
            if(step == 0){
                
                jumps++;
                
                if(i >= maxReach) return -1;
                
                step = maxReach - i;
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
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends