class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ck = false;
        int len = bits.size();
        for(int i=0;i<len;i++){
            if(i==len-1)ck=true;
            if(bits[i]==1)i++;
        }
        return ck;
    }
};
