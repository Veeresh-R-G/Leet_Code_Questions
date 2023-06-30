class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<double> prob(n , 0);
        prob[start] = 1;
        // vector<pair<int , int>> adj[n];

        int i = 0;
        // for(auto edge : edges)
        // {
        //     adj[edge[0]].push_back({edge[1] , succProb[i]});
        //     adj[edge[1]].push_back({edge[0] , succProb[i]});
        //     i++;
        // }

        

        for(int i = 0 ; i < n- 1 ; i++)
        {
            bool update = false;
            for(int j = 0 ; j < edges.size() ; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];

                double cur_prob = succProb[j];
                
                //undirected so twice : 
                if(prob[v] < cur_prob * prob[u])
                {
                    prob[v] = cur_prob * prob[u];
                    update = true;
                }

                if(prob[u] < cur_prob * prob[v])
                {
                    prob[u] = cur_prob * prob[v];
                    update = true;
                }

                
            }
            if(!update)
            {
                break;
            }
        }

        return prob[end];
    }
};