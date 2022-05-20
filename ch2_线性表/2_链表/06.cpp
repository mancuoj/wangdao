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

/***************  2.3.7, 06  ***************/
void sortList(LinkList L, int len) {
  // 1.将链表数据复制到数组中
  LNode* head = L->next;
  int a[len], i = 0;
  while (head != NULL) {
    a[i++] = head->data;
    head = head->next;
  }

  // 2.排序
  sort(a, a + len);

  // 3.将排序后的数组复制回链表
  head = L->next, i = 0;
  while (head != NULL) {
    head->data = a[i++];
    head = head->next;
  }
}

void sortList2(LinkList L) {
  LNode *p = L->next, *pre;
  LNode* q = p->next;
  p->next = NULL;  // 1.构建只有一个结点的有序链表
  p = q;

  // 2.分别查找位置插入
  while (p != NULL) {
    q = p->next;
    pre = L;
    while (pre->next != NULL && pre->next->data < p->data) {
      pre = pre->next;
    }
    p->next = pre->next;
    pre->next = p;
    p = q;
  }
}
/************  22/04/16 Mancuoj  ***********/

int main() {
  vector<int> data{6, 7, 3, 4, 2, 9, 1, 8, 5, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  // sortList(head, 10);
  sortList2(head);

  cout << "修改后: ";
  printList(head);
  return 0;
}
