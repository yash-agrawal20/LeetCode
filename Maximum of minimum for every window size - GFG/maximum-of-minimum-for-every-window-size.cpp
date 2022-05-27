// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        //Approach 1:
        //Brute Force: O(n^3)
        //Approach 2:
        //TC: O(n), SC: O(n)
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        stack<int> s;
        
        //Finding the index of the previous lesser element
        for(int i = 0; i < n; i++){
            
            while(!s.empty() && (arr[s.top()] >= arr[i])){
                s.pop();
            }
            
            if(!s.empty()){
                left[i] = s.top();
            }
            
            s.push(i);
        }
        
        //Emptying the stack
        while(!s.empty()){
            s.pop();
        }
        
        //Finding the index of the right lesser element
        for(int i = n-1; i >= 0; i--){
            
            while(!s.empty() && (arr[s.top()]) >= arr[i]){
                s.pop();
            }
            
            if(!s.empty()){
                right[i] = s.top();
            }
            
            s.push(i);
        }
        
        //Doubtful step
        vector<int> ans(n+1, 0);
        
        for(int i = 0; i < n; i++){
            
            int len = right[i] - left[i] - 1;
            
            ans[len] = max(ans[len], arr[i]);
        }
        
        for(int i = n-1; i >= 0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        vector<int> res = vector<int>(ans.begin() + 1, ans.end());
        
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends