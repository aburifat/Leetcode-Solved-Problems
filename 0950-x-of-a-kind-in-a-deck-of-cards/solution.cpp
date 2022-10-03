class Solution {
public:
    bool hasGroupsSizeX(vector<int>& dack) {
        sort(dack.begin(),dack.end());
        int ct=0,gcd=-1;
        for(int i=0;i<dack.size();i++){
            if(i!=0&&dack[i]!=dack[i-1]){
                gcd=(gcd==-1)?ct:__gcd(gcd,ct);
                ct=1;
            }else{
                ct=ct+1;
                if(i==dack.size()-1)gcd=(gcd==-1)?ct:__gcd(gcd,ct);
            }
        }
        return (gcd==1)?false:true;
    }
};
