#include "Amithi_Bhawsar_project3.h"
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

/* ---------------- Problem 1 ---------------- */

vector<int> weird_traversal(TreeNode* root) {
    if (!root) return {};

    vector<int> even;
    vector<vector<int>> odd;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [n, d] = q.front();
        q.pop();

        if (d % 2 == 0) {
            even.push_back(n->id);
        } else {
            if ((int)odd.size() <= d) odd.resize(d + 1);
            odd[d].push_back(n->id);
        }

        for (TreeNode* c = n->first_child; c; c = c->next_sibling) {
            q.push({c, d + 1});
        }
    }

    vector<int> out = even;
    for (int d = odd.size() - 1; d >= 1; --d) {
        for (int i = odd[d].size() - 1; i >= 0; --i) {
            out.push_back(odd[d][i]);
        }
    }
    return out;
}

/* ---------------- Problem 2 ---------------- */

TreeNode* bits_to_tree(const vector<bool>& bits) {
    int ones = 0, zeros = 0;
    for (bool b : bits) {
        if (b) ones++;
        else zeros++;
        if (zeros > ones) return nullptr;
    }
    if (ones != zeros) return nullptr;

    TreeNode* root = new TreeNode{0, nullptr, nullptr};
    stack<TreeNode*> st;
    st.push(root);
    int id = 1;

    for (bool b : bits) {
        if (b) {
            TreeNode* parent = st.top();
            TreeNode* node = new TreeNode{id++, nullptr, nullptr};
            if (!parent->first_child) parent->first_child = node;
            else {
                TreeNode* s = parent->first_child;
                while (s->next_sibling) s = s->next_sibling;
                s->next_sibling = node;
            }
            st.push(node);
        } else {
            if (st.empty()) return nullptr;
            st.pop();
        }
    }
    return root;
}

/* ---------------- Problem 3 ---------------- */



pair<int, vector<int>> light_post_problem(
    int n,
    const vector<Edge>& edges,
    const vector<int>& costs
) {
    vector<vector<int>> g(n);
    for (auto& e : edges) {
        g[e.u].push_back(e.v);
        g[e.v].push_back(e.u);
    }

    vector<array<int,3>> dp(n);
    vector<int> parent(n, -1);

    function<void(int)> dfs = [&](int u) {
        dp[u] = {costs[u], 0, 0};
        for (int v : g[u]) if (v != parent[u]) {
            parent[v] = u;
            dfs(v);
            dp[u][0] += min({dp[v][0], dp[v][1], dp[v][2]});
            dp[u][1] += min(dp[v][0], dp[v][2]);
            dp[u][2] += dp[v][1];
        }
    };

    dfs(0);
    int best = min(dp[0][0], dp[0][1]);

    vector<int> res;
    function<void(int,int)> rec = [&](int u, int state) {
        if (state == 0) res.push_back(u);
        for (int v : g[u]) if (v != parent[u]) {
            if (state == 0) {
                int ns = min({dp[v][0], dp[v][1], dp[v][2]});
                if (ns == dp[v][0]) rec(v,0);
                else if (ns == dp[v][1]) rec(v,1);
                else rec(v,2);
            } else if (state == 1) {
                if (dp[v][0] <= dp[v][2]) rec(v,0);
                else rec(v,2);
            } else {
                rec(v,1);
            }
        }
    };

    rec(0, dp[0][0] <= dp[0][1] ? 0 : 1);
    sort(res.begin(), res.end());
    return {best, res};
}

/* ---------------- Problem 4 ---------------- */

vector<pair<unsigned int,string>> smallest_subset_sum(
    unsigned int n,
    unsigned int t,
    const vector<pair<unsigned int, string>>& values
) {
    vector<vector<int>> dp(n+1, vector<int>(t+1, 1e9));
    vector<vector<bool>> take(n+1, vector<bool>(t+1, false));

    dp[0][0] = 0;

    for (unsigned int i = 1; i <= n; ++i) {
        for (unsigned int j = 0; j <= t; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= values[i-1].first &&
                dp[i-1][j - values[i-1].first] + 1 < dp[i][j]) {
                dp[i][j] = dp[i-1][j - values[i-1].first] + 1;
                take[i][j] = true;
            }
        }
    }

    vector<pair<unsigned int,string>> out;
    unsigned int j = t;

    for (int i = n; i > 0; --i) {
        if (take[i][j]) {
            out.push_back({i-1, values[i-1].second});
            j -= values[i-1].first;
        }
    }

    reverse(out.begin(), out.end());
    return out;
}


int main() {
    return 0;
}


