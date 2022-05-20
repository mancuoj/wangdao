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

/***************  2.2.3, 01  ***************/
int delMin(SqList &list) {
  if (list.length == 0) {
    cout << "Error!" << endl;
    return -1;
  }

  // 1.假设0号元素最小
  int min = list.data[0];
  int pos = 0;

  // 2.循环找出最小元素并记录位置, 从1开始
  for (int i = 1; i < list.length; i++) {
    if (list.data[i] < min) {
      min = list.data[i];
      pos = i;
    }
  }

  // 3.删除最小元素并用最后一个元素替换
  list.data[pos] = list.data[list.length - 1];
  list.length--;

  return min;
}
/************  22/04/07 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  cout << "原数组: ";
  printList(list);

  cout << delMin(list) << endl;

  cout << "修改后: ";
  printList(list);
  return 0;
}
