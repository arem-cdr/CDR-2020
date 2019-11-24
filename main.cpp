#include <iostream>
#include <vector>

#include "Vector2.h"
#include "PathGenerator.h"

using namespace std;

int main()
{

    Vector2 v(5.f, 2.f);
    Vector2 b(5.f, 1.f);
    Vector2 d;

    cout << v << endl;

    PathGenerator p;

    p.generatePath(v, b);

    cout << p << endl;

    return 0;
}