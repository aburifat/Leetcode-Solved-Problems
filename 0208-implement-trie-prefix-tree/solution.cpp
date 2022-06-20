class TrieNode{
public:
    TrieNode *next[26];
    bool endword;
    TrieNode(){
        for(int i=0;i<26;i++)next[i]=NULL;
        endword=false;
    }
};
class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->next[idx]==NULL){
                curr->next[idx]=new TrieNode();
            }
            curr=curr->next[idx];
        }
        curr->endword=true;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(curr->next[idx]==NULL)return false;
            curr=curr->next[idx];
        }
        if(curr->endword==true)return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(int i=0;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            if(curr->next[idx]==NULL)return false;
            curr=curr->next[idx];
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
