public class Solution
{
    public IList<int> FindAllPeople(int n, int[][] meetings, int firstPerson)
    {
        Array.Sort(meetings, (a,b) => a[2].CompareTo(b[2]));

        bool[] secretHolder = new bool[n];
        secretHolder[0] = secretHolder[firstPerson] = true;
        var meetingTimes = meetings.Select(meeting => meeting[2])
                                    .Distinct()
                                    .OrderBy(meetingTime => meetingTime)
                                    .ToList();
        
        int idx = 0;
        int endIdx = meetings.Length;
        foreach(var currTime in meetingTimes)
        {
            Dictionary<int,List<int>> adj = new();
            bool[] visited = new bool[n];
            Queue<int> q = new();

            while(idx < meetings.Length)
            {
                var meeting = meetings[idx];
                if(meeting[2] > currTime)break;

                if(!secretHolder[meeting[0]] && !secretHolder[meeting[1]])
                {
                    if(!adj.ContainsKey(meeting[0]))adj[meeting[0]] = new List<int>();
                    if(!adj.ContainsKey(meeting[1]))adj[meeting[1]] = new List<int>();
                    adj[meeting[0]].Add(meeting[1]);
                    adj[meeting[1]].Add(meeting[0]);
                    visited[meeting[0]] = visited[meeting[1]] = false;
                }
                else if(!secretHolder[meeting[0]] || !secretHolder[meeting[1]])
                {
                    if(secretHolder[meeting[0]]) q.Enqueue(meeting[1]);
                    else q.Enqueue(meeting[0]);

                    visited[meeting[0]] = visited[meeting[1]] = true;
                    secretHolder[meeting[1]] = secretHolder[meeting[0]] = true;
                }

                idx++;
            }

            while(q.Count > 0)
            {
                int curr = q.Dequeue();

                if(!adj.ContainsKey(curr))continue;

                foreach(var people in adj[curr])
                {
                    if(!visited[people])
                    {
                        secretHolder[people] = true;
                        visited[people] = true;
                        q.Enqueue(people);
                    }
                }
            }

        }

        return Enumerable.Range(0,n)
                        .Where(index => secretHolder[index])
                        .ToList();

    }
}