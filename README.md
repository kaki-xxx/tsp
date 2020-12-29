# TSPを総当りと、DP、その他近似解で解いてみたもの

## 説明

brute_force.cpp: 総当りによる解法  
dp.cpp: 動的計画法による解法  
mst.cpp: 最小全域木を使った近似解法

sample/10-cities: 都市数が10のランダムに生成したケース  
sample/17-cities: 都市数が17のランダムに生成したケース  
sample/100-cities: 都市数が100のランダムに生成したケース

graph/10-cities: 都市数が10の場合の最適解(総当りで求めたもの)  
graph/17-cities: 都市数が17の場合の最適解(動的計画法で求めたもの)  
graph/100-cities-mst: 都市数が100の場合の近似解(最小全域木を使った解法で求めたもの)
