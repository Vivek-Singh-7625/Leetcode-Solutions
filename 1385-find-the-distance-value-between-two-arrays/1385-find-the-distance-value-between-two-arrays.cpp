class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int mn = INT_MAX , mx = INT_MIN , t , ans = 0;
        for(int x : arr1){
            t = INT_MAX;
            for(int y : arr2){
                t = min(t,abs(y-x));
                if(t <= d)   break;
            }
            if(t > d)   ans++;
        }
        return ans;
    }
};