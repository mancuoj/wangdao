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

/***************  2.2.3, 02  ***************/
void reverse(SqList &list) {
  for (int i = 0; i < list.length / 2; i++) {
    swap(list.data[i], list.data[list.length - 1 - i]);
  }
}
/************  22/04/07 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  cout << "原数组: ";
  printList(list);

  reverse(list);

  cout << "修改后: ";
  printList(list);
  return 0;
}
