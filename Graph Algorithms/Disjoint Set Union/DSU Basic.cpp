    struct DSU {
        int n;
        vector<int> rank, parent;
        DSU(int _n) {
            n = _n;
            rank.resize(n);
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 1;
        }

        int find(int x) {
            return (x == parent[x]) ? x : parent[x] = find(parent[x]) ;
        }

        bool unite(int u, int v) {
            u = find(u);
            v = find(v);
            if (u != v) {
                if (rank[u] > rank[v]) swap(u, v);
                rank[v] += rank[u];
                parent[u] = v ;
                return true;
            }
            else return false;
        }
    };
