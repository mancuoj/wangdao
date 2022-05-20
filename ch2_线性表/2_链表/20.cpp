#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct DNode {
  ElemType data;
  struct DNode *pred, *next;
  int freq;
} DNode, *DLinkList;

// 创建一个带头结点的非循环双链表 DoublyLinkedList
DLinkList createDlist(vector<int> data) {
  if (data.size() == 0) return NULL;

  DNode* head = (DLinkList)malloc(sizeof(DNode));
  head->next = NULL;

  DNode* p = head;
  for (int i = 0; i < data.size(); i++) {
    DNode* q = (DNode*)malloc(sizeof(DNode));
    q->data = data[i];
    q->freq = 0;  // 初始化
    q->next = NULL;
    q->pred = p;  // 前驱
    p->next = q;
    p = q;
  }

  return head;
}

void printList(DLinkList L) {
  DNode* head = L->next;
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  puts("");
}

/***************  2.3.7, 20  ***************/
DNode* locate(DLinkList L, int x) {
  DNode *p = L->next, *q;

  // 1.找到值为x的结点
  while (p != NULL && p->data != x) p = p->next;

  // 2.不存在返回空指针
  if (p == NULL)
    return NULL;
  else {
    // 3.找到该结点时，freq+1
    p->freq++;

    // 4.是第一个元素（freq已经是最大的了）或是freq小于前驱，直接返回
    if (p->pred == L || p->pred->freq > p->freq) return p;

    // 5.取下该结点
    if (p->next != NULL) p->next->pred = p->pred;
    p->pred->next = p->next;

    // 6.顺着该结点的前驱向前找到第一个freq大于它的结点
    q = p->pred;
    while (q != L && q->freq <= p->freq) q = q->pred;

    // 7.找到后插入
    p->next = q->next;
    if (q->next != NULL) q->next->pred = p;
    p->pred = q;
    q->next = p;
  }
  return p;
}
/************  22/04/21 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5};
  DLinkList head = createDlist(data);
  cout << "原链表: ";
  printList(head);

  locate(head, 4);
  cout << "修改后: ";
  printList(head);
  locate(head, 2);
  cout << "修改后: ";
  printList(head);
  locate(head, 2);
  cout << "修改后: ";
  printList(head);
  locate(head, 4);
  cout << "修改后: ";
  printList(head);
  locate(head, 5);
  cout << "修改后: ";
  printList(head);
  return 0;
}
