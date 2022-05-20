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

// 生成一个有序列表, [0, len-1]
SqList initList(int len) {
  SqList list;
  list.length = len;
  for (int i = 0; i < len; i++) list.data[i] = i;

  return list;
}

/***************  2.2.3, 04  ***************/
void delSt(SqList &list, int s, int t) {
  if (s >= t || list.length == 0) {
    cout << "ERROR!" << endl;
    return;
  }

  // 1.要保存的值都放在前面
  int k = 0;
  for (int i = 0; i < list.length; i++) {
    if (list.data[i] < s || list.data[i] > t) {
      list.data[k++] = list.data[i];
    }
  }

  // 2.直接扔掉后面的值
  list.length = k;
}

// 第二种解法
void delSt2(SqList &list, int s, int t) {
  if (s >= t || list.length == 0) {
    cout << "ERROR!" << endl;
    return;
  }

  // 1.找到大于等于s的值
  int i = -1;
  while (list.data[++i] < s)
    ;

  // 2.如果全部元素均小于s
  if (i >= list.length) {
    cout << "ERROR!" << endl;
    return;
  }

  // 3.找到大于t的元素
  int j = i - 1;
  while (list.data[++j] <= t)
    ;

  // 4.前移，直接占住被删元素的位置
  while (j < list.length) {
    list.data[i++] = list.data[j++];
  }
  list.length = i;
}
/************  22/04/08 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  cout << "原数组: ";
  printList(list);

  delSt(list, 2, 6);
  // delSt(list, 0, 4);
  // delSt2(list, 8, 9);

  cout << "修改后: ";
  printList(list);
  return 0;
}
