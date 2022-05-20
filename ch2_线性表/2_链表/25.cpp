#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct node {
  ElemType data;
  struct node* next;
} NODE, *LinkList;

// 创建一个带头结点的单链表
LinkList createHeadList(vector<ElemType> data) {
  if (data.size() == 0) return NULL;

  NODE* head = (LinkList)malloc(sizeof(NODE));
  head->next = NULL;

  NODE* p = head;
  for (int i = 0; i < data.size(); i++) {
    NODE* q = (NODE*)malloc(sizeof(NODE));
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

/***************  2.3.7, 25  ***************/
void rearrange(NODE* head) {
  NODE *p = head, *q = head, *tmp, *s;

  // 1.快慢指针，找到中间结点
  while (q->next != NULL) {
    p = p->next;
    q = q->next;
    if (q->next != NULL) q = q->next;
  }

  // 2.断链，分成两个链表
  q = p->next;
  p->next = NULL;

  // 3.后一个链表原地逆置，链回去
  while (q != NULL) {
    tmp = q->next;
    q->next = p->next;
    p->next = q;
    q = tmp;
  }

  // 4.拼接两个链表
  s = head->next;
  q = p->next;
  p->next = NULL;

  while (q != NULL) {
    tmp = q->next;
    q->next = s->next;
    s->next = q;
    s = q->next;
    q = tmp;
  }
}
/************  22/04/28 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  rearrange(head);

  cout << "修改后: ";
  printList(head);
  return 0;
}
