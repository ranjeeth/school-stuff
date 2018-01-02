#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
  vector<int> v;
  copy(std::istream_iterator<int>(cin), std::istream_iterator<int>(), back_inserter(v));
  //copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));

  int n = v.size();
  vector<int> dp(v.size());
  for(int i=0; i < dp.size(); ++i) dp[i] = 0;

  // the split is to break the circular nature
  dp[0] = v[0]; dp[1] = max(v[0], v[1]);;
  for(int i=2; i < n-1; ++i) dp[i] = max(dp[i-1], dp[i-2] + v[i]);
  int m0 = dp[n-2];

  dp[0] = 0; dp[1] = v[1];
  for(int i=2; i < n; ++i) dp[i] = max(dp[i-1], dp[i-2] + v[i]);
  int m1 = dp[n-1];

  cout << max(m0, m1) << endl;

}
