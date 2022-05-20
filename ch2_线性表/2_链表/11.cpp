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

/***************  2.3.7, 11  ***************/
void splitList(LinkList L, LinkList A, LinkList B) {
  // 1.创建工作指针
  LNode *p = L->next, *pa = A;
  int i = 1;

  while (p != NULL) {
    // 2.分别采用头插法和尾插法插入
    if (i % 2 != 0) {
      pa->next = p;
      pa = p;
      p = p->next;
    } else {
      LNode* q = p->next;  // 记录p的后继防止断链
      p->next = B->next;
      B->next = p;
      p = q;
    }
    i++;
  }

  // 3.收尾
  pa->next = NULL;
}

void splitList2(LinkList L, LinkList A, LinkList B) {
  // 1.创建工作指针
  LNode *p = L->next, *pa = A;

  while (p != NULL) {
    // 2.分别采用头插法和尾插法插入
    pa->next = p;
    pa = p;
    p = p->next;

    if (p != NULL) {
      LNode* q = p->next;  // 记录p的后继防止断链
      p->next = B->next;
      B->next = p;
      p = q;
    }
  }

  // 3.收尾
  pa->next = NULL;
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
