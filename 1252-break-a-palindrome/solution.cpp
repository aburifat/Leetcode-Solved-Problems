class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len=palindrome.size();
        if(len<=1)return "";
        bool ck=false;
        for(int i=0,j=len-1;i<j;i++,j--){
            if(palindrome[i]>'a'){
                palindrome[i]='a';
                ck=true;
                break;
            }
        }
        if(!ck){
            palindrome[len-1]='b';
        }
        return palindrome;
    }
};
