class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize)   return false;
        priority_queue<int,vector<int>,greater<int>> p , q;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++)    mpp[hand[i]]++;
        for(auto& [y,v] : mpp){
            p.push(y);
        }
        int t , k = 0;
        vector<int> a(groupSize);
        while(!p.empty()){
            t = p.top();
            mpp[t]--;
            p.pop();
            if(mpp[t])  q.push(t);
            a[k%groupSize] = t;
            if( !((k+1) % groupSize) ){
                while(!q.empty()){
                    p.push(q.top());
                    q.pop();
                }
                for(int i = 1 ; i < groupSize ; i++){
                    if(a[i]-a[i-1] != 1)    return false;
                }
            }
            k++;
        }
        return k == n;
    }
};