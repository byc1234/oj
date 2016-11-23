#include <iostream>
#include <vector>

using namespace std;

void update(vector<int> &tree, int idx, int val) {
  for (int i = idx+1; i <= tree.size(); i += i&(-i)) {
     tree[i] += val;
  }
}

vector<int> construct(vector<int> &freq) {
  int n = freq.size();
  vector<int> tree(n+1, 0);
  for (int i = 0; i < n; i++) {
    update(tree, i, freq[i]);
  } 
  return tree;
}

int get(vector<int> &tree, int idx) {
  int sum = 0;
  for (int i = idx+1; i > 0; i -= i&(-i)) {
     sum += tree[i];
  }
  return sum;
}


int main()
{
    int tmp[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(tmp)/sizeof(tmp[0]);
    vector<int> freq(tmp, tmp+n);
    vector<int> BITree = construct(freq);
    cout << "Sum of elements in arr[0..5] is "
         << get(BITree, 5);
 
    // Let use test the update operation
    freq[3] += 6;
    update(BITree, 3, 6); //Update BIT for above change in arr[]
 
    cout << "\nSum of elements in arr[0..5] after update is "
         << get(BITree, 5)
	 << endl;
 
    return 0;
}
