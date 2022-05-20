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

/***************  2.3.7, 15  ***************/
void getSame(LinkList A, LinkList B) {
  // 1.创建工作指针
  LNode *pa = A->next, *pb = B->next, *tail = A;

  // 2.同步遍历
  while (pa != NULL && pb != NULL) {
    if (pa->data < pb->data) {
      pa = pa->next;
    } else if (pa->data > pb->data) {
      pb = pb->next;
    } else {
      // 3.找到相等结点就尾插
      tail->next = pa;
      tail = pa;

      pa = pa->next;
      pb = pb->next;
    }
  }
}

void getSame2(LinkList A, LinkList B) {
  LNode *pa = A->next, *pb = B->next, *tail = A, *del;
  while (pa != NULL && pb != NULL) {
    if (pa->data < pb->data) {
      del = pa;
      pa = pa->next;
      free(del);
    } else if (pa->data > pb->data) {
      del = pb;
      pb = pb->next;
      free(del);
    } else {
      tail->next = pa;
      tail = pa;
      pa = pa->next;

      del = pb;
      pb = pb->next;
      free(del);
    }
  }

  // 收尾
  tail->next = NULL;

  // 释放剩余空间
  while (pa != NULL) {
    del = pa;
    pa = pa->next;
    free(del);
  }

  while (pb != NULL) {
    del = pb;
    pb = pb->next;
    free(del);
  }
  free(B);
}
/************  22/04/19 Mancuoj  ***********/

int main() {
  vector<int> dataA{1, 2, 4, 5, 6};
  vector<int> dataB{2, 4, 6, 8, 9};
  LinkList headA = createHeadList(dataA);
  LinkList headB = createHeadList(dataB);
  cout << "链表A: ";
  printList(headA);
  cout << "链表B: ";
  printList(headB);

  // getSame(headA, headB);
  getSame2(headA, headB);
  printList(headA);
  return 0;
}
