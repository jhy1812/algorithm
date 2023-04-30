#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h;
int minn = 100000000;

int main()
{
    cin >> x >> y >> w >> h;
    minn = min(minn, x);
    minn = min(minn, y);
    minn = min(minn, w - x);
    minn = min(minn, h - y);
    
    cout << minn;
    
    return 0;
}