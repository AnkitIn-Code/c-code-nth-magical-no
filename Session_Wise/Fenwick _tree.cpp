#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    int n;
    vector<long long> bit;
public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int i, long long val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n;
    cin >> n;
    Fenwick ft(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ft.update(i, x);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, val;
            cin >> idx >> val;
            ft.update(idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.rangeQuery(l, r) << endl;
        }
    }
}
