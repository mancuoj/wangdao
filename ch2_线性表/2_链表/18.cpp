#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode {
  ElemType data;
  struct LNode* next;
} LNode, *LinkList;

// 创建一个带头结点的循环单链表
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

  p->next = head;  // 最后指向头指针
  return head;
}

void printList(LinkList L) {
  LNode* head = L->next;
  while (head != L) {
    cout << head->data << " ";
    head = head->next;
  }
  puts("");
}

/***************  2.3.7, 18  ***************/
void linkTwoLists(LinkList h1, LinkList h2) {
  // 1.创建工作指针
  LNode *p1 = h1->next, *p2 = h2->next;

  // 2.找到h1的尾结点
  while (p1->next != h1) {
    p1 = p1->next;
  }

  // 3.链接h2
  p1->next = p2;

  // 4.找到h2的尾结点，指向h1
  while (p2->next != h2) {
    p2 = p2->next;
  }
  p2->next = h1;
}
/************  22/04/20 Mancuoj  ***********/

int main() {
  vector<int> dataA{1, 2, 4, 5, 6};
  vector<int> dataB{2, 4, 6, 8, 9};
  LinkList headA = createHeadList(dataA);
  LinkList headB = createHeadList(dataB);
  cout << "链表A: ";
  printList(headA);
  cout << "链表B: ";
  printList(headB);

  linkTwoLists(headA, headB);

  cout << "修改后: ";
  printList(headA);
  return 0;
}
