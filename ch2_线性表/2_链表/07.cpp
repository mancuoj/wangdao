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

/***************  2.3.7, 07  ***************/
void delRange(LinkList L, int min, int max) {
  LNode *p = L->next, *pre = L;

  while (p != NULL) {
    if (p->data > min && p->data < max) {
      // 在范围内就删除
      pre->next = p->next;
      free(p);
      p = pre->next;
    } else {
      // 不在范围内就继续遍历
      pre = pre->next;
      p = p->next;
    }
  }
}
/************  22/04/16 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  delRange(head, 3, 7);

  cout << "修改后: ";
  printList(head);
  return 0;
}
