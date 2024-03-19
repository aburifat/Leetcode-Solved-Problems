public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        int[] ct = new int[26];
        for(int i = 0; i < tasks.Length; i++){
            ct[tasks[i] - 'A']++;
        }
        PriorityQueue<int, int> taskQueue = new();
        for(int i = 0; i < 26; i++){
            if(ct[i] == 0) continue;
            taskQueue.Enqueue(ct[i], -ct[i]);
        }
        int ans = 0;
        while(taskQueue.Count > 0){
            List<int> taken = new();
            int tmpCt = 0;
            for(int i = 0; i <= n; i++){
                if(taskQueue.Count == 0) break;
                int curr = taskQueue.Dequeue();
                if(curr > 1) taken.Add(curr - 1);
                tmpCt++;
            }
            if(taken.Count > 0){
                ans += (n + 1);
            }else{
                ans += tmpCt;
            }
            foreach(int task in taken){
                taskQueue.Enqueue(task, -task);
            }
        }
        return ans;
    }
}
