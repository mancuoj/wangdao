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

/***************  2.3.7, 16  ***************/
bool isSubseq(LinkList A, LinkList B) {
  // 1.创建工作指针，p记录每趟比较中的开始结点
  LNode *pa = A->next, *pb = B->next, *p = A->next;

  // 2.遍历
  while (pa != NULL && pb != NULL) {
    if (pa->data == pb->data) {
      pa = pa->next;
      pb = pb->next;
    } else {
      p = p->next;
      pa = p;  // 重新开始一趟比较
      pb = B->next;
    }
  }

  if (pb == NULL) return true;  // 3.如果pb都能匹配上，证明是A的子序列
  return false;
}
/************  22/04/19 Mancuoj  ***********/

int main() {
  vector<int> dataA{1, 2, 4, 5, 6};
  vector<int> dataB{2, 4, 5};
  vector<int> dataC{1, 3, 4};
  LinkList headA = createHeadList(dataA);
  LinkList headB = createHeadList(dataB);
  LinkList headC = createHeadList(dataC);
  cout << "链表A: ";
  printList(headA);
  cout << "链表B: ";
  printList(headB);
  cout << "链表C: ";
  printList(headC);

  if (isSubseq(headA, headB)) puts("B是A的连续子序列");
  if (isSubseq(headA, headC)) puts("C是A的连续子序列");
  return 0;
}
