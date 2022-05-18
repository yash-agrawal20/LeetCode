class Solution {
public:
    string intToRoman(int num) {
        
        vector<int> integers = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        
        for(int i = 0; i < integers.size(); i++){
            
            while(num >= integers[i]){
                
                res += roman[i];
                num -= integers[i];
            }
        }
        
        return res;        
        
    }
};