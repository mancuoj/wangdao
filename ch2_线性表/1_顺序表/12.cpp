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

SqList initList() {
  SqList list;
  list.length = 8;
  // int data[] = {0, 5, 5, 3, 5, 1, 5, 7};
  int data[] = {0, 5, 5, 3, 5, 7, 5, 5};
  for (int i = 0; i < list.length; i++) list.data[i] = data[i];
  return list;
}

/***************  2.2.3, 12  ***************/
int findMain(SqList list) {
  // 1.初始化一个全为0的数组
  int tmp[list.length] = {0};

  // 2.新数组的下标对应元素值，值对应元素个数
  for (int i = 0; i < list.length; i++) {
    tmp[list.data[i]]++;
  }

  // 3.遍历找出主元素
  for (int i = 0; i < list.length; i++) {
    if (tmp[i] > list.length / 2) return i;
  }

  // 4.没找到返回-1
  return -1;
}

int findMain2(SqList list) {
  // 1.排序
  sort(list.data, list.data + list.length);

  // 2.记录每个元素出现的次数，找到主元素
  int cnt = 1;
  for (int i = 0; i < list.length - 1; i++) {
    if (list.data[i + 1] == list.data[i]) {
      cnt++;
    } else {
      if (cnt > list.length / 2) return list.data[i];
      cnt = 1;
    }
  }
  return -1;
}

int findMain3(SqList list) {
  int c, cnt = 1;
  c = list.data[0];

  // 1.选定候选主元素
  for (int i = 1; i < list.length; i++) {
    if (list.data[i] == c)
      cnt++;
    else {
      if (cnt > 0) {
        cnt--;
      } else {
        c = list.data[i];
        cnt = 1;
      }
    }
  }

  // 2.统计实际数量
  if (cnt > 0) {
    cnt = 0;
    for (int i = 0; i < list.length; i++)
      if (list.data[i] == c) cnt++;
  }

  // 3.确认主元素
  if (cnt > list.length / 2) return c;
  return -1;
}
/************  22/04/12 Mancuoj  ***********/

int main() {
  SqList list = initList();
  cout << "原数组: ";
  printList(list);

  cout << "主元素: " << findMain(list) << endl;
  cout << "主元素: " << findMain2(list) << endl;
  cout << "主元素: " << findMain3(list) << endl;
  return 0;
}
