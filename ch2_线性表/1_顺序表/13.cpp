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
  list.length = 5;
  int data[] = {-5, 3, 4, 3, 4};
  // int data[] = {1, 2, -3, -3, -5};
  for (int i = 0; i < list.length; i++) list.data[i] = data[i];
  return list;
}

/***************  2.2.3, 13  ***************/
int findMissMin(SqList list) {
  // 1.初始化一个全为0的数组
  int tmp[list.length] = {0};

  // 2.下标对应元素值，值对应元素是否出现
  for (int i = 0; i < list.length; i++) {
    if (list.data[i] > 0 && list.data[i] <= list.length) tmp[list.data[i]]++;
  }

  // 3.找到最小正整数
  int i;
  for (i = 1; i <= list.length; i++) {
    if (tmp[i] == 0) return i;
  }
  return i;
}
/************  22/04/12 Mancuoj  ***********/

int main() {
  SqList list = initList();
  cout << "原数组: ";
  printList(list);

  cout << "未出现的最小正整数: " << findMissMin(list) << endl;
  return 0;
}
