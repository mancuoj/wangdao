#include <bits/stdc++.h>
using namespace std;

/***************  3.1.5, 05  ***************/
#define maxsize 5
typedef struct {
  int stack[maxsize];
  int top1;
  int top2;
} Stack;

// 栈的初始化
void initStack(Stack &S) {
  S.top1 = -1;
  S.top2 = maxsize;
}

// 判断栈空
bool isEmpty(Stack &S, int num) {
  if (num != 1 && num != 2) {
    cout << "栈号输入错误" << endl;
    return false;
  }

  if (num == 1) return S.top1 == -1;
  return S.top2 == maxsize;
}

// 判断栈满
bool isFull(Stack &S) {
  if (S.top2 - S.top1 == 1) return true;
  return false;
}

// 入栈
bool push(Stack &S, int num, int x) {
  if (num != 1 && num != 2) {
    cout << "栈号输入错误" << endl;
    return false;
  }

  if (isFull(S)) {
    cout << "栈满" << endl;
    return false;
  }

  if (num == 1)
    S.stack[++S.top1] = x;
  else
    S.stack[--S.top2] = x;
  return true;
}

// 出栈
bool pop(Stack &S, int num, int &x) {
  if (num != 1 && num != 2) {
    cout << "栈号输入错误" << endl;
    return false;
  }

  if (isEmpty(S, num)) {
    cout << "栈空" << endl;
    return false;
  }

  if (num == 1)
    x = S.stack[S.top1--];
  else
    x = S.stack[S.top2++];
  return true;
}
/************  22/05/04 Mancuoj  ***********/

int main() {
  Stack S;
  initStack(S);
  int x;
  pop(S, 1, x);  // 栈空
  push(S, 1, 10);
  push(S, 1, 11);
  push(S, 1, 12);
  push(S, 2, 49);
  push(S, 2, 50);
  push(S, 2, 51);  // 栈满
  pop(S, 1, x);
  pop(S, 1, x);
  cout << x << endl;  // 11
  pop(S, 2, x);
  cout << x << endl;  // 50

  return 0;
}
