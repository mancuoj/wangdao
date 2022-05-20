#include <bits/stdc++.h>
using namespace std;

// 栈
#define maxsize 5
typedef struct {
  int stack[maxsize];
  int top;
} Stack;

void initStack(Stack &S) { S.top = -1; }

bool isEmpty(Stack &S) { return S.top == -1; }

bool isFull(Stack &S) { return S.top == maxsize - 1; }

bool push(Stack &S, int x) {
  if (isFull(S)) {
    cout << "栈满" << endl;
    return false;
  }

  S.stack[++S.top] = x;
  return true;
}

bool pop(Stack &S, int &x) {
  if (isEmpty(S)) {
    cout << "栈空" << endl;
    return false;
  }

  x = S.stack[S.top--];
  return true;
}

// 队列
#define maxsize 5
typedef struct {
  int data[maxsize];
  int front, rear;
} Queue;

void initQueue(Queue &Q) { Q.front = Q.rear = 0; }

bool isEmpty(Queue &Q) { return Q.front == Q.rear; }

bool isFull(Queue &Q) { return Q.front == (Q.rear + 1) % maxsize; }

bool enqueue(Queue &Q, int x) {
  if (isFull(Q)) {
    cout << "队列满" << endl;
    return false;
  }

  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % maxsize;
  return true;
}

bool dequeue(Queue &Q, int &x) {
  if (isEmpty(Q)) {
    cout << "队列空" << endl;
    return false;
  }

  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % maxsize;
  return true;
}

/***************  3.2.6, 02  ***************/
void reverseQueue(Queue &Q, Stack &S) {
  int x;
  while (!isEmpty(Q)) {
    dequeue(Q, x);
    push(S, x);
  }

  while (!isEmpty(S)) {
    pop(S, x);
    enqueue(Q, x);
  }
}
/************  22/05/09 Mancuoj  ***********/

int main() {
  Stack S;
  initStack(S);
  Queue Q;
  initQueue(Q);
  enqueue(Q, 1);
  enqueue(Q, 2);
  enqueue(Q, 3);
  enqueue(Q, 4);

  reverseQueue(Q, S);

  // 输出队列元素
  int x;
  while (!isEmpty(Q)) {
    dequeue(Q, x);
    cout << x << " ";
  }
  return 0;
}
