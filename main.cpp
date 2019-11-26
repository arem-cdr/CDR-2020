#include <iostream>
#include <vector>

#include "Vector2f.h"
#include "PathGenerator.h"

using namespace std;

int main()
{
    Vector2f v(5, 2);
    Vector2f b(5, 1);
    Vector2f n  = v*b;
    cout << n << endl;

    PathGenerator p;

    p.generatePath(v, b);

    cout << p << endl;

    return 0;
}