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

/***************  2.3.7, 03  ***************/
void reversePrintList(LinkList L) {
  if (L == NULL) return;
  reversePrintList(L->next);
  cout << L->data << " ";
}

void reversePrintList2(LinkList L) {
  if (L == NULL) return;

  // 1.遍历存储
  stack<int> stack;
  while (L->next != NULL) {
    stack.push(L->next->data);
    L = L->next;
  }

  // 2.输出
  while (!stack.empty()) {
    cout << stack.top() << " ";
    stack.pop();
  }
}
/************  22/04/14 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  // reversePrintList(head);
  reversePrintList2(head);
  return 0;
}
