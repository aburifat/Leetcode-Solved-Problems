class Solution {
    string buttons[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>v;
public:
    void gen(string digits, int idx, string pre=""){
        if(idx>=digits.size())v.push_back(pre);
        else{
            int button=digits[idx]-'0'-2;
            for(int i=0;i<buttons[button].size();i++){
                gen(digits,idx+1,pre+buttons[button][i]);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size())gen(digits,0);
        return v;
    }
};
