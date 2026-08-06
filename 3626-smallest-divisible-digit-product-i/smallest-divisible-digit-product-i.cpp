class Solution {
public:

    int digitProduct(int x)
    {
        if(x==0)
        {
            return 0;
        }
        int product=1;
        while(x>0)
        {
            product*=(x%10);
            x/=10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true)
        {
            int p=digitProduct(n);

            if(p%t==0)
            return n;
            n++;
        }
        
    }
};