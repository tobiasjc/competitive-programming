// from: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/problem-to-be-linked-with-kmp-tutorial-1/
// Write your code here
#include <iostream>
#include "string.h"
using namespace std;
char p[200005], t[100005];
int f[200005], j = 0;

int n = 0, plen = 0, ans = 0;

int main(int argc, char **argv)
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        cin >> p >> t;
        plen = strlen(p);
        strcat(strcat(p, "$"), t);
        n = strlen(p);

        f[0] = 0;
        for (int i = 1; i < n; i++) {
                j = f[i - 1];

                while (j > 0 && p[i] != p[j])
                        j = f[j - 1];

                if (p[i] == p[j])
                        ++j;
                f[i] = j;
                if (f[i] == plen)
                        ++ans;
        }

        cout << ans << '\n';

        return 0;
}
