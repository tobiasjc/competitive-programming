#include <iostream>
using namespace std;
int one;

main(int argc, char** argv)
{
        one ^= !one;
        int ele = (one << one << one << one) + one + one + one;
        cout << ele * (int)('B') << endl;
}
