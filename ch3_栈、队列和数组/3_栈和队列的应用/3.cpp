#include <bits/stdc++.h>
using namespace std;

/***************  3.3.7, 03  ***************/
// 栈
double calc(int n, double x) {
  struct stack {
    int num;
    double val;
  } stk[n + 1];
  int top = -1;

  double f1 = 1, f2 = 2 * x;
  for (int i = n; i >= 2; i--) {
    stk[++top].num = i;
  }

  // 从n=2开始一路向后算，每次记录前两个值即可
  while (top != -1) {
    stk[top].val = 2 * x * f2 - 2 * (stk[top].num - 1) * f1;
    f1 = f2;
    f2 = stk[top].val;
    top--;
  }

  if (n == 0) return f1;
  return f2;
}

// 数组
double calc2(int n, double x) {
  double nums[n + 1];
  nums[0] = 1;
  nums[1] = 2 * x;

  if (n <= 1) {
    return nums[n];
  }

  for (int i = 2; i <= n; i++) {
    nums[i] = 2 * x * nums[i - 1] - 2 * (i - 1) * nums[i - 2];
  }
  return nums[n];
}
/************  22/05/13 Mancuoj  ***********/

int main() {
  cout << calc(0, 2) << endl;  // 1
  cout << calc(1, 2) << endl;  // 4
  cout << calc(2, 2) << endl;  // 14
  cout << calc(3, 2) << endl;  // 40

  cout << calc2(0, 2) << endl;
  cout << calc2(1, 2) << endl;
  cout << calc2(2, 2) << endl;
  cout << calc2(3, 2) << endl;
  return 0;
}
