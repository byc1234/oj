#include <iostream>
#include <vector>

using namespace std;

template<typename T> 
class PQ {
private :
  vector<T> que;
  int N;
public :
  PQ(int size) {
     que.reserve(size);
     N = 1;
  }

  void insert(T x) {
    que[++N] = x;
    swim(N);
  }

  void push(T n) {
    swim(que.size()-1);
  }

  int less(int a, int b) {
    return que[a] < que[b];
  }
  
  void exch(int a, int b) {
    int tmp = que[a];
    que[a] = que[b];
    que[b] = tmp; 
  }

  void sink(int k) {
    while (2*k <= N) {
       int j = 2*k;
       if (j < N && less(j, j+1)) j++;
       if (!less(k, j)) break;
       exch(k, j);
       k = j;
    }
  }

  void swim(int k) {
    while (k > 1 && less(k/2, k)) {
      exch(k, k/2);
      k = k/2;
    }
  }

  T delMin() {
    T val = pq[1];
    exch(1, N--);
    sink(1);
    pq[N+1] = null;
    return val;
  }

  void pop() {
  }

  T top() {
  }
};


int main() {
  PQ<int> pq(10);
}
