#include "Amithi_Bhawsar_project3.h"
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

/* ---------------- Problem 1 ---------------- */
/* Weird Tree Traversal */

vector<int> weird_traversal(TreeNode* root) {
    // If tree is empty, return empty result
    if (!root) return {};

    // Store nodes from even levels
    vector<int> even;

    // Store nodes from odd levels grouped by depth
    vector<vector<int>> odd;

    // Queue for BFS: (node, depth)
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    // Breadth-first traversal
    while (!q.empty()) {
        auto [n, d] = q.front();
        q.pop();

        // Even depth: store directly
        if (d % 2 == 0) {
            even.push_back(n->id);
        }
        // Odd depth: store by level
        else {
            if ((int)odd.size() <= d)
                odd.resize(d + 1);
            odd[d].push_back(n->id);
        }

        // Push children into queue
        for (TreeNode* c = n->first_child; c; c = c->next_sibling) {
            q.push({c, d + 1});
        }
    }

    // Combine results
    vector<int> out = even;

    // Add odd levels from bottom to top, right to left
    for (int d = odd.size() - 1; d >= 1; --d) {
        for (int i = odd[d].size() - 1; i >= 0; --i) {
            out.push_back(odd[d][i]);
        }
    }

    return out;
}

/* ---------------- Problem 2 ---------------- */
/* Bits to Tree */

TreeNode* bits_to_tree(const vector<bool>& bits) {
    int ones = 0, zeros = 0;

    // Validate input bits
    for (bool b : bits) {
        if (b) ones++;
        else zeros++;
        if (zeros > ones) return nullptr;
    }
    if (ones != zeros) return nullptr;

    // Create root node
    TreeNode* root = new TreeNode{0, nullptr, nullptr};

    // Stack to track DFS path
    stack<TreeNode*> st;
    st.push(root);

    int id = 1;

    // Build tree using stack
    for (bool b : bits) {
        if (b) {
            // Create new child node
            TreeNode* parent = st.top();
            TreeNode* node = new TreeNode{id++, nullptr, nullptr};

            // Attach as first child or sibling
            if (!parent->first_child)
                parent->first_child = node;
            else {
                TreeNode* s = parent->first_child;
                while (s->next_sibling)
                    s = s->next_sibling;
                s->next_sibling = node;
            }

            st.push(node);
        } else {
            // Move back up the tree
            if (st.empty()) return nullptr;
            st.pop();
        }
    }

    return root;
}

/* ---------------- Problem 3 ---------------- */
/* Light Post Problem */

pair<int, vector<int>> light_post_problem(
    int n,
    const vector<Edge>& edges,
    const vector<int>& costs
) {
    // Build adjacency list
    vector<vector<int>> g(n);
    for (auto& e : edges) {
        g[e.u].push_back(e.v);
        g[e.v].push_back(e.u);
    }

    // dp[u][0]: light placed at u
    // dp[u][1]: u is covered by child
    // dp[u][2]: u is not covered
    vector<array<int,3>> dp(n);

    vector<int> parent(n, -1);

    // DFS to compute DP values
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

    // Choose best option for root
    int best = min(dp[0][0], dp[0][1]);

    vector<int> res;

    // Reconstruct which nodes have lights
    function<void(int,int)> rec = [&](int u, int state) {
        if (state == 0)
            res.push_back(u);

        for (int v : g[u]) if (v != parent[u]) {
            if (state == 0) {
                int ns = min({dp[v][0], dp[v][1], dp[v][2]});
                if (ns == dp[v][0]) rec(v,0);
                else if (ns == dp[v][1]) rec(v,1);
                else rec(v,2);
            }
            else if (state == 1) {
                if (dp[v][0] <= dp[v][2]) rec(v,0);
                else rec(v,2);
            }
            else {
                rec(v,1);
            }
        }
    };

    rec(0, dp[0][0] <= dp[0][1] ? 0 : 1);
    sort(res.begin(), res.end());

    return {best, res};
}

/* ---------------- Problem 4 ---------------- */
/* Smallest Subset Sum */

vector<pair<unsigned int,string>> smallest_subset_sum(
    unsigned int n,
    unsigned int t,
    const vector<pair<unsigned int, string>>& values
) {
    // dp[i][j] = minimum number of elements to reach sum j using first i items
    vector<vector<int>> dp(n+1, vector<int>(t+1, 1e9));

    // take[i][j] = true if item i is included
    vector<vector<bool>> take(n+1, vector<bool>(t+1, false));

    dp[0][0] = 0;

    // Fill DP table
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

    // Reconstruct subset
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
