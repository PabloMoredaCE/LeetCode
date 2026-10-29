#include <bits/stdc++.h>
using namespace std;

class ST {
    private:
        int n;
        vector<int> st;

    public:
        ST(const vector<int>& arr) {
            n = arr.size();
            st.assign(4 * n, 0);

            if (n > 0) {
                build(1, 0, n - 1, arr);
            }
        }

        int build(int node, int l, int r, const vector<int>& arr) {
            if (l == r) {
                st[node] = arr[l];
                return st[node];
            }

            int mid = l + (r - l) / 2;

            build(node * 2, l, mid, arr);
            build(node * 2 + 1, mid + 1, r, arr);

            st[node] = st[node * 2] ^ st[node * 2 + 1];

            return st[node];
        }

        int update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                st[node] = val;
                return st[node];
            }

            int mid = l + (r - l) / 2;

            if (idx <= mid) {
                update(node * 2, l, mid, idx, val);
            } else {
                update(node * 2 + 1, mid + 1, r, idx, val);
            }

            st[node] = st[node * 2] ^ st[node * 2 + 1];

            return st[node];
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (ql <= l && qr >= r) {
                return st[node];
            }

            if (qr < l || ql > r) {
                return 0;
            }

            int mid = l + (r - l) / 2;

            int lc = query(node * 2, l, mid, ql, qr);
            int rc = query(node * 2 + 1, mid + 1, r, ql, qr);

            return lc ^ rc;
        }
};


class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,vector<string>& queries) {

        // 1. Build adjacency list
        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // 2. BFS: calculate parents and depths
        vector<int> par(n, -1);
        vector<int> depth(n, 0);

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (nei == par[node]) {
                    continue;
                }

                par[nei] = node;
                depth[nei] = depth[node] + 1;

                q.push(nei);
            }
        }

        // 3. DFS: subtree sizes and heavy children
        vector<int> subtreeSize(n, 1);
        vector<int> heavy(n, -1);

        function<void(int)> dfs = [&](int node) {
            int largest = 0;

            for (int nei : adj[node]) {
                if (nei == par[node]) {
                    continue;
                }

                dfs(nei);

                subtreeSize[node] += subtreeSize[nei];

                if (subtreeSize[nei] > largest) {
                    largest = subtreeSize[nei];
                    heavy[node] = nei;
                }
            }
        };

        dfs(0);

        // 4. Heavy-Light Decomposition
        vector<int> head(n, 0);
        vector<int> pos(n, 0);

        int curr = 0;

        function<void(int, int)> dfs2 = [&](int node, int h) {
            head[node] = h;
            pos[node] = curr++;

            if (heavy[node] != -1) {
                dfs2(heavy[node], h);
            }

            for (int nei : adj[node]) {
                if (nei == par[node] || nei == heavy[node]) {
                    continue;
                }

                dfs2(nei, nei);
            }
        };

        dfs2(0, 0);

        // 5. Convert characters into bitmasks
        vector<int> masks(n, 0);

        for (int node = 0; node < n; node++) {
            masks[pos[node]] = 1 << (s[node] - 'a');
        }

        // 6. Initialize segment tree
        ST st(masks);

        // 7. Process queries
        vector<bool> res;

        for (const string& queryStr : queries) {
            stringstream ss(queryStr);

            string operation;
            ss >> operation;

            if (operation == "update") {
                int node;
                char c;

                ss >> node >> c;

                int i = pos[node];
                int nmask = 1 << (c - 'a');

                st.update(1, 0, n - 1, i, nmask);

            } else {
                int a, b;
                ss >> a >> b;

                int xr = 0;

                // Process different heavy chains
                while (head[a] != head[b]) {
                    if (depth[head[a]] < depth[head[b]]) {
                        swap(a, b);
                    }

                    xr ^= st.query(
                        1, 0, n - 1,
                        pos[head[a]], pos[a]
                    );

                    a = par[head[a]];
                }

                // Process remaining path in the same chain
                if (depth[a] > depth[b]) {
                    swap(a, b);
                }

                xr ^= st.query(
                    1, 0, n - 1,
                    pos[a], pos[b]
                );

                // At most one character may have an odd count
                res.push_back(__builtin_popcount(
                    static_cast<unsigned int>(xr)
                ) <= 1);
            }
        }
        return res;
    }
};

        

        