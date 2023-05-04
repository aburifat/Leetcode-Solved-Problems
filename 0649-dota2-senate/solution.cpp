class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>R,D;
        int len=(int)senate.size();
        for(int i=0;i<len;i++){
            if(senate[i]=='R')R.push(i);
            else D.push(i);
        }
        string ans="Radiant";
        while((!R.empty())&&(!D.empty())){
            if(R.front()<D.front()){
                R.push(len);
            }else D.push(len);
            len++;
            R.pop();
            D.pop();
        }
        if(R.empty())ans="Dire";
        return ans;
    }
};
