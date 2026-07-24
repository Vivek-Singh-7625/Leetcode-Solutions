class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> A;
    vector<bool> T;
    SmallestInfiniteSet() : T(1001, true) {
        for(int i = 1 ; i <= 1000 ; i++)    A.push(i);
    }
    int popSmallest() {
        int x = -1;
        if(!A.empty()){
            x = A.top();
            T[x] = false;
            A.pop();
        }
        return x;
    }
    
    void addBack(int num) {
        if(!T[num]) A.push(num);
        T[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */