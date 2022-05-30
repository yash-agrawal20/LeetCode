class StockSpanner {
private:
    //Stock price and count
    stack<pair<int, int>> s;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int count = 1;
        
        while(!s.empty() && s.top().first <= price){
            
            count += s.top().second;
            s.pop();
        }
        
        s.push({price, count});
        
        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */