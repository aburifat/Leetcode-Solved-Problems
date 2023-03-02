class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        vector<char>ch;
        vector<int>ct;
        for(int i=0;i<len;i++){
            if(i!=0&&chars[i]==chars[i-1])ct[(int)ct.size()-1]++;
            else{
                ch.push_back(chars[i]);
                ct.push_back(1);
            }
        }
        chars.clear();
        for(int i=0;i<(int)ch.size();i++){
            chars.push_back(ch[i]);
            if(ct[i]<=1){
                continue;
            }
            vector<int>num;
            while(ct[i]){
                num.push_back(ct[i]%10);
                ct[i]/=10;
            }
            for(int i=(int)num.size()-1;i>=0;i--){
                chars.push_back(num[i]+'0');
            }
        }
        return (int)chars.size();
    }
};
