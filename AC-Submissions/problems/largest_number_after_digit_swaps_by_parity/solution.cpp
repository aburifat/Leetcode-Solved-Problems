class Solution {
public:
    int largestInteger(int num) {
        vector<int>type;
        priority_queue<int,vector<int> >odd,even;
        while(num){
            int dgt=num%10;
            num/=10;
            if(dgt%2==0){
                even.push(dgt);
                type.push_back(0);
            }else{
                odd.push(dgt);
                type.push_back(1);
            }
        }
        int ans=0;
        reverse(type.begin(),type.end());
        for(int i=0;i<type.size();i++){
            ans*=10;
            if(type[i]==0){
                int dgt=even.top();
                even.pop();
                ans+=dgt;
            }else{
                int dgt=odd.top();
                odd.pop();
                ans+=dgt;
            }
        }
        return ans;
    }
};