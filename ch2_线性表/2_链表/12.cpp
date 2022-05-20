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

/***************  2.3.7, 12  ***************/
void delSame(LinkList L) {
  LNode *p = L->next, *del;
  while (p->next != NULL) {
    if (p->data == p->next->data) {
      del = p->next;
      p->next = del->next;
      free(del);
    } else {
      p = p->next;
    }
  }
}
/************  22/04/17 Mancuoj  ***********/

int main() {
  vector<int> data{7, 10, 10, 21, 30, 42, 42, 42, 51, 70};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  delSame(head);

  cout << "修改后: ";
  printList(head);
  return 0;
}
