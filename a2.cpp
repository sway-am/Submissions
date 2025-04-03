struct DSU {
    vector<int> parent, size, rank;
    bool useSize;
    DSU(int n, bool useSize = true) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        this->useSize = useSize;
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return parent[x] = (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (useSize) {
            if (size[x] < size[y]) {
                parent[x] = y;
                size[y] += size[x];
            } else {
                parent[y] = x;
                size[x] += size[y];
            }
        } else {
            if (rank[x] < rank[y]) {
                parent[x] = y;
            } else if (rank[x] > rank[y]) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};