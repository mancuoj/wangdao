#include <bits/stdc++.h>
using namespace std;

#define maxsize 5
typedef struct {
  int data[maxsize];
  int front, rear, tag;
} Queue;

void initQueue(Queue &Q) { Q.front = Q.rear = Q.tag = 0; }

/***************  3.2.6, 01  ***************/
bool enqueue(Queue &Q, int x) {
  if (Q.front == Q.rear && Q.tag == 1) {
    cout << "队列满" << endl;
    return false;
  }

  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % maxsize;
  Q.tag = 1;
  return true;
}

bool dequeue(Queue &Q, int &x) {
  if (Q.front == Q.rear && Q.tag == 0) {
    cout << "队列空" << endl;
    return false;
  }

  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % maxsize;
  Q.tag = 0;
  return true;
}
/************  22/05/08 Mancuoj  ***********/

int main() {
  Queue Q;
  initQueue(Q);
  enqueue(Q, 1);
  enqueue(Q, 2);
  enqueue(Q, 3);
  enqueue(Q, 4);
  enqueue(Q, 5);
  enqueue(Q, 6);  // 队满
  int x;
  dequeue(Q, x);
  cout << x << endl;  // 1
  dequeue(Q, x);
  cout << x << endl;  // 2
  dequeue(Q, x);
  cout << x << endl;  // 3
  return 0;
}
