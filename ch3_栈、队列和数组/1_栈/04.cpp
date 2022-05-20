#include <bits/stdc++.h>
#define ElemType char
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

/***************  3.1.5, 04  ***************/
bool isSymmetry(LinkList L, int n) {
  char stk[n / 2];  // 字符栈
  LNode* p = L->next;

  // 1.存入链表前一半的元素
  for (int i = 0; i < n / 2; i++) {
    stk[i] = p->data;
    p = p->next;
  }

  // 2.如果链表元素个数为奇数，则中间元素不用比较
  if (n % 2 == 1) p = p->next;

  // 3.对比后半部分
  for (int i = n / 2 - 1; i >= 0; i--) {
    if (stk[i] != p->data) return false;
    p = p->next;
  }
  return true;
}
/************  22/05/03 Mancuoj  ***********/

int main() {
  vector<char> data{'x', 'y', 'x'};
  // vector<char> data{'x', 'y', 'y', 'x'};
  LinkList head = createHeadList(data);

  if (isSymmetry(head, 3)) cout << "中心对称" << endl;
  // if (isSymmetry(head, 4)) cout << "中心对称" << endl;
  return 0;
}
