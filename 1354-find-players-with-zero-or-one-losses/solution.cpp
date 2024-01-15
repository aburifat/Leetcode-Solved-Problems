class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win,loss;
        set<int>players;
        int n = matches.size();
        for(int i=0;i<n;i++){
            int winner = matches[i][0];
            int looser = matches[i][1];
            players.insert(winner);
            players.insert(looser);
            win[winner]++;
            loss[looser]++;
        }
        vector<vector<int>>champs(2,vector<int>());
        vector<int>semiChamps;
        for(auto player : players){
            if(!loss[player])champs[0].push_back(player);
            else if(loss[player]==1)champs[1].push_back(player);
        }
        return champs;
    }
};
