class Solution {
public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<int>> graph1(n);
        std::vector<std::vector<int>> graph2(n);

        for ( const auto& connection : connections ) {
            const auto f = connection[0];
            const auto t = connection[1];

            graph1[f].push_back( t );
            graph2[t].push_back( f );
        }

        int result = 0;

        dfs( graph1, graph2, n, 0, -1 /** prev */, result );

        return result;
    }

private:
    void dfs( std::vector<std::vector<int>>& graph1, std::vector<std::vector<int>>& graph2, const int n, int u, int prev, int& result ) {
        for ( auto v : graph1[u] ) {
            if ( v != prev ) {
                result++;
                dfs( graph1, graph2, n, v, u, result );
            }
        }

        for ( auto v : graph2[u] ) {
            if ( v != prev ) {
                dfs( graph1, graph2, n, v, u, result );
            }
        }
    }
};