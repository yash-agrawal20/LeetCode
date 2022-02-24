class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n = size(columnTitle);
        int cn = 0;
        
        for(int i = 0; i < n; i++){
            
            int len_num = int(columnTitle[i] - 'A' + 1);
            cn += pow(26, n-i-1)*len_num;
        }
        
        return cn;
        
    }
};