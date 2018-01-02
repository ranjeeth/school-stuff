#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

int longestZigZag(std::vector<int> a) {
  std::vector<int> pre(a.size());
  std::vector<int> len(a.size());
  pre[0] = -1;
  len[0] = 1;
  int longest = 1;
  for(int i=1; i < a.size(); ++i) {
    int max = -1;
    for(int j=i-1; j >= 0; --j) {
      int sign = 1;
      if (j != 0) {
        sign = (a[i] - a[j])*(a[j] - a[pre[j]]);
      } else if (a[i] != a[j]) {
        sign = -1;
      }
      if (sign < 0) {
        if (max < len[j] + 1) {
          max = len[j] + 1;
          pre[i] = j;
        }
      }
    }
    len[i] = max;
    if (longest < len[i]) {
      longest = len[i];
    }
  }
  return longest;
}

int main() {
  std::vector<int> v;
  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(v));
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

  std::cout<< longestZigZag(v) << std::endl;
}
