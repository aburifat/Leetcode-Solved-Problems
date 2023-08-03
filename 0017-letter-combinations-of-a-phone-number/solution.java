class Solution {
    char[][] mp = new char[][]{
        {},
        {},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'},
    };
    LinkedList<String> res = new LinkedList<>();
    char[] digits;
    char[] curr;

    void goBabe(int idx){
        if(idx==digits.length){
            res.add(new String(curr));
        }else{
            int digit = digits[idx] - '0';
            for(char c : mp[digit]){
                curr[idx] = c;
                goBabe(idx+1);
            }
        }
    }

    public List<String> letterCombinations(String digits) {
        if((digits==null)||(digits.length()==0)){
            return res;
        }
        curr = new char[digits.length()];
        this.digits = digits.toCharArray();
        goBabe(0);
        return res;
    }
}
