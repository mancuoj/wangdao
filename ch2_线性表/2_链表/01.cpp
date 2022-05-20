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
void delX(LinkList& L, int x) {
  if (L == NULL) return;  // 1.递归出口
  LNode* p;
  if (L->data == x) {  // 2.L结点的值为x，删除L结点
    p = L;
    L = L->next;
    free(p);
    delX(L, x);
  } else {  // 3.L结点的值不为x，递归处理L结点的下一个结点
    delX(L->next, x);
  }
}
/************  22/04/14 Mancuoj  ***********/

int main() {
  vector<int> data{3, 2, 3, 4, 3, 6, 3, 3, 9, 10};
  LinkList head = createList(data);
  cout << "原链表: ";
  printList(head);

  delX(head, 3);

  cout << "修改后: ";
  printList(head);
  return 0;
}
