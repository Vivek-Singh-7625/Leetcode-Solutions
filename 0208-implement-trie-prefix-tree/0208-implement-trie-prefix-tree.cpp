class Trie {
public:
    unordered_map<int,vector<string>> mpp;
    Trie() {
    }
    
    void insert(string word) {
        mpp[word[0] - 'a'].push_back(word);
    }
    
    bool search(string word) {
        for(string x : mpp[word[0] - 'a']){
            if(x == word)  return  true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int k = prefix.size();
        for(string x : mpp[prefix[0] - 'a']){
            if(x.substr(0,k) == prefix)  return  true;
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