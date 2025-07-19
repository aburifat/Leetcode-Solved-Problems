package main

import (
	"sort"
)

func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums) // Sort the array to handle duplicates
	result := [][]int{}
	currentSubset := []int{}

	var backtrack func(start int)
	backtrack = func(start int) {
		// Add a copy of the current subset to the result
		temp := make([]int, len(currentSubset))
		copy(temp, currentSubset)
		result = append(result, temp)

		for i := start; i < len(nums); i++ {
			// Skip duplicates: If the current element is the same as the previous one
			// AND it's not the first element being considered at this recursion level (i.e., i > start),
			// then skipping it avoids generating duplicate subsets.
			// Example: For [1,2,2], when processing the second '2' (at index 2) after the first '2' (at index 1)
			// has already been considered in a previous branch (or skipped), we skip this '2'
			// to prevent duplicate subsets like [1,2] from being generated twice.
			if i > start && nums[i] == nums[i-1] {
				continue
			}

			currentSubset = append(currentSubset, nums[i])
			backtrack(i + 1) // Recurse with the next element
			currentSubset = currentSubset[:len(currentSubset)-1] // Backtrack: remove the last element
		}
	}

	backtrack(0)
	return result
}
