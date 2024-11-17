function fourSum(nums: number[], target: number): number[][] {
    const ans: number[][] = [];
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length - 3; i++) {
        if (i > 0 && nums[i] === nums[i -1]) continue;
        for (let j = i + 1; j < nums.length - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;
            let k = j + 1;
            let l = nums.length - 1;
            const rem = target - nums[i] - nums[j];
            while (k < l) {
                if (nums[k] + nums[l] < rem) {
                    k++;
                }
                else if(nums[k] + nums[l] > rem) {
                    l--;
                }
                else {
                    ans.push([nums[i], nums[j], nums[k], nums[l]]);
                    k++;
                    l--;
                    while (k < l && nums[k] === nums[ k - 1]) k++;
                    while (k < l && nums[l] === nums[l + 1]) l--;
                }
            }
        }
    }
    return ans;
};
