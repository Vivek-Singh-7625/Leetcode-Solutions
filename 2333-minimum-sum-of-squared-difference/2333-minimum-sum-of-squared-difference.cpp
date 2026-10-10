
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<pair<int,int>> v;
        long long total = 1LL*k1 + k2;
        int n = nums1.size() , next , count , curr , val;
        unordered_map<int,int> mpp;
        long long cost , p , q;

        for(int i = 0 ; i < n ; i++)    mpp[abs(nums1[i] - nums2[i])]++;
        for(auto& [k,value] : mpp){
            v.push_back({k,value});
        }
        sort(v.begin() , v.end());
        n = v.size();

        while(total > 0){
            curr = v[n-1].first;
            if(curr == 0)    return 0;
            next = (n <= 1) ? 0 : v[n-2].first;
            count = v[n-1].second;
            cost = 1LL*count*(curr-next);
            if(total >= cost){
                total -= cost;
                if(n == 1)    return 0;
                v[n-2].second += v[n-1].second;
                v.pop_back();
                n--;
            }
            else{
                p = total/count;
                q = total%count;
                val = curr-p;
                v[n-1] = {val,count-q};
                if(q > 0)    v.push_back({val-1,q}) , n++;
                total = 0;
            }
        }

        long long ans = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            curr = v[i].first;
            ans += 1LL*curr*curr*v[i].second;
        }
        return ans;
    }
};
