class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& nums) {
        a.push_back(0);
        int p = 0;
        for(int x : nums){  
            p += x; 
            a.push_back(p);
        }
    }
    
    void update(int index, int val) {
        int t = val - (a[index+1]-a[index]);
        for(int i = index + 1 ; i < a.size() ; i++)    a[i] += t;
    }
    
    int sumRange(int left, int right) {
        return a[right+1] - a[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */