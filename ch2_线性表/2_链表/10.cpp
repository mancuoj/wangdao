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

/***************  2.3.7, 10  ***************/
void splitList(LinkList L, LinkList A, LinkList B) {
  // 1.创建工作指针
  LNode *p = L->next, *pa = A, *pb = B;
  int i = 1;

  while (p != NULL) {
    // 2.采用尾插法分别插入
    if (i % 2 != 0) {
      pa->next = p;
      pa = p;
    } else {
      pb->next = p;
      pb = p;
    }
    p = p->next;  // 继续处理
    i++;
  }

  // 3.最后设为空
  pa->next = NULL;
  pb->next = NULL;
}

void splitList2(LinkList L, LinkList A, LinkList B) {
  // 1.创建工作指针
  LNode *p = L->next, *pa = A, *pb = B;

  while (p != NULL) {
    // 2.采用尾插法分别插入
    pa->next = p;
    pa = p;
    p = p->next;  // 继续处理

    if (p != NULL) {
      pb->next = p;
      pb = p;
      p = p->next;  // 继续处理
    }
  }

  // 3.最后设为空
  pa->next = NULL;
  pb->next = NULL;
}
/************  22/04/17 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  LinkList A = (LinkList)malloc(sizeof(LNode));
  LinkList B = (LinkList)malloc(sizeof(LNode));
  A->next = NULL;
  B->next = NULL;
  cout << "原链表: ";
  printList(head);

  // splitList(head, A, B);
  splitList2(head, A, B);

  cout << "A: ";
  printList(A);
  cout << "B: ";
  printList(B);
  return 0;
}
