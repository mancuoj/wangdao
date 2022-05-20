#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct DNode {
  ElemType data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

// 创建一个带头结点的循环双链表 CircularDoublyLinkedList
DLinkList createCdlist(vector<int> data) {
  if (data.size() == 0) return NULL;

  DNode* head = (DLinkList)malloc(sizeof(DNode));
  head->next = NULL;

  DNode* p = head;
  for (int i = 0; i < data.size(); i++) {
    DNode* q = (DNode*)malloc(sizeof(DNode));
    q->data = data[i];
    q->next = NULL;
    q->prior = p;  // 前驱
    p->next = q;
    p = q;
  }
  p->next = head;  // 收尾
  head->prior = p;
  return head;
}

void printList(DLinkList L) {
  DNode* head = L->next;
  while (head != L) {
    cout << head->data << " ";
    head = head->next;
  }
  puts("");
}

/***************  2.3.7, 17  ***************/
bool isSymmetry(DLinkList L) {
  // 1.创建两头的指针
  DNode *p = L->next, *q = L->prior;

  // 2.向中间遍历
  while (p != q && p->next != q) {
    if (p->data == q->data) {
      p = p->next;
      q = q->prior;
    } else {
      // 如果有一个值不等则不对称
      return false;
    }
  }

  // 3.循环结束证明对称
  return true;
}
/************  22/04/20 Mancuoj  ***********/

int main() {
  // vector<int> data{1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
  vector<int> data{1, 2, 3, 4, 3, 2, 1};
  DLinkList head = createCdlist(data);
  cout << "原链表: ";
  printList(head);

  if (isSymmetry(head))
    puts("对称!");
  else
    puts("不对称!");
  return 0;
}
