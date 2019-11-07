#include <iostream>

using namespace std;

string a, b;
int DP[1001][1001], n, m;

int main() {
  cin >> a >> b;
  
  n = a.size();
  m = b.size();

  for (int i = 0; i <= n; i++) DP[i][0] = i;
  for (int j = 0; j <= m; j++) DP[0][j] = j;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        DP[i][j] = DP[i - 1][j - 1];
      } else {
        DP[i][j] = 1 + min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]);
      }
    }
  }
  
  cout << DP[n][m];
}
