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

SqList initList(int len, int k) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) list.data[i] = i + k++;

  return list;
}

/***************  2.2.3, 11  ***************/
int merge(SqList A, SqList B) {
  int i = 0, j = 0, k = -1, mid = (A.length + B.length - 1) / 2;

  // 条件也不需要，因为我们找到中间值就会直接return
  while (1) {
    ++k;
    if (A.data[i] <= B.data[j]) {
      if (k == mid) return A.data[i];
      i++;
    } else {
      if (k == mid) return B.data[j];
      j++;
    }
  }
}

int merge2(SqList A, SqList B) {
  int i = 0, j = 0, mid = (A.length + B.length - 1) / 2;
  while (i + j < mid) {
    if (A.data[i] <= B.data[j])
      i++;
    else
      j++;
  }
  return A.data[i] < B.data[j] ? A.data[i] : B.data[j];
}
/************  22/04/11 Mancuoj  ***********/

int main() {
  SqList A = initList(4, 5);
  SqList B = initList(4, 10);
  cout << "原数组A: ";
  printList(A);
  cout << "原数组B: ";
  printList(B);

  // cout << "中位数是: " << merge(A, B) << endl;
  cout << "中位数是: " << merge2(A, B) << endl;
  return 0;
}
