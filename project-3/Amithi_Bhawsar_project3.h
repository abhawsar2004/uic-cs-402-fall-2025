#ifndef AMITHI_BHAWSAR_PROJECT3
#define AMITHI_BHAWSAR_PROJECT3

#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int id;
    TreeNode* first_child;
    TreeNode* next_sibling;
};

struct Edge {
    int u;
    int v;
};

struct Node {
    int id;
    int cost;
    vector<int> neighbors;
};

vector<int> weird_traversal(TreeNode* root);
TreeNode* bits_to_tree(const vector<bool>& bits);
pair<int, vector<int>> light_post_problem(int n, const vector<Edge>& edges, const vector<int>& 
costs);
vector<pair<unsigned int,string>> smallest_subset_sum(
    unsigned int n,
    unsigned int t,
    const vector<pair<unsigned int, string>>& values
);

#endif

