class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int prev = INT_MIN , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(intervals[i][0] >= prev){
                prev = intervals[i][1];
                ans++;
            }
        }
        return n - ans;
    }
    static bool cmp(const vector<int>& a ,const vector<int>& b){
        return a[1] < b[1];
    }
};