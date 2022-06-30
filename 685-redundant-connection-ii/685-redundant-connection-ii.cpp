class Solution {
public:
    vector<int> edge;
    int find(vector<int>& parent, int x){
        if(x==parent[x])
            return x;
        int temp = find(parent,parent[x]);
        parent[x] = temp;
        return temp;
    }
    
    void merge(vector<int>& parent,vector<int>& rank, int x, int y){
        int parx = find(parent,x);
        int pary = find(parent,y);
        
        if(rank[parx]>rank[pary])
            parent[pary] = parx;
        else if(rank[parx]<rank[pary])
            parent[parx] = pary;
        else{
            parent[parx] = pary;
            rank[parx]++;
        }
    }
    
    bool checkDSU(vector<vector<int>>& edges, int n, vector<int>& blacklist){
        vector<int> parent(n+1);
        for(int i=0;i<n+1;i++){
            parent[i] = i;
        }
        vector<int> rank(n+1,1);
        
        for(int i=0;i<edges.size();i++){
            if(blacklist.size()>0 && edges[i]==blacklist)
                continue;
            
            if(find(parent,edges[i][0]) == find(parent,edges[i][1])){
                edge = edges[i];
                return true;
            }
            else
                merge(parent,rank,edges[i][0],edges[i][1]);
        }
        
        return false;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1,-1);
        
        for(int i=0;i<edges.size();i++){
            if(indegree[edges[i][1]]!=-1){
                vector<int> blacklist = edges[i];
                if(checkDSU(edges,n,blacklist))
                    return edges[indegree[edges[i][1]]];
                else
                    return blacklist;
            }else{
                indegree[edges[i][1]] = i;
            }
        }
        
        vector<int> noblacklist;
        checkDSU(edges,n,noblacklist);
        return edge;
    }
};