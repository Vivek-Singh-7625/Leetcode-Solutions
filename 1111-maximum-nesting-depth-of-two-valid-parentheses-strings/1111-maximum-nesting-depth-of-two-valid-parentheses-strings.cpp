class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length() , t = 0;
        vector<int> a(n,0);
        for(int i = 0 ; i < n ; i++){
            if(seq[i] == ')') t--;
            if(t%2) a[i] = 1;
            if(seq[i] == '(') t++;
        }
        return a;
    }
};