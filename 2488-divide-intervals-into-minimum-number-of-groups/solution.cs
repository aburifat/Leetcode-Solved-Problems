public class cmp : IComparer<int[]> {
    public int Compare(int[] a, int[] b) {
        if(a[0] == b[0]) return a[1] < b[1] ? -1 : 1;
        return a[0] < b[0] ? -1 : 1;
    }
}

public class Solution {
    public int MinGroups(int[][] intervals) {
        PriorityQueue<int, int> pq = new PriorityQueue<int, int>();
        Array.Sort(intervals, new cmp());
        int mx = 0;
        int curr = 0;
        for(int i = 0; i < intervals.Length; i++) {
            while(pq.Count > 0 && pq.Peek() < intervals[i][0]) {
                curr--;
                pq.Dequeue();
            }
            curr++;
            if(curr > mx) mx = curr;
            pq.Enqueue(intervals[i][1], intervals[i][1]);
        }
        return mx;
    }
}
