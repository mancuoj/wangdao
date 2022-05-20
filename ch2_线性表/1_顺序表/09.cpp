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
  int k = 1;
  for (int i = 0; i < len; i++) list.data[i] = i + k++;

  return list;
}

/***************  2.2.3, 09  ***************/
void findX(SqList &list, int x) {
  // 1.循环找x
  int i = -1;
  while (list.data[++i] < x && i < list.length)
    ;

  // 2.找到了就交换
  if (list.data[i] == x) {
    if (i == list.length - 1) {
      // 最后一个元素没有后继，直接返回
      return;
    } else {
      swap(list.data[i], list.data[i + 1]);
      return;
    }
  }

  // 3.没找到就插入
  list.length++;
  for (int j = list.length - 2; j >= i; j--) {
    // i此时指向第一个大于x的元素, 全部后移
    list.data[j + 1] = list.data[j];
  }
  // 插入x
  list.data[i] = x;
}

void findX2(SqList &list, int x) {
  // 1.二分找x
  int low = 0, high = list.length - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (list.data[mid] == x)
      break;
    else if (list.data[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  // 2.找到了
  if (list.data[mid] == x && mid != list.length - 1) {
    swap(list.data[mid], list.data[mid + 1]);
    return;
  }

  // 3.没找到, 此时low>high
  list.length++;
  int i = list.length - 2;
  while (i > high) {
    list.data[i + 1] = list.data[i];
    i--;
  }
  list.data[i + 1] = x;
}
/************  22/04/09 Mancuoj  ***********/

int main() {
  SqList list = initList(10);
  cout << "原数组: ";
  printList(list);

  // findX(list, 5);
  // findX(list, 3);
  // findX(list, 18);
  // findX2(list, 7);
  findX2(list, 14);
  // findX2(list, 21);

  cout << "修改后: ";
  printList(list);
  return 0;
}
