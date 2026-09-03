class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2 , sum1 = 0 , sum2 = 0 , k = 0;   
        vector<vector<int>> left(n + 1), right(n + 1);
        for(int i = 0 ; i < (1<<n) ; i++){
            sum1 = 0 , sum2 = 0;
            for(int j = 0 ; j < n ; j++){
                if(i&(1<<j)){
                    sum1 += nums[j];
                    sum2 += nums[n+j];
                    k++;
                }
            }
            left[k].push_back(sum1);
            right[k].push_back(sum2);
            k = 0;
        }
        int target , sum = 0 , ans = INT_MAX;
        for(int x : nums)   sum += x;
        for(int i = 0 ; i < n+1 ; i++){
            sort(right[n-i].begin(),right[n-i].end());
            for(int x : left[i]){
                target = (sum-2*x)/2;
                auto itr = lower_bound(right[n-i].begin(),right[n-i].end(),target);
                if(itr != right[n-i].end()) ans = min(ans,abs(sum - 2*x - 2*(*itr)));
                if(itr != right[n-i].begin()){
                    itr--;
                    ans = min(ans,abs(sum - 2*x - 2*(*itr)));
                }
            }
        }
        return ans;
    }
};