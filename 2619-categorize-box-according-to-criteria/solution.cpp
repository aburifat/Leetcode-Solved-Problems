class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int ck1=0,ck2=0;
        long long volume=(long long)length*(long long)width*(long long)height;
        long long vmax=(long long)1000000000;
        if(length>=10000||width>=10000||height>=10000||volume>=vmax)ck1=1;
        if(mass>=100)ck2=1;
        if(ck1){
            if(ck2)return "Both";
            else return "Bulky";
        }else if(ck2){
            return "Heavy";
        }else{
            return "Neither";
        }
    }
};
