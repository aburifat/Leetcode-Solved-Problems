class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size();
        for(int i=0;i<len;i++)gas[i]-=cost[i];
        for(int i=0;i<len;i++)gas.push_back(gas[i]);
        int siz=len*2;
        int ans=-1;
        int sum=0;
        int ct=0;
        for(int i=0;i<siz;i++){
            sum+=gas[i];
            if(sum<0){
                sum=0;
                ct=0;
            }else{
                ct++;
            }
            if(ct>=len){
                ans=i-len+1;
                break;
            }
        }
        return ans;
    }
};