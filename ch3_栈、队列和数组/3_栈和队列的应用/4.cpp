#include <bits/stdc++.h>
using namespace std;

#define maxsize 50
typedef struct {
  int data[maxsize];
  int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue &Q) { Q.front = Q.rear = 0; }

// 判空
bool isEmpty(Queue &Q) { return Q.front == Q.rear; }

// 判满
bool isFull(Queue &Q) { return Q.front == (Q.rear + 1) % maxsize; }

// 入队
bool enqueue(Queue &Q, int x) {
  if (isFull(Q)) {
    cout << "队列满" << endl;
    return false;
  }

  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1) % maxsize;
  return true;
}

// 出队
bool dequeue(Queue &Q, int &x) {
  if (isEmpty(Q)) {
    cout << "队列空" << endl;
    return false;
  }

  x = Q.data[Q.front];
  Q.front = (Q.front + 1) % maxsize;
  return true;
}

/***************  3.3.7, 04  ***************/
void manage(Queue &car, Queue &truck, Queue &all) {
  // 船上车总数，已上客车数量
  int total = 0, cnt = 0, x;

  while (total < 10) {
    if (!isEmpty(car) && cnt < 4) {
      // 1.先上客车，已有四辆就到2，没有客车了就到3
      dequeue(car, x);
      enqueue(all, x);
      total++;
      cnt++;
    } else if (!isEmpty(truck) && cnt == 4) {
      // 2.客车已有四辆上货车，没有货车了就到4
      dequeue(truck, x);
      enqueue(all, x);
      total++;
      cnt = 0;
    } else {
      // 3.以货车代替客车
      while (total < 10 && cnt < 4 && !isEmpty(truck)) {
        dequeue(truck, x);
        enqueue(all, x);
        total++;
        cnt++;
      }
      // 4.清空客车计数
      cnt = 0;
    }

    if (isEmpty(car) && isEmpty(truck)) {
      cout << "不足十辆" << endl;
      break;
    }
  }
}
/************  22/05/14 Mancuoj  ***********/

int main() {
  Queue car, truck, all;
  initQueue(car);
  initQueue(truck);
  initQueue(all);
  enqueue(car, 1);
  enqueue(car, 1);
  enqueue(car, 1);
  enqueue(car, 1);
  enqueue(car, 1);
  enqueue(car, 1);
  enqueue(car, 1);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);
  enqueue(truck, 2);

  manage(car, truck, all);
  int x;
  while (!isEmpty(all)) {
    dequeue(all, x);
    cout << x << ' ';
  }

  return 0;
}
