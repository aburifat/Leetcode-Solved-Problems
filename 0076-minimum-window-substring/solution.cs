public class Solution {
    int[] pat;
    int[][] mem;

    private bool ckValid(int l, int r) {
        for(int i = 0; i < 52; i++) {
            if(mem[r][i] - ((l == 0) ? 0 : mem[l-1][i]) < pat[i]) {
                return false;
            }
        }
        return true;
    }

    public string MinWindow(string s, string t) {
        pat = new int[52];
        mem = new int[s.Length][];

        for(int i = 0; i < t.Length; i++) {
            if(t[i] >= 'a' && t[i] <= 'z') {
                pat[t[i] - 'a']++;
            }
            else {
                pat[t[i] - 'A' + 26]++;
            }
        }

        int minLen = s.Length + 1;
        int minStart = 0;

        for(int i = 0; i < s.Length; i++) {
            mem[i] = new int[52];

            if(s[i] >= 'a' && s[i] <= 'z') {
                mem[i][s[i] - 'a']++;
            }
            else {
                mem[i][s[i] - 'A' + 26]++;
            }
            if(i != 0) {
                for(int j = 0; j < 52; j++) {
                    mem[i][j] += mem[i-1][j];
                }
            }

            int l = Math.Max(0, i - minLen), r = i;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if((i - mid + 1 < minLen) && ckValid(mid, i)) {
                    minLen = i - mid + 1;
                    minStart = mid;
                    l = mid + 1;
                }
                else if(i - mid + 1 == minLen){
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        if(minLen == s.Length + 1) return "";
        return s.Substring(minStart, minLen);
    }
}
