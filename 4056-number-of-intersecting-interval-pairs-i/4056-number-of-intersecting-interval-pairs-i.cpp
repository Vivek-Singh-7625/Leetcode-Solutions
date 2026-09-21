class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() , ans = 0;
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(intervals[i][1] >= intervals[j][0] and intervals[i][0] <= intervals[j][1])  ans++;
            }
        }
        return ans;
    }
    static bool cmp(const vector<int> a , const vector<int> b){
        return b[1] > a[1];
    }
};