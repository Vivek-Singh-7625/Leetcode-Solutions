class Trie {
public:
    unordered_map<int,string> mpp;
    int n = 0;
    Trie() {
    }
    
    void insert(string word) {
        mpp[n++] = word;
    }
    
    bool search(string word) {
        for(int i = 0 ; i < n ; i++){
            if(mpp[i] == word)  return  true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int k = prefix.size();
        for(int i = 0 ; i < n ; i++){
            if(mpp[i].substr(0,k) == prefix)  return  true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */