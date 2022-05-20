#include <bits/stdc++.h>
using namespace std;

#define maxsize 5
typedef struct {
  int stack[maxsize];
  int top;
} Stack;

// 初始化栈
void initStack(Stack &S) { S.top = -1; }

// 判空
bool isEmpty(Stack &S) { return S.top == -1; }

// 判满
bool isFull(Stack &S) { return S.top == maxsize - 1; }

// 入栈
bool push(Stack &S, int x) {
  if (isFull(S)) {
    cout << "栈满" << endl;
    return false;
  }

  S.stack[++S.top] = x;
  return true;
}

// 出栈
bool pop(Stack &S, int &x) {
  if (isEmpty(S)) {
    cout << "栈空" << endl;
    return false;
  }

  x = S.stack[S.top--];
  return true;
}

/***************  3.1.5, 03  ***************/
/************  22/05/02 Mancuoj  ***********/

int main() {
  Stack S;
  initStack(S);
  int x;
  pop(S, x);  // 栈空
  push(S, 1);
  push(S, 2);
  push(S, 3);
  push(S, 4);
  push(S, 5);
  push(S, 6);  // 栈满
  pop(S, x);
  cout << x << endl;  // 5
  pop(S, x);
  cout << x << endl;  // 4
  pop(S, x);
  cout << x << endl;  // 3
  return 0;
}
