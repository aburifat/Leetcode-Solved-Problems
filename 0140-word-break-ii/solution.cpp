class TrieNode{
public:
    TrieNode* child[26];
    TrieNode* parent=nullptr;
    char ch='#';
    bool wordEnd=false;
    TrieNode(TrieNode* parent=nullptr, char ch='#'){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        this->parent=parent;
        this->ch=ch;
    }
};

class Trie{
public:
    TrieNode* root;
    map<TrieNode*,int>nodeIdx;
    int nodeCt=0;
    vector<vector<TrieNode*>>path;
    vector<vector<bool>>mem;
    Trie(){
        root = new TrieNode();
    }
    void insert(string s){
        TrieNode* curr = root;
        for(int i=0;i<(int)s.size();i++){
            int idx=s[i]-'a';
            if(curr->child[idx]==nullptr){
                curr->child[idx]=new TrieNode(curr,s[i]);
                nodeCt++;
                nodeIdx[curr->child[idx]]=nodeCt;
            }
            curr->child[idx]->parent=curr;
            curr->child[idx]->ch=s[i];
            curr=curr->child[idx];
        }
        curr->wordEnd=true;
    }
    void splitSearch(int i, int& len, TrieNode* curr, string& s, vector<TrieNode*> v){
        int idx = s[i] - 'a';
        if(curr->child[idx]==nullptr)return;
        else{
            TrieNode* tmp = curr->child[idx];
            if(tmp->wordEnd==true){
                if(i!=len-1){
                    splitSearch(i+1,len,tmp,s,v);
                    v.push_back(tmp);
                    splitSearch(i+1,len,root,s,v);
                }else{
                    v.push_back(tmp);
                    path.push_back(v);
                }
            }else{
                if(i!=len-1){
                    splitSearch(i+1,len,tmp,s,v);
                }else{
                    return;
                }
            }
        }
    }
    void search(string s){
        int len=(int)s.size();
        vector<TrieNode*>v;
        splitSearch(0,len,root,s,v);
    }
    vector<char> getWord(TrieNode* curr){
        vector<char>word;
        while(curr->parent!=nullptr){
            word.push_back(curr->ch);
            curr=curr->parent;
        }
        return word;
    }

    string getSantence(vector<TrieNode*> v){
        string santence="";
        for(int i=0;i<(int)v.size();i++){
            vector<char>word=getWord(v[i]);
            if((int)santence.size()>0 && (int)word.size()>0)santence+=' ';
            for(int j=(int)word.size()-1;j>=0;j--){
                santence+=word[j];
            }
        }
        return santence;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len=wordDict.size();
        Trie* t = new Trie();
        for(int i=0;i<len;i++){
            t->insert(wordDict[i]);
        }
        t->search(s);
        len = t->path.size();
        vector<string>ans;
        string tmp;
        for(int i=0;i<len;i++){
            tmp=t->getSantence(t->path[i]);
            ans.push_back(tmp);
        }
        return ans;
    }
};
