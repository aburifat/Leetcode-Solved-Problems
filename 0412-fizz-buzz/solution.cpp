class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>s(n);
        for(int i=0;i<n;i++)s[i]=to_string(i+1);
        for(int i=2;i<n;i+=3){
            s[i]="Fizz";
        }
        for(int i=4;i<n;i+=5){
            if((i+1)%3==0)s[i]="FizzBuzz";
            else s[i]="Buzz";
        }
        return s;
    }
};
