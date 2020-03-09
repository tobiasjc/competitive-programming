// from: https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/micro-and-queuequeue-tutorial/

#include <iostream>
using namespace std;
int ms = 100;
int n;
char c;
int q[100];
int f = 0, b = -1, x, s = 0, dq = 0;

inline void enq(int v)
{
        if (s == ms)
                return;

        ++s;
        q[f % ms] = v;
        ++f;

}

inline int deq()
{
        if (s == 0)
                return -1;

        --s;
        return q[++b % ms];

}

int main(int argc, char **argv)
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> n;

        for (int i = 0; i < n; ++i) {
                cin >> c;
                if (c == 'E') {
                        cin >> x;
                        enq(x);
                        cout << s << '\n';
                } else {
                        dq = deq();
                        cout << dq << ' ' << s << '\n';
                }
        }

        return 0;
}
