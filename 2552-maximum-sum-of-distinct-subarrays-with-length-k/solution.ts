function maximumSubarraySum(nums: number[], k: number): number {
    let map: Map<number, number> = new Map();
    let maxSum: number = 0, start: number = 0;
    for (let i = 0; i < nums.length; i++) {
        const preIdx: number | undefined = map.get(nums[i]);
        if (preIdx != undefined && start <= preIdx)
            start = preIdx + 1;
        map.set(nums[i], i);
        if(i) nums[i] += nums[i - 1];
        if (i - start + 1 >= k)
            maxSum = Math.max(maxSum, i - k >= 0 ? nums[i] - nums[i - k] : nums[i]);
    }
    return maxSum;
};
