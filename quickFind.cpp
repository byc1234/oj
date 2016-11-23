#include <iostream>
#include <vector>

using namespace std;

struct UF {
  vector<int> id;
  vector<int> size;
  UF(int n) {
    id = vector<int>(n, 0);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; i++) id[i] = i;
  }
  int root(int idx) {
     while (id[idx] != idx) {
       idx = id[idx];
     }
     return idx;
  }
  void merge(int i1, int i2) {
    int ri1 = root(i1);
    int ri2 = root(i2);
    if (ri1 != ri2) {
      if (size[ri1] > size[ri2]) {
        id[ri2] = ri1;
        size[ri1] += size[ri2];
      } else {
        id[ri1] = ri2;
        size[ri2] += size[ri1];
      }
    }
  }
  bool connected(int i1, int i2) {
    return root(i1) == root(i2);
  }
};

int main() {
  UF uf(10);
  uf.merge(4, 3);
  uf.merge(3, 8);
  uf.merge(6, 5);
  uf.merge(9, 4);
  uf.merge(2, 1);
  cout << uf.connected(8, 9) << endl;
  cout << uf.connected(1, 0) << endl;
  uf.merge(5, 0);
  uf.merge(7, 2);
  uf.merge(6, 1);
  cout << uf.connected(1, 0) << endl;
  cout << uf.connected(6, 7) << endl;
}
