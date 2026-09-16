class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0 , h = arr.size()-1;
        while(h-l+1 > k){
            if(abs(arr[h]-x) >= abs(arr[l]-x))   h--;
            else    l++;
        }
        vector<int> ans;
        for(int i = l ; i <= h ; i++)    ans.push_back(arr[i]);
        return ans;
    }
};