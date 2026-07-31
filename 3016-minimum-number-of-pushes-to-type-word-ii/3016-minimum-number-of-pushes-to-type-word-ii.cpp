class Solution {
public:
    int minimumPushes(string word) {
        vector<int> A(26,0);
        int n = word.size() , ans = 0;
        for(int i = 0 ; i < n ; i++)    A[word[i]-'a']++;
        for(int i = 1; i < 26; i++){
		    for(int j = i; j > 0 && A[j] > A[j-1]; j--){
			    swap(A[j],A[j-1]);
		    }
	    }
        for(int i = 0 ; i < 26 ; i++)   ans += (i/8 + 1)*A[i];
        return ans;
    }
};