// from: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-monk-and-balanced-parentheses/

#include <iostream>
using namespace std;
int x[200000];
int s[200000];
int top = -1;

int main(int argc, char **argv)
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
                cin >> x[i];

        int ans = 0, size = 0;
        int l = 0, r = 0, w = 0;
        for (int i = 0; i < n; ++i) {
                if (x[i] > 0) {
                        s[++top] = x[i];
                        ++r;
                } else {
                        int w = 0;
                        size = 0;
                        while (top > -1 && i + w < n) {
                                if (s[top--] + x[i + w] == 0) {
                                        size += 2;
                                        ++w;
                                        ++l;
                                } else {
                                        top = -1;
                                        break;
                                }
                        }
                        if (l == r) {
                                ans += size;
                        } else if (size > ans) {
                                ans = size;
                                r = l;
                        }
                }
        }

        cout << ans << '\n';
        return 0;
}

