class Solution {
private:
    int GCD(int a, int b){
        
        if(b == 0)
            return a;
        
        return GCD(b, a%b);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size() <= 2)
            return points.size();
        
        //Fina; count
        int res = 0;
        
        for(int i = 0; i < points.size() - 1; i++){
            
            int local = 0;
            int overlap = 0;
            int vertical = 0;
            map<pair<int, int>, int> mp;
            
            for(int j = i+1; j < points.size(); j++){
                
                if(points[i][0] == points[j][0]){
                    
                    if(points[i][1] == points[j][1])
                        overlap++; //Same number is repeating
                    else
                        vertical++;
                }
                
                else{
                    int a = points[j][0] - points[i][0];
                    int b = points[j][1] - points[i][1];
                    
                    int gcd = GCD(a, b);
                    
                    a /= gcd;
                    b /= gcd;
                    
                    mp[{a, b}]++;
                    local = max(mp[{a, b}], local);
                }
                
                local = max(vertical, local);
            }
            
            res = max(res, local + overlap + 1);
        }
        
        return res;
    }
};