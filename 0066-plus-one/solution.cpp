class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
        }
        vector<int>v;
        if(carry)v.push_back(carry);
        for(int i=0;i<digits.size();i++)v.push_back(digits[i]);
        return v;
    }
};
