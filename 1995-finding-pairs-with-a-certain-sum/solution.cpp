// Include necessary headers
#include <vector>
#include <unordered_map>

class FindSumPairs {
private:
    std::vector<int> nums1_;
    std::vector<int> nums2_;
    std::unordered_map<int, int> nums2_freq_;

public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
        nums1_ = nums1; // Copy nums1
        nums2_ = nums2; // Copy nums2

        // Build frequency map for nums2
        for (int num : nums2_) {
            nums2_freq_[num]++;
        }
    }

    void add(int index, int val) {
        // Decrement frequency of the old value
        int old_val = nums2_[index];
        nums2_freq_[old_val]--;
        // Optional: If frequency becomes 0, remove the key to save space
        // if (nums2_freq_[old_val] == 0) {
        //     nums2_freq_.erase(old_val);
        // }

        // Update the value in nums2
        nums2_[index] += val;
        int new_val = nums2_[index];

        // Increment frequency of the new value
        nums2_freq_[new_val]++;
    }

    int count(int sum) {
        int pair_count = 0;
        // Iterate through nums1
        for (int num1 : nums1_) {
            int target = sum - num1;
            // Check if the target exists in nums2 frequency map
            if (nums2_freq_.count(target)) {
                pair_count += nums2_freq_[target];
            }
        }
        return pair_count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(sum);
 */
