class SmallestInfiniteSet {
public:
    vector<bool> T;
    int x = 1;
    SmallestInfiniteSet() : T(1000, true) {

    }
    int popSmallest() {
        int y = x; 
        T[x-1] = false;
        for(int i = x ; i < 1000 ; i++){
            if(T[i]){
                x = i+1;
                break;
            }
        }
        return y;
    }
    
    void addBack(int num) {
        T[num-1] = true;
        if(num < x) x = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */