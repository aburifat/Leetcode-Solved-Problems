public class Solution
{
    List<int> primes;
    bool[] isPrime;
    Dictionary<int,int> parent = new();

    private void GetPrimes(int n)
    {
        primes = new(){2};
        isPrime = new bool[n+1];
        Array.Fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 4; i <= n; i += 2)isPrime[i] = false;
        for(int i = 3; i<=n; i+=2)
        {
            if(isPrime[i])
            {
                primes.Add(i);
                if((long) i * i <= n)
                {
                    for(int j = i * i; j <= n; j += i) isPrime[j] = false;
                }
            }
        }
    }

    private List<int> GetPrimeDivisors(int num)
    {
        List<int> divisors = new();
        foreach(int prime in primes)
        {
            if(prime * prime > num) break;
            if(num % prime == 0)
            {
                divisors.Add(prime);
                while(num % prime == 0) num /= prime;
            }
        }
        if(num > 1) divisors.Add(num);
        return divisors;
    }

    private int FindSet(int a)
    {
        if(!parent.ContainsKey(a)) return parent[a] = a;
        if(a == parent[a]) return a;
        return parent[a] = FindSet(parent[a]);
    }

    private void UnionSet(int a, int b)
    {
        a = FindSet(a);
        b = FindSet(b);
        if(a != b)
        {
            parent[b] = a;
        }
    }

    public bool CanTraverseAllPairs(int[] nums)
    {
        if(nums.Length == 1) return true;
        if(nums.Min() == 1) return false;
        GetPrimes(nums.Max());
        for(int i=0;i<nums.Length;i++)
        {
            List<int> divisors = GetPrimeDivisors(nums[i]);
            foreach(int divisor in divisors)
            {
                UnionSet(divisor, nums[i]);
            }
        }

        int currParent = 1;
        bool ck = false;
        for(int i=0; i<nums.Length; i++)
        {
            if(currParent != FindSet(nums[i]))
            {
                if(!ck) ck = !ck;
                else return false;
                currParent = FindSet(nums[i]);
            }
        }
        return ck;
    }
}