public class Solution {
    public int FindLeastNumOfUniqueInts(int[] arr, int k) {
        Dictionary<int,int> mp = new Dictionary<int,int>();
        for(int i=0;i<arr.Length;i++){
            if(mp.ContainsKey(arr[i])){
                mp[arr[i]]++;
            }else{
                mp[arr[i]] = 1;
            }
        }
        arr = mp.Values.ToArray();
        Array.Sort(arr);
        int ans = arr.Length;
        for(int i=0;i<arr.Length;i++){
            if(k < arr[i])break;
            k-=arr[i];
            ans--;
        }
        return ans;
    }
}