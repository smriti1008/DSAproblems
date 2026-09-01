class StockSpanner {
public:
    
    stack<int> s;
    vector<int> price;
    vector<int> ans;


    StockSpanner() {
        
    }
    
    int next(int p) {
            price.push_back(p);

            int i = price.size() - 1;

            while(s.size()>0 && price[s.top()]<=price[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                ans.push_back(i+1);
            }
            else
            {
                ans.push_back(i-s.top());
            }

            s.push(i);
        return ans[i];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */