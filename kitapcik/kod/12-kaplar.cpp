#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
  stack<int> yigin;               // ilk giren son çıkar
  queue<int> kuyruk;              // ilk giren ilk çıkar
  priority_queue<int> oncelik;    // en büyük önce çıkar

  for (int s : {3, 1, 4, 1, 5}) {
    yigin.push(s); kuyruk.push(s); oncelik.push(s);
  }

  cout << "yığın  : "; while (!yigin.empty())   { cout << yigin.top()   << " "; yigin.pop(); }
  cout << "\nkuyruk : "; while (!kuyruk.empty()) { cout << kuyruk.front() << " "; kuyruk.pop(); }
  cout << "\nöncelik: "; while (!oncelik.empty()){ cout << oncelik.top() << " "; oncelik.pop(); }
  cout << endl;
  return 0;
}
