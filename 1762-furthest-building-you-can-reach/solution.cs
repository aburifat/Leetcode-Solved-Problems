public class Solution {
    public int FurthestBuilding(int[] heights, int bricks, int ladders) {

        PriorityQueue<int,int> pq = new PriorityQueue<int,int>();

        int ans = heights.Length - 1;

        for(int i = 1; i < heights.Length; i++){

            int diff = heights[i] - heights[i-1];

            if(diff > 0){
                bricks -= diff;
                pq.Enqueue(diff, -diff);
            }

            if(bricks < 0){

                if(ladders > 0){
                    
                    bricks += pq.Dequeue();
                    ladders--;
                }else
                {
                    ans = i - 1;
                    break;
                }
            }
        }

        return ans;
    }
}
