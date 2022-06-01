class Solution {
public:
    string addBinary(string a, string b) {
        
        deque<int> d;
        int n = a.size();
        int m = b.size();
        int carry = 0;
        
        while(n || m || carry){
            
            int x = 0;
            
            if(n > 0){
                n--;
                x += a[n] - '0';
            }
            
            if(m > 0){
                m--;
                x += b[m] - '0';
            }
            
            x += carry;
            d.push_front(x % 2);
            
            if(x > 1){
                carry = 1;
            }
            else
                carry = 0;
        }
        
        string res;
        while(d.size()){
            
            string s = to_string(d.front());
            d.pop_front();
            res += s;
        }
        
        return res;
        
    }
};