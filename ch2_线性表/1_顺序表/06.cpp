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

// 插入
void insertList(SqList &list, int idx, int e) {
  if (idx < 1 || idx > list.length + 1) return;
  if (list.length >= MaxSize) return;

  for (int i = list.length; i >= idx; i--) {
    list.data[i] = list.data[i - 1];
  }
  list.data[idx - 1] = e;
  list.length++;
}

// 生成一个有序重复列表, [0, len-1]
SqList initList(int len) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) list.data[i] = i;

  return list;
}

/***************  2.2.3, 06  ***************/
void delSame(SqList &list) {
  if (list.length == 0) return;

  // 1.新开一个数组
  SqList copied = list;
  copied.data[0] = list.data[0];

  // 2.把不同元素存入
  int k = 0;
  for (int i = 1; i < list.length; i++) {
    if (list.data[k] != copied.data[i]) {
      copied.data[++k] = list.data[i];
    }
  }

  // 3.新换旧
  copied.length = k + 1;
  list = copied;
}

void delSame2(SqList &list) {
  if (list.length == 0) return;

  int k = 0;
  for (int i = 1; i < list.length; i++) {
    if (list.data[k] != list.data[i]) {
      list.data[++k] = list.data[i];
    }
  }

  list.length = k + 1;
}
/************  22/04/08 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  insertList(list, 3, 2);
  insertList(list, 3, 2);
  insertList(list, 12, 9);
  insertList(list, 12, 9);
  cout << "原数组: ";
  printList(list);

  delSame2(list);

  cout << "修改后: ";
  printList(list);
  return 0;
}
