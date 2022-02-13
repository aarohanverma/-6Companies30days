class Solution {
public:
    
    bool dfsTopoSort(int node, vector<int> adj[], vector<int> &visi,vector<int> &dfsvisi,queue<int> &container){
        visi[node] = 1;
        dfsvisi[node] = 1;

        for(auto i:adj[node]){
            
            // cout << "Node " << i << endl;
            // cout << visi[i] << endl;
            // cout << dfsvisi[i] << endl;
            
            if(visi[i] == -1){
                if(dfsTopoSort(i,adj,visi,dfsvisi,container) == false){
                    return false;
                }
            } else {
                if(dfsvisi[i] != -1){
                    return false;
                }
            }
        }
        
        dfsvisi[node] = -1;
        container.push(node);
        return true;
    }
    
    // DFS toposort
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visi(numCourses+1, -1);
        vector<int> dfsvisi(numCourses+1, -1);
        vector<int> adj[numCourses+1];
        vector<int> res;
        queue<int> container;
        
        for(auto &i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(visi[i] == -1){
                if(dfsTopoSort(i,adj,visi,dfsvisi,container) == false){
                    return res;
                }    
            }
        }
        
        while(!container.empty()){
            int top = container.front();
            res.push_back(top);
            container.pop();
        }
        
        return res;
    }
};
