

The idea is from Ugly Number II. https://leetcode.com/problems/ugly-number-ii/ Below code is for ugly number II

public int nthUglyNumber(int n){
    int i2=0, i3=0, i5=0;
    int[] k = new int[n];
    k[0] = 1;
    for (int i=1; i<n; i++) {
        k[i] = Math.min(k[i2]*2, Math.min(k[i3]*3, k[i5]*5));
        if (k[i]%2 == 0) i2++;
        if (k[i]%3 == 0) i3++;
        if (k[i]%5 == 0) i5++;
    }

    return k[n-1];
}
Similarly, for this problem, just use loop to replace above i2, i3, i5.


public int nthSuperUglyNumber(int n, int[] primes) {
    int len = primes.length;
    int[] index = new int[len]; //index[0]==0, ... index[len-1]==0
    int[] res = new int[n];
    res[0] = 1;
    for(int i=1; i<n; i++) {
        int min = Integer.MAX_VALUE;
        for(int j=0; j<len; j++){
            min = Math.min(res[index[j]]*primes[j], min);
        }
        res[i] = min;
        for (int j=0; j<len; j++) {
            if(res[i]%primes[j]==0) index[j]++;
        }

    }

    return res[n-1];
}



    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0]=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
            for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
        }
        return ugly[n-1];
    }

public int nthSuperUglyNumberHeap(int n, int[] primes) {
    int[] ugly = new int[n];

    PriorityQueue<Num> pq = new PriorityQueue<>();
    for (int i = 0; i < primes.length; i++) pq.add(new Num(primes[i], 1, primes[i]));
    ugly[0] = 1;

    for (int i = 1; i < n; i++) {
        ugly[i] = pq.peek().val;
        while (pq.peek().val == ugly[i]) {
            Num nxt = pq.poll();
            pq.add(new Num(nxt.p * ugly[nxt.idx], nxt.idx + 1, nxt.p));
        }
    }

    return ugly[n - 1];
}

private class Num implements Comparable<Num> {
    int val;
    int idx;
    int p;

    public Num(int val, int idx, int p) {
        this.val = val;
        this.idx = idx;
        this.p = p;
    }

    @Override
    public int compareTo(Num that) {
        return this.val - that.val;
    }
}

