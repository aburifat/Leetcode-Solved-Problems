/*
Bezout Identity:
if gcd(a,b)=d,
then,
there exist some values x,y where, ax + by = gcd(a,b) = d

Here,
if gcd(a,b)=1, only then ax + by = 1 is possible.
So, a and b should be co-prime.
To check the property, we can get the gcd of all the values, if there exist
any pair of integers which are co-prime, the result of the gcd of all the
values is 1

*/

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd;
        for(int i=0;i<nums.size();i++){
            if(i==0)gcd=nums[i];
            else{
                gcd=__gcd(gcd,nums[i]);
            }
        }
        return (gcd==1)?true:false;
    }
};
