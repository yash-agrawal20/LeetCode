class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        //Using stack
        //Similar to postfix expression and result
        stack<int> s;
        
        for(int i = 0; i < tokens.size(); i++){
            
            if(tokens[i] == "+"){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                s.push(x+y);
            }
            
            else if(tokens[i] == "-"){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                s.push(x-y);
            }
            
            else if(tokens[i] == "*"){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                s.push(x*y);
            }
            
            else if(tokens[i] == "/"){
                
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                
                s.push(x/y);
            }
            
            else{
                int x = stoi(tokens[i]);
                s.push(x);
            }
        }
        
        return s.top();
        
    }
};