#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <iterator>

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
  std::vector<int> v(n-1);
  for (int i = 0; i < n-1; i++) {
    v[i] = i+1;
  }
  double min_dist = INFINITY;
  std::vector<int> ans(n-1);
  do {
    double distance = 0.;
    int pos = 0;
    for (auto v_e : v) {
      distance += std::abs(p[pos] - p[v_e]);
      pos = v_e;
    }
    distance += std::abs(p[pos] - p[0]);
    if (min_dist > distance) {
      min_dist = distance;
      ans = v;
    }
  } while (std::next_permutation(v.begin(), v.end()));
  std::cout << n << std::endl;
  std::cout << p[0].real() << " " << p[0].imag() << std::endl;
  for (auto ans_e : ans) {
    std::cout << p[ans_e].real() << " " << p[ans_e].imag() << std::endl;
  }
}
