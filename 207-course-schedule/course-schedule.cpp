class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        
        vector<int> adj[numCourses];
        vector<int> indeg(numCourses , 0);

        for(auto it : prereq){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }


        queue<int> q;

        vector<int> ans;

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

        return ans.size() == numCourses;



    }
};