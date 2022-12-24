class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        //min possible result
        int l=uniqueCnt1+uniqueCnt2;
        //max possible result
        int r=2*l;
        //initial result
        int ans=r;
        //binary search
        while(l<=r){
            //mid value of l, r
            long long mid=l+(r-l)/2;
            //calculating lcm of divisor1, divisor2
            int gcd=__gcd(divisor1,divisor2);
            long long lcm=divisor1/__gcd(divisor1,divisor2);
            lcm*=(long long)divisor2;
            //count of numbers in range [1,mid] divisible by lcm
            int div_lcm=mid/lcm;
            //count of numbers in range [1,mid] 
            //divisible by divisor1 & not divisible by lcm
            int div1=(mid/divisor1)-div_lcm;
            //count of numbers in range [1,mid] 
            //divisible by divisor2 & not divisible by lcm
            int div2=(mid/divisor2)-div_lcm;
            //rest of the numbers in range [1,mid]
            int other=mid-div1-div2-div_lcm;
            //count of empty space in arr1 after inserting div2 numbers
            int emp_arr1=max(0,uniqueCnt1-div2);
            //count of empty space in arr2 after inserting div1 numbers
            int emp_arr2=max(0,uniqueCnt2-div1);
            //check if it's possible to fullfill all the empty spaces
            //in arr1 and arr2 with the other numbers or not
            if(emp_arr1+emp_arr2<=other){
                //we got a result, let's find a smaller one
                ans=mid;
                r=mid-1;
            }else{
                //not a valid result, let's increase the lower value
                //and check a bigger one
                l=mid+1;
            }
        }
        //return the smallest possible ans
        return ans;
    }
};
