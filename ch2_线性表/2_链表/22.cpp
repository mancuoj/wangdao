#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode {
  ElemType data;
  struct LNode* link;
} LNode, *LinkList;

// 创建一个带头结点的单链表
LinkList createHeadList(vector<ElemType> data) {
  if (data.size() == 0) return NULL;

  LNode* head = (LinkList)malloc(sizeof(LNode));
  head->link = NULL;

  LNode* p = head;
  for (int i = 0; i < data.size(); i++) {
    LNode* q = (LNode*)malloc(sizeof(LNode));
    q->data = data[i];
    q->link = NULL;
    p->link = q;
    p = q;
  }
  return head;
}

void printList(LinkList L) {
  while (L->link != NULL) {
    cout << L->link->data << " ";
    L = L->link;
  }
  puts("");
}

/***************  2.3.7, 22  ***************/
int searchK(LinkList L, int k) {
  // 1.获取链表长度n
  int n = 0;
  LNode* p = L->link;
  while (p != NULL) {
    p = p->link;
    n++;
  }

  // 2.没有那么多结点，直接返回0
  if (n < k) return 0;

  // 3.遍历找到第n-k个结点
  int count = n - k;
  p = L->link;
  while (count--) {
    p = p->link;
  }
  cout << "倒数第" << k << "个结点值为" << p->data << endl;
  return 1;
}

int searchK2(LinkList L, int k) {
  // 1.双指针
  LNode *p1 = L->link, *p2 = L->link;

  int count = 0;
  while (p1 != NULL) {
    if (count < k)
      count++;
    else
      p2 = p2->link;  // 2.p1走了k步之后，开始同步走

    p1 = p1->link;  // 3.一直走到链表尾
  }

  // 3.查找成功就输出并返回1
  if (count < k)
    return 0;
  else {
    cout << "倒数第" << k << "个结点值为" << p2->data << endl;
    return 1;
  }
}
/************  22/04/25 Mancuoj  ***********/

int main() {
  vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  searchK(head, 3);
  // searchK(head, 11);
  searchK2(head, 5);
  // searchK2(head, 11);
  return 0;
}
