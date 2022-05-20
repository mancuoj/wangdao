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
  while (L != NULL) {
    cout << L->data << " ";
    L = L->next;
  }
  puts("");
}

/***************  2.3.7, 08  ***************/
LNode* findCommon(LinkList A, LinkList B) {
  LNode *pa = A->next, *pb = B->next;
  while (pa != NULL) {
    while (pb != NULL) {
      if (pa == pb) return pa;
      pb = pb->next;
    }
    pa = pa->next;
    pb = B->next;  // 重置指针
  }
  return NULL;  // 没找到返回NULL
}

int getLen(LinkList L) {
  int len = 0;
  while (L->next != NULL) {
    L = L->next;
    len++;
  }
  return len;
}

LNode* findCommon2(LinkList A, LinkList B) {
  // 1.计算A, B的长度
  int lenA = getLen(A), lenB = getLen(B);

  // 2.让A, B的长度差距为0
  if (lenA > lenB) {
    for (int i = 0; i < lenA - lenB; i++) A = A->next;
  } else {
    for (int i = 0; i < lenB - lenA; i++) B = B->next;
  }

  // 3.开始比较
  while (A != NULL) {
    if (A == B) return A;
    A = A->next;
    B = B->next;
  }

  // 4.没找到返回NULL
  return NULL;
}
/************  22/04/17 Mancuoj  ***********/

int main() {
  vector<int> dataA{1, 2, 3, 4, 5};
  vector<int> dataB{7, 8, 9};
  LinkList headA = createHeadList(dataA);
  LinkList headB = createHeadList(dataB);
  LNode *p1 = headA->next, *p2 = headB->next;
  while (p1->next != NULL) {
    p1 = p1->next;
  }
  p1->next = p2;

  cout << "链表A: ";
  printList(headA->next);
  cout << "链表B: ";
  printList(headB->next);

  // LNode *common = findCommon(headA, headB);
  LNode* common = findCommon2(headA, headB);
  printList(common);
  return 0;
}
