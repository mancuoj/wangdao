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

SqList initList(int len) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) list.data[i] = i;

  return list;
}

/***************  2.2.3, 08  ***************/
void change(SqList &list, int m, int n) {
  // 前一个线性表[0, m-1], 后一个[m, m+n-1]
  SqList copied = list;
  int k = -1;
  for (int i = m; i < m + n; i++) {
    copied.data[++k] = list.data[i];
  }
  for (int i = 0; i < m; i++) {
    copied.data[++k] = list.data[i];
  }
  list = copied;
}

// 逆置，跟第二题类似, l=left, r=right
void reverse(SqList &list, int l, int r) {
  if (l > r || r > list.length) return;

  int mid = (l + r) / 2;
  // 注意边界
  for (int i = 0; i <= mid - l; i++) {
    swap(list.data[l + i], list.data[r - i]);
  }
}

void change2(SqList &list, int m, int n) {
  // 注意参数
  reverse(list, 0, m + n - 1);
  reverse(list, 0, n - 1);
  reverse(list, n, m + n - 1);
}
/************  22/04/09 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  cout << "原数组: ";
  printList(list);

  // change(list, 5, 5);
  // reverse(list, 0, list.length - 1);
  change2(list, 5, 5);

  cout << "修改后: ";
  printList(list);
  return 0;
}
