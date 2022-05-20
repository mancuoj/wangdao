#include <bits/stdc++.h>
#define ElemType int
#define MaxSize 50

using namespace std;

typedef struct {
  ElemType data[MaxSize];
  int length;
} SqList;

// 打印数组
void printList(SqList list) {
  for (int i = 0; i < list.length; i++) cout << list.data[i] << ' ';
  cout << endl;
}

SqList initList(int len, int d) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) list.data[i] = i + d;

  return list;
}

/***************  2.2.3, 07  ***************/
SqList merge(SqList A, SqList B) {
  SqList C;
  if (A.length + B.length > MaxSize) {
    cout << "ERROR!" << endl;
    return C;
  }

  int i = 0, j = 0, k = 0;
  // 1.两两比较，小的存入结果表
  while (i < A.length && j < B.length) {
    if (A.data[i] <= B.data[j])
      C.data[k++] = A.data[i++];
    else
      C.data[k++] = B.data[j++];
  }

  // 2.剩下的全部加入结果表，两个循环只会有一个运行
  while (i < A.length) C.data[k++] = A.data[i++];
  while (i < B.length) C.data[k++] = B.data[j++];

  // 3.返回结果表
  C.length = k;
  return C;
}
/************  22/04/08 Mancuoj  ***********/

int main() {
  SqList list1 = initList(10, 5);
  SqList list2 = initList(8, 4);

  cout << "原数组1: ";
  printList(list1);
  cout << "原数组2: ";
  printList(list2);

  SqList list = merge(list1, list2);

  cout << "合并后: ";
  printList(list);
  return 0;
}
