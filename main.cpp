#include <iostream>
#include <vector>

#include "Vector2.h"
#include "PathGenerator.h"

using namespace std;

int main()
{
    Vector2<int> v(5, 2);
    Vector2<int> b(5, 1);
    Vector2<int> d;

    Vector2<float> f;

    cout << v << endl;

    PathGenerator p;

    p.generatePath(v, b);

    cout << p << endl;

    return 0;
}