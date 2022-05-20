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

// 生成一个无序列表, [0, len-1]
SqList initList(int len) {
  srand(time(NULL));
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) list.data[i] = i;

  for (int i = len - 1; i >= 0; i--)
    swap(list.data[i], list.data[rand() % len]);

  return list;
}

/***************  2.2.3, 03  ***************/
void delX(SqList &list, int x) {
  int k = 0;
  for (int i = 0; i < list.length; i++) {
    // 1.把所有要保存的值都放在前面
    if (list.data[i] != x) {
      list.data[k++] = list.data[i];
    }
  }
  // 2.直接扔掉后面的元素
  list.length = k;
}

// 第二种解法: 双指针
void delX2(SqList &list, int x) {
  int i = -1, j = list.length, k = 0;
  while (i < j) {
    while (list.data[++i] != x)
      ;
    while (list.data[--j] == x) k++;
    if (i < j) {
      swap(list.data[i], list.data[j]);
      k++;
    }
  }
  list.length -= k;
}
/************  22/04/07 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  list.data[list.length++] = 1;
  list.data[list.length++] = 1;

  cout << "原数组: ";
  printList(list);

  delX(list, 1);
  // delX2(list, 1);

  cout << "修改后: ";
  printList(list);
  return 0;
}
