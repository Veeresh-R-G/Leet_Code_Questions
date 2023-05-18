class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        //Now why should this approach work ??
        /*
            Ok so if indeg == 0 that node is not reachable from any other node
            other nodes are reachable by atleast one node

            So we have to include the nodes which are unreachable in order to
            cover the whole graph

            Thats why all nodes with indeg == 0 will be included so we can
            include them also 
        */

        vector<int> inDeg(n , 0);

        for(auto edge : edges)
        {
            inDeg[edge[1]]++;
        }

        vector<int> ans;

        for(int i = 0 ; i < inDeg.size() ; i++)
        {
            if(inDeg[i] == 0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};