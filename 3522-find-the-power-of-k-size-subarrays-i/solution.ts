function resultsArray(nums: number[], k: number): number[] {
    let ans : number[] = [nums.length - k + 1];
    let currLen : number = 0;
    let pre : number = 0;
    for (var i = 0; i < nums.length; i++) {
        if (pre + 1 === nums[i]) currLen ++;
        else currLen = 1;
        if (currLen >= k) ans[i - k + 1] = nums[i];
        else ans[i - k + 1] = -1;
        pre = nums[i];
    }
    return ans;
};
