struct Node {
    Node* chars[26];
    bool isEnd;
    Node () {
        for(int i = 0 ; i < 26 ; i++){
            chars[i] = NULL;
            isEnd = false;
        }
    }
    bool contains(char c){
        return (chars[c-'a'] != NULL);
    }
    void put(char c , Node* t){
        chars[c-'a'] = t;
    }
    Node* get(char c) {
        return chars[c-'a'];
    }
    void End() {
        isEnd = true;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* t = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!t->contains(word[i]))   t->put(word[i], new Node);
            t = t->get(word[i]);
        }
        t->End();
    }
    
    bool search(string word) {
        Node* t = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!t->contains(word[i]))   return false;
            t = t->get(word[i]);
        }
        return t->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* t = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!t->contains(prefix[i]))   return false;
            t = t->get(prefix[i]);
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */