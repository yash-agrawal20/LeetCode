//https://leetcode.com/problems/basic-calculator-ii/discuss/63006/C%2B%2B-stack-solution.

class Solution {
public:
    int calculate(string s) {
               
        int n = s.size();
        stack<int> st;
        int res = 0;
        long tmp = 0;
        char sign  = '+';
        
        for(unsigned int i = 0; i < n; i++){
            
            if(isdigit(s[i]))
                tmp = tmp * 10 + s[i] - '0';
            
            if(!isdigit(s[i]) && !isspace(s[i]) || (i == n-1)){
                
                if(sign == '+')
                    st.push(tmp);
                
                else if(sign == '-')
                    st.push(-tmp);
                
                else{
                    int num;
                    
                    if(sign == '*')
                        num = st.top() * tmp;
                    
                    else
                        num = st.top() / tmp;
                    
                    st.pop();
                    st.push(num);
                }
                
                tmp = 0;
                sign = s[i];
            }
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};