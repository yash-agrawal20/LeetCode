// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        // Your code here
        stack<int> s;
        
        for(int i = 0; i < str.size(); i++){
            
            if(str[i] == '+'){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                int r = x+y;
                s.push(r);
            }
            
            else if(str[i] == '-'){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                int r = x-y;
                s.push(r);
            }
            
            else if(str[i] == '*'){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                int r = x*y;
                s.push(r);
            }
            
            else if(str[i] == '/'){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                int r = x/y;
                s.push(r);
            }
            
            else{
                int x = str[i] - '0';
                s.push(x);
            }
        }
        
        return s.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends