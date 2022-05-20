#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode {
  ElemType data;
  struct LNode* next;
} LNode, *LinkList;

// 创建一个带头结点的单链表
LinkList createHeadList(vector<ElemType> data) {
  if (data.size() == 0) return NULL;

  LNode* head = (LinkList)malloc(sizeof(LNode));
  head->next = NULL;

  LNode* p = head;
  for (int i = 0; i < data.size(); i++) {
    LNode* q = (LNode*)malloc(sizeof(LNode));
    q->data = data[i];
    q->next = NULL;
    p->next = q;
    p = q;
  }
  return head;
}

void printList(LinkList L) {
  while (L->next != NULL) {
    cout << L->next->data << " ";
    L = L->next;
  }
  puts("");
}

/***************  2.3.7, 14  ***************/
LinkList getSame(LinkList A, LinkList B) {
  // 1.创建链表和指针
  LNode* C = (LinkList)malloc(sizeof(LNode));
  C->next = NULL;
  LNode *tail = C, *pa = A->next, *pb = B->next, *node;

  // 2.同步遍历
  while (pa != NULL && pb != NULL) {
    if (pa->data < pb->data) {
      pa = pa->next;
    } else if (pa->data > pb->data) {
      pb = pb->next;
    } else {
      // 3.相等就尾插进新链表
      node = (LNode*)malloc(sizeof(LNode));
      node->data = pa->data;
      tail->next = node;
      tail = node;

      // 4.继续向后扫描
      pa = pa->next;
      pb = pb->next;
    }
  }

  return C;
}
/************  22/04/17 Mancuoj  ***********/

int main() {
  vector<int> dataA{1, 2, 4, 5, 6};
  vector<int> dataB{2, 4, 6, 8, 9};
  LinkList headA = createHeadList(dataA);
  LinkList headB = createHeadList(dataB);
  cout << "链表A: ";
  printList(headA);
  cout << "链表B: ";
  printList(headB);

  LinkList C = getSame(headA, headB);
  printList(C);
  return 0;
}
