class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n , 0);
        //1 --> red
        //-1 --> blue

       
        //for loop for disconnected graph
        for(int i = 0 ; i < n ; i++)
        {

            if(color[i] != 0) continue;

            queue<int> q;

            color[i] = 1;
            q.push(i);
            while(!q.empty())
            {
                int f = q.front();
                q.pop();

                int currColor = color[f];
                // cout << f << " " << currColor << endl;
                for(auto node : graph[f])
                {
                    if(color[node] == 0)
                    {
                        //not colored
                        color[node] = currColor * -1;
                        q.push(node);
                    }

                    else if(color[node] == currColor)
                    {

                        return false;
                    }
                }

            }
        }
       

        return true;

    }
};