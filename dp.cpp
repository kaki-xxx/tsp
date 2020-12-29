#include <cmath>
#include <iostream>
#include <vector>
#include <complex>

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
  std::vector<std::vector<double>> dp(1<<n, std::vector<double>(n, INFINITY));
  std::vector<std::vector<std::pair<int, int>>> prev(1<<n, std::vector<std::pair<int, int>>(n, std::pair<int, int>(0, 0)));
  dp[0][0] = 0.;
  for (int bit = 0; bit < (1<<n); bit++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (bit & (1<<i)) {
          continue;
        }
        if (dp[bit|(1<<i)][i] > dp[bit][j] + std::abs(p[j] - p[i])) {
          dp[bit|(1<<i)][i] = dp[bit][j] + std::abs(p[j] - p[i]);
          prev[bit|(1<<i)][i] = std::pair<int, int>(bit, j);
        }
      }
    }
  }
  std::vector<int> ans;
  ans.push_back(0);
  std::pair<int, int> pos = prev[(1<<n)-1][0];
  while (pos.second != 0) {
    ans.push_back(pos.second);
    pos = prev[pos.first][pos.second];
  }
  ans.push_back(0);
  std::cout << ans.size() << std::endl;
  for (auto ans_e : ans) {
    std::cout << p[ans_e].real() << " " << p[ans_e].imag() << std::endl;
  }
}
