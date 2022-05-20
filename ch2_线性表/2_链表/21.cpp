#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkList;

// 创建一个带头结点的单链表
LinkList createHeadList(vector<ElemType> data) {
  if (data.size() == 0) return NULL;

  LNode *head = (LinkList)malloc(sizeof(LNode));
  head->next = NULL;

  LNode *p = head;
  for (int i = 0; i < data.size(); i++) {
    LNode *q = (LNode *)malloc(sizeof(LNode));
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

/***************  2.3.7, 21  ***************/
bool isLoop(LNode *head) {
  // 1.快慢指针，快的一次走两步
  LNode *fast = head, *slow = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;  // 两指针相遇
  }

  // 2.没有环的情况
  if (slow == NULL || fast->next == NULL) {
    return false;
  }

  return true;
}

LNode *findLoopStart(LNode *head) {
  // 1.快慢指针，快的一次走两步
  LNode *fast = head, *slow = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;  // 两指针相遇
  }

  // 2.没有环的情况，返回NULL
  if (slow == NULL || fast->next == NULL) {
    return NULL;
  }

  // 3.两个指针分别指向头结点和相遇点
  LNode *p1 = head, *p2 = slow;
  while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p1;
}
/************  22/04/24 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);

  // 整个环
  LNode *p = head->next, *s;
  int i = 1;
  while (p->next != NULL) {
    if (i++ == 5) s = p;
    p = p->next;
  }
  p->next = s;

  if (isLoop(head)) puts("有环！");
  p = findLoopStart(head);
  cout << p->data << endl;

  return 0;
}
