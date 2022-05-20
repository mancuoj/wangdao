#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode {
  ElemType data;
  struct LNode* next;
} LNode, *LinkList;

// 创建一个不带头结点的单链表
LinkList createList(vector<int> data) {
  if (data.size() == 0) return NULL;

  LNode* head = (LinkList)malloc(sizeof(LNode));
  head->data = data[0];
  head->next = NULL;

  LNode* p = head;
  for (int i = 1; i < data.size(); i++) {
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

/***************  2.3.7, 01  ***************/
/************  22/04/14 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createList(data);
  cout << "原链表: ";
  printList(head);

  cout << "修改后: ";
  printList(head);
  return 0;
}
