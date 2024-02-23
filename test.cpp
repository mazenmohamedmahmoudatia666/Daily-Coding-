#include <iostream>
using namespace std;
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <cassert>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <string.h>
#define ll long long
#define PI 3.14
#define Ye cout << "YES"
#define ye cout << "yes"
#define Ne cout << "NO"
#define ne cout << "no"
#define ln "\n"
#define ll long long

int el(int g[][1000], bool vv[][1000], int row, int col, int n, int m)
{
    if (row < 0 || row >= n || col < 0 || col >= m || vv[row][col] || g[row][col] == 0)
    {
        return 0;
    }

    vv[row][col] = true;

    int v = g[row][col];
    v += el(g, vv, row + 1, col, n, m);
    v += el(g, vv, row - 1, col, n, m);
    v += el(g, vv, row, col + 1, n, m);
    v += el(g, vv, row, col - 1, n, m);

    return v;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[1000][1000];
        bool vv[1000][1000];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                vv[i][j] = false;
            }
        }

        int lv = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (g[i][j] > 0 && !vv[i][j])
                {
                    int v = el(g, vv, i, j, n, m);
                    lv = max(lv, v);
                }
            }
        }

        cout << lv << endl;
    }

    return 0;
}