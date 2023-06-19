#include <iostream>

using namespace std;

template<typename WhatKind>
void multiples(WhatKind& sum, WhatKind x, int n)
{
    sum = WhatKind(1);
    for (int i = 0; i <= n; i++)
    {
        sum += i * x;
    }
}

int main()
{
    int sum;
    int x = 2;
    int n = 5;

    multiples(sum, x, n);

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
