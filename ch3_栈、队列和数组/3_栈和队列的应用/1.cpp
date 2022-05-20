#include <bits/stdc++.h>
using namespace std;

/***************  3.3.7, 01  ***************/
bool isValid(string str) {
  // 初始化栈
  char stk[str.length()];
  int top = -1, i = 0;

  while (str[i] != '\0') {
    // 左括号直接入栈
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      stk[++top] = str[i];
    }

    // 右括号判断栈顶元素是否对应
    if (str[i] == ')' && stk[top--] != '(') return false;
    if (str[i] == ']' && stk[top--] != '[') return false;
    if (str[i] == '}' && stk[top--] != '{') return false;

    i++;
  }

  if (top == -1) return true;
  return false;
}
/************  22/05/13 Mancuoj  ***********/

int main() {
  // string test = "{[()()]}";
  string test = "[{[]}()[]{[()]}]";
  // string test = "())";
  // string test = "{[()}]";

  if (isValid(test))
    cout << "括号匹配" << endl;
  else
    cout << "括号不匹配" << endl;

  return 0;
}
