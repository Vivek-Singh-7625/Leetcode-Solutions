
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<pair<int,long long>> pq;
        long long total = 1LL*k1 + k2;
        int n = nums1.size();
        unordered_map<int,long long> mpp;
        long long cost , next;

        for(int i = 0 ; i < n ; i++)    mpp[abs(nums1[i] - nums2[i])]++;
        for(auto& [k,v] : mpp){
            pq.push({k,v});
        }

        while(total > 0 and !pq.empty()){
            if(pq.top().first == 0)   return 0;
            auto [f , c] = pq.top();
            pq.pop();
            next = pq.empty() ? 0 : pq.top().first;
            cost = 1LL*(f-next)*c;

            if(total >= cost){
                total -= cost;

                if(!pq.empty() and pq.top().first == next){
                    c += pq.top().second;
                    pq.pop();
                }
                pq.push({next , c});
            }
            else{
                long long q = total/c;
                long long r = total%c;
                int val = f-q;

                if(c-r > 0)    pq.push({val , c-r});
                if(r > 0)      pq.push({val-1 , r});
                total = 0;
            }
        }

        long long ans = 0;

        while(!pq.empty()){
            auto [f , c] = pq.top();
            pq.pop();
            ans += 1LL*f*f*c;
        }

        return ans;
    }
};
