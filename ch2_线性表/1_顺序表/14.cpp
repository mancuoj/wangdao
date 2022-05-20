#include <bits/stdc++.h>
using namespace std;

/***************  2.2.3, 14  ***************/
int findMinDistance(int A[], int B[], int C[], int n1, int n2, int n3) {
  int dmin = INT_MAX, d;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      for (int k = 0; k < n3; k++) {
        // 计算距离
        d = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
        // 更新最小值
        if (d < dmin) dmin = d;
      }
    }
  }
  return dmin;
}

// n1是否是三个数中的最小值
bool findMin(int n1, int n2, int n3) {
  if (n1 <= n2 && n1 <= n3) return true;
  return false;
}

int findMinDistance2(int A[], int B[], int C[], int n1, int n2, int n3) {
  int dmin = INT_MAX, d, i = 0, j = 0, k = 0;
  while (i < n1 && j < n2 && k < n3) {
    // 计算距离
    d = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
    // 更新最小值
    if (d < dmin) dmin = d;

    if (findMin(A[i], B[j], C[k]))
      i++;
    else if (findMin(B[j], C[k], A[i]))
      j++;
    else
      k++;
  }
  return dmin;
}
/************  22/04/12 Mancuoj  ***********/

int main() {
  int A[] = {-1, 0, 9};
  int B[] = {-25, -10, 10, 11};
  int C[] = {2, 9, 17, 30, 41};
  cout << "最小距离: " << findMinDistance(A, B, C, 3, 4, 5) << endl;
  // cout << "最小距离: " << findMinDistance2(A, B, C, 3, 4, 5) << endl;

  return 0;
}
