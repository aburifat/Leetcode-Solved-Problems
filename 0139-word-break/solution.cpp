class TrieNode{
public:
    TrieNode* child[26];
    bool wordCk=false;
    TrieNode(){
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
    }
};

class Trie{
public:
    TrieNode* root;
    map<TrieNode*,int>nodeMp;
    vector<vector<bool>>visited,value;
    int nodeCt=0;
    Trie(){
        root = new TrieNode();
        nodeCt=1;
        nodeMp[root]=nodeCt;
    }
    void insert(string s){
        TrieNode* curr=root;
        for(int i=0;i<(int)s.size();i++){
            int idx=s[i]-'a';
            if(curr->child[idx]==nullptr){
                curr->child[idx]=new TrieNode();
                nodeCt++;
                nodeMp[curr->child[idx]]=nodeCt;
            }
            curr=curr->child[idx];
        }
        curr->wordCk=true;
    }

    bool search(string& s){
        TrieNode* curr=root;
        int len=s.size();
        visited.assign(len+5,vector<bool>(nodeCt+5,false));
        value.assign(len+5,vector<bool>(nodeCt+5,false));
        return splitSearch(s,0,curr);
    }

    bool splitSearch(string& s, int i, TrieNode* curr){
        int idx=s[i]-'a';
        if(visited[i][nodeMp[curr]]==true)return value[i][nodeMp[curr]];
        visited[i][nodeMp[curr]]=true;
        if(curr->child[idx]!=nullptr){
            TrieNode* tmp = curr->child[idx];
            if(tmp->wordCk==true){
                if(i==(int)s.size()-1) value[i][nodeMp[curr]] = true;
                else{
                    bool ck1 = splitSearch(s,i+1,curr->child[idx]);
                    bool ck2 = splitSearch(s,i+1,root);
                    if(ck1==true||ck2==true) value[i][nodeMp[curr]] = true;
                }
            }else{
                if(i==(int)s.size()-1)value[i][nodeMp[curr]] = false;
                else value[i][nodeMp[curr]] = splitSearch(s,i+1,curr->child[idx]);
            }
        }else{
            value[i][nodeMp[curr]]=false;
        }
        return value[i][nodeMp[curr]];
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* t = new Trie();
        for(int i=0;i<(int)wordDict.size();i++){
            t->insert(wordDict[i]);
        }
        bool ans = false;
        ans|= t->search(s);
        return ans;
    }
};
