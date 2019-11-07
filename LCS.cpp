#include <iostream>
using namespace std;

int n, m, A[1001][1001], a[1000], b[1000];

// recursive reconstruction of LCS
void LCS (int i, int j) {
  if (A[i][j] == 0) return;

  if (a[i - 1] == b[j - 1]) {
    LCS(i - 1, j - 1);
    cout << a[i - 1] << " ";
  } else {
    if (A[i - 1][j] > A[i][j - 1]) {
      LCS(i - 1, j);
    } else {
      LCS(i, j - 1);
    }
  }
}

int main() {
  // read the first sequence
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    A[i][0] = 0;
  }
  
  // read the second sequence
  cin >> m;
  for (int j = 0; j <= m; j++)  {
    cin >> b[j];
    A[0][j] = 0;
  }
  
  // calculate the length of the LCS with recurrent formula
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        A[i][j] = 1 + A[i - 1][j - 1];
      } else {
        A[i][j] = max(A[i - 1][j], A[i][j - 1]);
      }
    }
  }
  
  cout << A[n][m] << endl;
  LCS(n, m);
}
