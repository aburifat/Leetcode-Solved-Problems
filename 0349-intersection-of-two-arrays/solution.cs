public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        Array.Sort(nums1);
        Array.Sort(nums2);
        int pre = -1;
        List<int> ans = new();
        for(int i = 0, j = 0; i < nums1.Length && j < nums2.Length;)
        {
            while(i < nums1.Length && pre == nums1[i]) i++;

            while(j < nums2.Length && pre == nums2[j]) j++;

            if(i < nums1.Length && j < nums2.Length)
            {
                if(nums1[i] == nums2[j])
                {
                    ans.Add(nums1[i]);
                    pre = nums1[i];
                    i++;
                    j++;
                }
                else if(nums1[i] < nums2[j])
                {
                    i++;
                }
                else{
                    j++;
                }
            }
        }

        return ans.ToArray();
    }
}
