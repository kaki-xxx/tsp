#include <cmath>
#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <algorithm>

struct dsu {
  std::vector<int> parent;

  dsu(int n) : parent(n) {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int root(int a) {
    if (a == parent[a]) {
      return a;
    } else {
      return parent[a] = root(parent[a]);
    }
  }

  void unite(int a, int b) {
    int ra = root(a);
    int rb = root(b);
    if (ra == rb) {
      return;
    }
    parent[ra] = rb;
  }

  bool same(int a, int b) {
    return root(a) == root(b);
  }
};

struct walk_tree {
  std::vector<int> ans;
  std::vector<bool> visited;
  std::vector<std::vector<int>> adj;

  walk_tree(int n, std::vector<std::vector<int>> _adj) : visited(n), adj(_adj) {}

  void dfs(int v, int p) {
    if (!visited[v]) {
      ans.push_back(v);
      visited[v] = true;
    }
    for (auto n : adj[v]) {
      if (n == p) {
        continue;
      }
      dfs(n, v);
    }
  }
};


int main() {
  int n;
  std::cin >> n;
  std::vector<std::complex<double>> p(n);
  for (int i = 0; i < n; i++) {
    double x, y;
    std::cin >> x >> y;
    std::complex<double> c(x, y);
    p[i] = c;
  }
  std::vector<std::tuple<double, int, int>> edges;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      edges.push_back({std::abs(p[i] - p[j]), i, j});
    }
  }
  dsu d(n);
  std::sort(edges.begin(), edges.end());
  std::vector<std::vector<int>> mst(n);
  for (auto [_, i, j] : edges) {
    if (!d.same(i, j)) {
      mst[i].push_back(j);
      mst[j].push_back(i);
      d.unite(i, j);
    }
  }
  walk_tree wt(n, mst);
  wt.dfs(0, -1);
  std::cout << wt.ans.size() << std::endl;
  for (auto ans_e : wt.ans) {
    std::cout << p[ans_e].real() << " " << p[ans_e].imag() << std::endl;
  }
}
