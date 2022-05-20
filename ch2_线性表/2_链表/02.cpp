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

/***************  2.3.7, 02  ***************/
void delX(LinkList L, int x) {
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

void delX2(LinkList L, int x) {
  LNode *pre = L, *p = L->next, *q;
  while (p != NULL) {
    if (p->data == x) {
      q = p;
      p = p->next;
      pre->next = p;
      free(q);
    } else {
      pre = p;
      p = p->next;
    }
  }
}
/************  22/04/14 Mancuoj  ***********/

int main() {
  vector<int> data{3, 2, 3, 4, 3, 6, 3, 3, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  // delX(head->next, 3);
  delX2(head, 3);

  cout << "修改后: ";
  printList(head);
  return 0;
}
