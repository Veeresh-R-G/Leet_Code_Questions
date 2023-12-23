class Solution {

pair<int, int> helper(char direction, pair<int,int>& curr){
    
    switch(direction){
        case 'N':
            return make_pair(curr.first, curr.second + 1);

        case 'E':
            return make_pair(curr.first + 1, curr.second);
        
        case 'S':
            return make_pair(curr.first, curr.second - 1);

        case 'W':
            return make_pair(curr.first - 1, curr.second);
    };

    return {};
}


public:
    bool isPathCrossing(string path) {
        
        pair<int,int>curr = {0 , 0};
        set<pair<int, int>> s;
        s.insert(curr);

        for(auto direction: path){

            auto move = helper(direction, curr);
            if(s.find(move) != s.end()){
                return true;
            }    

            s.insert(move);
            curr = move;
        }

        return false;
    }
};