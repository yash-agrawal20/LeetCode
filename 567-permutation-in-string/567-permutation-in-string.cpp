class Solution {
private:
    bool areVectorsEqual(vector<int> freq1, vector<int> freq2){
        
        for(int i = 0; i < 26; i++){
            
            if(freq1[i] != freq2[i]) return false;
        }
        
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        
           //Mine Approach: Multi set (TLE)
//         if(s1.size() > s2.size())
//             return false;
        
//         //Storing the elements of s1
//         multiset<char> s;
//         for(int i = 0; i < s1.size(); i++){
            
//             s.insert(s1[i]);
//         }
        
//         for(int i = 0; i <= (s2.size() - s1.size()); i++){
            
//             if(s.find(s2[i]) != s.end()){
                
//                 //Copy for easier deleating the indiavidual characters
//                 multiset<char> cp = s;
//                 int j = i;
                
//                 cp.erase(cp.find(s2[j]));
//                 j++;
                
//                 while(!cp.empty()){
                    
//                     if(cp.find(s2[j]) != cp.end()){
//                         cp.erase(cp.find(s2[j]));
//                         j++;
//                     }
//                     else break;
//                 }
                
//                 //If all the elements of s1 are found in s2
//                 if(cp.empty()) return true;
//             }
//         }
        
//         return false;
//https://leetcode.com/problems/permutation-in-string/discuss/1762469/C%2B%2B-oror-SLIDING-WINDOW-OPTIMIZED-oror-Well-Explained      
        //Sliding window Approach
        if(s1.size() > s2.size())
            return false;
        
        vector<int> freq1(26, 0);
        for(char c: s1){
            freq1[c - 'a']++;
        }
        
        vector<int> freq2(26, 0);
        int i = 0, j = 0;
        
        while(j < s2.size()){
            
            freq2[s2[j] - 'a']++;
            
            if((j - i + 1) == s1.size()){
                
                if(areVectorsEqual(freq1, freq2)) return true;
            }
            
            if((j - i + 1) < s1.size()) j++;
            
            else{
                freq2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        
        return false;
        
    }
};