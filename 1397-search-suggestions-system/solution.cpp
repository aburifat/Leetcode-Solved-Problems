class TrieNode{
public:
    TrieNode* child[26];
    bool end_word=false;
    TrieNode(){
        for(int i=0;i<26;i++)child[i]=nullptr;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root=new TrieNode();
    }

    void insert(string s){
        TrieNode* curr=root;
        for(int i=0;i<(int)s.size();i++){
            int idx=s[i]-'a';
            if(curr->child[idx]==nullptr)curr->child[idx]=new TrieNode();
            curr=curr->child[idx];
        }
        curr->end_word=true;
    }

    void find(int idx, TrieNode* curr, vector<string>& words, string pre){
        if(words.size()>=3)return;
        pre+=('a'+idx);
        if(curr->end_word==true)words.push_back(pre);
        for(int i=0;i<26;i++){
            if(curr->child[i]!=nullptr){
                find(i,curr->child[i],words,pre);
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        Trie* t=new Trie();

        for(int i=0;i<(int)products.size();i++){
            t->insert(products[i]);
        }

        string s="";
        int len=searchWord.size();
        vector<vector<string>>v(len,vector<string>());
        TrieNode* curr=t->root;

        for(int i=0;i<len;i++){
            int idx=searchWord[i]-'a';
            if(curr->child[idx]!=nullptr)curr=curr->child[idx];
            else break;
            vector<string>tmp;
            t->find(idx,curr,tmp,s);
            for(int j=0;j<min(3,(int)tmp.size());j++){
                v[i].push_back(tmp[j]);
            }
            s+=searchWord[i];
        }

        while(v.size()<len){
            v.push_back(vector<string>());
        }

        return v;
    }
};
