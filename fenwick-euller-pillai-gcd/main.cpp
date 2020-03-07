#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
ll MAX = 5e5 + 5;
ll MAXV = 1E6 + 5;
ll BIT[1000005];
ll NUMS[1000005];
ll GCDS[500005];
ll PHI[500005];

const ll MOD = 1E9 + 7;
ll inline mod(ll x)
{
        return (x % MOD + MOD) % MOD;
}
void update(ll x, ll n, ll val)
{
        for (; x <= n; x += x & -x) {
                BIT[x] += val;
                //                BIT[x] = mod(BIT[x]);
        }
}

ll query(ll x)
{
        ll sum = 0;
        for (; x > 0; x -= x & -x) {
                sum += BIT[x];
                //              sum = mod(sum);
        }
        return sum;
}

void euler()
{
        for (ll i = 0; i < MAX; i++)
                GCDS[i] = i;

        for (ll i = 2; i < MAX; i++) {
                if (GCDS[i] == i) {
                        for (int j = i; j < MAX; j += i) {
                                GCDS[j] -= GCDS[j] / i;
                                //                            GCDS[j] = mod(GCDS[j]);
                        }
                }
        }
}

void pillai()
{
        for (ll i = 1; i < MAX; i++) {
                for (ll j = i; j < MAX; j += i) {
                        PHI[j] += i * GCDS[j / i];
                        //                  PHI[j] = mod(PHI[j]);
                }
        }
}

int main(int argc, char **argv)
{
        ll n;
        ll q;
        char type;
        ll x, y;
        cin >> n;

        for (ll i = 1; i <= n; i++) {
                cin >> NUMS[i];
                update(i, n, PHI[NUMS[i]]);
        }

        euler();
        pillai();

        memset(BIT, 0, MAXV);
        for (ll i = 1; i <= n; i++)
                update(i, n, PHI[NUMS[i]]);

        cin >> q;

        for (ll z = 0; z < q; z++) {
                cin >> type;
                cin >> x >> y;
                if (type == 'C') {
                        cout << mod(query(y) - query(x - 1)) << endl;
                } else {
                        update(x, n, mod(PHI[y] - PHI[NUMS[x]]));
                        NUMS[x] = y;
                }
        }
        return 0;
}
