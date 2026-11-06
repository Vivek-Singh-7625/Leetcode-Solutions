class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        deque<int> p;
        int k = 0 , n = deck.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++)   p.push_back(i);
        while(!p.empty()){
            ans[p.front()] = deck[k++];
            p.pop_front();
            if(!p.empty()){
                p.push_back(p.front());
                p.pop_front();
            }
        }
        return ans;
    }
};