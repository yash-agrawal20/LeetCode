class Solution {
private:
    double f(vector<int>& v1, vector<int>& v2){
        
        return sqrt((v1[0] - v2[0])*(v1[0] - v2[0]) + (v1[1] - v2[1])*(v1[1] - v2[1]));
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<vector<int>> p = {p1, p2, p3, p4};
        set<double> s;
        
        for(int i = 0; i < 3; i++){
            
            for(int j = i+1; j < 4; j++){
                
                double dis = f(p[i], p[j]);
                
                if(dis)
                    s.insert(dis);
                
                else
                    return false; // Distance is 0
            }
        }
        
        if(s.size() == 2)
            return true;
        else
            return false;
            
        
    }
};