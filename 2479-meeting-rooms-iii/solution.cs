public class Solution {
    public int MostBooked(int n, int[][] meetings) {

        Array.Sort(meetings, (a, b) => {
            return a[0].CompareTo(b[0]);
        });

        int[] bookingCount = new int[n];
        PriorityQueue<(long, int),(long, int)> reservedRooms = new PriorityQueue<(long, int),(long, int)>();
        PriorityQueue<int, int> freeRooms = new PriorityQueue<int, int>(Enumerable.Range(0, n).Select(i => (i, i)));

        for(int i = 0; i < meetings.Length; i++)
        {
            long meetingStartTime = meetings[i][0];
            long meetingEndTime = meetings[i][1];

            while (reservedRooms.Count > 0 && reservedRooms.Peek().Item1 <= meetingStartTime)
            {
                int reservedRoom = reservedRooms.Dequeue().Item2;
                freeRooms.Enqueue(reservedRoom, reservedRoom);
            }

            int availableRoom;
            if(freeRooms.Count != 0)
            {
                availableRoom = freeRooms.Dequeue();
            }else
            {
                var (availableTime, nextRoom) = reservedRooms.Dequeue();
                meetingEndTime = availableTime + (meetingEndTime - meetingStartTime);
                meetingStartTime = availableTime;
                availableRoom = nextRoom;
            }

            bookingCount[availableRoom]++;
            
            reservedRooms.Enqueue((meetingEndTime, availableRoom), (meetingEndTime, availableRoom));
        }

        int maxBookingCount = 0;
        int starRoom = -1;

        for(int i=0; i<n; i++)
        {
            if(bookingCount[i] > maxBookingCount)
            {
                maxBookingCount = bookingCount[i];
                starRoom = i;
            }
        }

        return starRoom;
    }
}
