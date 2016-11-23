#include <iostream>

using namespace std;

int main() {
  unsigned int i = 4;
  cout << i - (i & -i) << endl;
}
