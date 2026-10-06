class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int st = 0 , ed = 0 , n = intervals.size();
        while(st < n and intervals[st][0] < newInterval[0]){
            if(intervals[st][1] >= newInterval[0])  break;
            st++;
        }
        ed = st;
        while(ed < n and intervals[ed][0] < newInterval[1]){
            if(intervals[ed][1] >= newInterval[1])  break;
            ed++;
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i < st ; i++)   ans.push_back(intervals[i]);
        if(ed < n and intervals[ed][0] <= newInterval[1]) ans.push_back({min(intervals[st][0],newInterval[0]),max(newInterval[1],intervals[ed][1])}) ;
        else    ans.push_back({min(st < n ? intervals[st][0] : INT_MAX,newInterval[0]),newInterval[1]}) , ed--;
        for(int i = ed+1 ; i < n ; i++)   ans.push_back(intervals[i]);
        return ans;
    }
};