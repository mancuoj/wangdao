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

/***************  2.3.7, 09  ***************/
void delMin(LinkList L) {
  // 1.只剩一个头结点时停止
  while (L->next != NULL) {
    LNode *minpre = L, *p = L->next;

    // 2.找到最小值，记录其前缀
    while (p->next != NULL) {
      if (p->next->data < minpre->next->data) minpre = p;
      p = p->next;
    }

    // 3.输出并释放最小值结点
    cout << minpre->next->data << ' ';
    LNode* del = minpre->next;
    minpre->next = del->next;
    free(del);
  }

  // 4.释放头结点
  free(L);
}
/************  22/04/17 Mancuoj  ***********/

int main() {
  vector<int> data{6, 7, 3, 4, 2, 9, 1, 8, 5, 10};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  delMin(head);
  return 0;
}
