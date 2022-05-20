#include <bits/stdc++.h>
using namespace std;

#define maxsize 5
typedef struct {
  int stack[maxsize];
  int top;
} Stack;

void InitStack(Stack &S) { S.top = -1; }

bool StackEmpty(Stack &S) { return S.top == -1; }

bool StackOverflow(Stack &S) { return S.top == maxsize - 1; }

bool Push(Stack &S, int x) {
  if (StackOverflow(S)) {
    cout << "栈满" << endl;
    return false;
  }

  S.stack[++S.top] = x;
  return true;
}

bool Pop(Stack &S, int &x) {
  if (StackEmpty(S)) {
    cout << "栈空" << endl;
    return false;
  }

  x = S.stack[S.top--];
  return true;
}

/***************  3.2.6, 03  ***************/
bool Enqueue(Stack &S1, Stack &S2, int x) {
  if (!StackOverflow(S1)) {
    Push(S1, x);
    return true;
  }

  if (StackOverflow(S1) && !StackEmpty(S2)) {
    cout << "队列满" << endl;
    return false;
  }

  // S1满且S2空，先将S1中的元素全部入S2，再入S1
  while (!StackEmpty(S1)) {
    int tmp;
    Pop(S1, tmp);
    Push(S2, tmp);
  }
  Push(S1, x);
  return true;
}

bool Dequeue(Stack &S1, Stack &S2, int &x) {
  if (!StackEmpty(S2)) {
    Pop(S2, x);
    return true;
  }

  if (StackEmpty(S1)) {
    cout << "队列空" << endl;
    return false;
  }

  // S2为空且S1不为空
  while (!StackEmpty(S1)) {
    int tmp;
    Pop(S1, tmp);
    Push(S2, tmp);
  }
  Pop(S2, x);
  return true;
}

bool QueueEmpty(Stack S1, Stack S2) { return StackEmpty(S1) && StackEmpty(S2); }
/************  22/05/09 Mancuoj  ***********/

int main() {
  Stack S1;
  InitStack(S1);
  Stack S2;
  InitStack(S2);
  Enqueue(S1, S2, 1);
  Enqueue(S1, S2, 2);
  Enqueue(S1, S2, 3);
  Enqueue(S1, S2, 4);
  int x;
  Dequeue(S1, S2, x);
  cout << x << endl;  // 1
  Dequeue(S1, S2, x);
  cout << x << endl;  // 2
  return 0;
}
