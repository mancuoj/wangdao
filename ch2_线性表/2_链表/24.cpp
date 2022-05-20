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

/***************  2.3.7, 24  ***************/
void delSameAbsoluteValue(LinkList L, int n) {
  // 1.初始化辅助数组
  int arr[n + 1] = {0};
  LNode *p = L, *del;

  // 2.遍历同时判别
  while (p->link != NULL) {
    int m = abs(p->link->data);  // 获得绝对值

    if (arr[m] == 0) {
      arr[m] = 1;  // 首次出现
      p = p->link;
    } else {
      del = p->link;  // 非首次出现直接删除
      p->link = del->link;
      free(del);
    }
  }
}
/************  22/04/27 Mancuoj  ***********/

int main() {
  vector<int> data{21, -15, -15, -7, 15};
  LinkList head = createHeadList(data);
  cout << "原链表: ";
  printList(head);

  delSameAbsoluteValue(head, 21);

  cout << "修改后: ";
  printList(head);
  return 0;
}
