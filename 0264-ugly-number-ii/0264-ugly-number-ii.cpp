class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> p;
        p.push(1);
        vector<int> ans(n);
        ans[0] = 1;
        int x , k = 0;
        while(k < n-1){
            x = p.top();
            if(x < INT_MAX/2)   p.push(x*2);
            if(x < INT_MAX/3)   p.push(x*3);
            if(x < INT_MAX/5)   p.push(x*5);
            while(p.top() == ans[k])    p.pop();
            ans[++k] = p.top();
        }
        return ans[n-1];
    }
};