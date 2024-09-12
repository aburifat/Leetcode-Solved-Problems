class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bitset<26> cr;

        for(int i = 0; i < allowed.size(); i++) {
            cr[allowed[i] - 'a'] = true;
        }
        int ct = 0;
        for(int idx = 0; idx < words.size(); idx++) {
            bool ck = true;
            for(int i = 0; i < words[idx].size(); i++) {
                if(cr[words[idx][i] - 'a'] == false) {
                    ck = false;
                    break;
                }
            }
            if(ck) ct++;
        }

        return ct;
    }
};
