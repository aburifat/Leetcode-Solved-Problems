package main

// FindSumPairs struct holds the two arrays and a frequency map for nums2.
type FindSumPairs struct {
	nums1     []int
	nums2     []int
	nums2Freq map[int]int
}

// Constructor initializes the FindSumPairs object.
func Constructor(nums1 []int, nums2 []int) FindSumPairs {
	freq := make(map[int]int)
	for _, num := range nums2 {
		freq[num]++
	}
	return FindSumPairs{
		nums1:     nums1,
		nums2:     nums2,
		nums2Freq: freq,
	}
}

// Add adds val to the element at index in nums2 and updates the frequency map.
func (this *FindSumPairs) Add(index int, val int) {
	// Decrement frequency of the old value
	oldVal := this.nums2[index]
	this.nums2Freq[oldVal]--
	// Note: No need to explicitly delete if count becomes 0, map lookup handles it.

	// Update the value in nums2
	this.nums2[index] += val

	// Increment frequency of the new value
	newVal := this.nums2[index]
	this.nums2Freq[newVal]++
}

// Count returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
func (this *FindSumPairs) Count(tot int) int {
	count := 0
	for _, num1 := range this.nums1 {
		target := tot - num1
		// Check if the target exists in the frequency map of nums2
		if freq, ok := this.nums2Freq[target]; ok {
			count += freq
		}
	}
	return count
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * obj := Constructor(nums1, nums2);
 * obj.Add(index,val);
 * param_2 := obj.Count(tot);
 */
