class Solution {
    int keyRnk;
    int currRnk;
    map<char,int>keyPat;
    map<char,int>currPat;
public:
    pair<int,int>getWindow(int siz,string s,int len){
        int x=-1,y=-1;
        currRnk=0;
        currPat.clear();
        for(int i=0;i<siz;i++){
            if(currPat[s[i]]<keyPat[s[i]]){
                currRnk++;
            }
            currPat[s[i]]++;
        }
        if(currRnk==keyRnk)return {0,siz-1};
        else{
            int l=1,r=siz;
            for(;r<len;l++,r++){
                if(currPat[s[l-1]]<=keyPat[s[l-1]])currRnk--;
                currPat[s[l-1]]--;
                if(currPat[s[r]]<keyPat[s[r]])currRnk++;
                currPat[s[r]]++;
                if(currRnk==keyRnk){
                    x=l;
                    y=r;
                    break;
                }
            }
        }
        return {x,y};  
    }
    string minWindow(string s, string t) {
        keyRnk=t.size();
        int len=s.size();
        keyPat.clear();
        currPat.clear();
        for(int i=0;i<keyRnk;i++){
            keyPat[t[i]]++;
        }
        int l=1,r=len;
        pair<int,int>ans={-1,-1},iniPr={-1,-1};
        while(l<=r){
            int mid=(l+r)/2;
            pair<int,int> window=getWindow(mid,s,len);
            if(window!=iniPr){
                r=mid-1;
                if(ans==iniPr)ans=window;
                else{
                    int dif_ans=ans.second-ans.first;
                    int dif_window=window.second-window.first;
                    if(dif_window<dif_ans)ans=window;
                }
            }else{
                l=mid+1;
            }
        }
        string ansS="";
        if(ans!=iniPr){
            for(int i=ans.first;i<=ans.second;i++)ansS+=s[i];
        }
        return ansS;
    }
};