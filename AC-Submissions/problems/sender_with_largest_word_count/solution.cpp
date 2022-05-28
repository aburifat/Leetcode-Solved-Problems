class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int len=senders.size();
        map<string,int>sendMap;
        //for(int i=0;i<len;i++)sendMap[senders[i]]=i;
        for(int i=0;i<len;i++){
            string line;
            line=messages[i];
            istringstream is(line);
            string message;
            while(is >> message){
                sendMap[senders[i]]++;
            }
        }
        sort(senders.begin(),senders.end());
        //reverse()
        int ct=0;
        string ans="";
        for(int i=0;i<len;i++){
            if(sendMap[senders[i]]>=ct){
                ct=sendMap[senders[i]];
                ans=senders[i];
            }
        }
        return ans;
        
    }
};