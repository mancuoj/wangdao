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

/***************  2.3.7, 13  ***************/
void headInsert(LinkList L, int num) {
  LNode* node = (LNode*)malloc(sizeof(LNode));
  node->data = num;
  node->next = L->next;
  L->next = node;
}

LinkList mergeList(LinkList A, LinkList B) {
  // 1.创建一个新链表
  LNode* C = (LinkList)malloc(sizeof(LNode));
  C->next = NULL;

  // 2.遍历插入
  LNode *pa = A->next, *pb = B->next, *q;
  while (pa != NULL && pb != NULL) {
    if (pa->data < pb->data) {
      headInsert(C, pa->data);
      pa = pa->next;
    } else {
      headInsert(C, pb->data);
      pb = pb->next;
    }
  }

  // 3.处理剩余元素
  if (pa == NULL) pa = pb;
  while (pa != NULL) {
    headInsert(C, pa->data);
    pa = pa->next;
  }

  return C;
}
/************  22/04/17 Mancuoj  ***********/

int main() {
  vector<int> dataA{1, 3, 5, 7, 9};
  vector<int> dataB{2, 4, 6, 8, 10};
  LinkList headA = createHeadList(dataA);
  LinkList headB = createHeadList(dataB);
  cout << "链表A: ";
  printList(headA);
  cout << "链表B: ";
  printList(headB);

  LinkList C = mergeList(headA, headB);
  printList(C);
  return 0;
}
