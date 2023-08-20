class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<int> ans;
        vector<int> indeg(numCourses , 0);
        vector<int> adj[numCourses];
        for(auto it : pre){

            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;

        for(int i = 0 ; i < numCourses ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            auto f = q.front();
            q.pop();

            ans.push_back(f);

            for(auto child : adj[f]){
                indeg[child]--;
                if(indeg[child] == 0){
                    q.push(child);
                }
            }
        }


        if(ans.size() == numCourses){
            return ans;
        }
        return {};
    }
};