#include <bits/stdc++.h>
using namespace std;

/***************  3.3.7, 02  ***************/
void arrange(string &train) {
  // 初始化
  string tmp = train;
  char stk[train.length()];
  int top = -1, cnt = -1;

  for (int i = 0; i < tmp.length(); i++) {
    if (tmp[i] == 'H') {
      stk[++top] = tmp[i];
    }

    // 软座调到前面
    if (tmp[i] == 'S') {
      train[++cnt] = tmp[i];
    }
  }

  while (top != -1) {
    train[++cnt] = stk[top--];
  }
}
/************  22/05/13 Mancuoj  ***********/

int main() {
  string test = "HSHSSHSHSHSH";
  // string test = "HSHSSSSSHHHHSSHHHHHSSS";
  arrange(test);
  cout << test << endl;

  return 0;
}
