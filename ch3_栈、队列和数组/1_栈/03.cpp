#include <bits/stdc++.h>
using namespace std;

/***************  3.1.5, 03  ***************/
bool isValid(string str) {
  int cnt = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'I') cnt++;
    if (str[i] == 'O') cnt--;

    if (cnt < 0) return false;
  }

  if (cnt == 0) return true;
  return false;
}
/************  22/05/02 Mancuoj  ***********/

int main() {
  // string str = "IOIIOIOO";
  string str = "IOOIOIIO";
  // string str = "IIIOIOIO";
  // string str = "IIIOOIOO";

  if (isValid(str))
    cout << "合法" << endl;
  else
    cout << "不合法" << endl;

  return 0;
}
