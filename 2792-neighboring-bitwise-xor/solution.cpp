class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int len=(int)derived.size();
        int ck=0;
        for(int i=0;i<len;i++){
            ck^=derived[i];
        }
        if(ck==0)return true;
        else return false;
    }
};
