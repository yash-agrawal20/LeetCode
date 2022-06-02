class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.size();
        
        //Using Priority queue
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto p : mp){
            
           if(p.second > (n+1)/2)
               return "";
            
            pq.push({p.second, p.first});
        }
        
        string res = "";
        pair<int, char> top1, top2;
        
        while(!pq.empty()){
            
            top1 = pq.top();
            pq.pop();
            res += top1.second;
            
            if(!pq.empty()){
                
                top2 = pq.top();
                pq.pop();
                res += top2.second;
                
                if(top2.first > 1)
                    pq.push({top2.first - 1, top2.second});
            }
            
            if(top1.first > 1)
                pq.push({top1.first - 1, top1.second});
        }
        
        for(int i = 1; i < res.size(); i++){
            
            if(res[i] == res[i-1])
                return "";
        }
        return res;
    }
};