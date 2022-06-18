#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int argc, char)
{
    std::list<int> l{1,2,3,4,5};
    std::cout << *std::upper_bound(l.begin(), l.end(), 2) << std::endl;
    system("pause");
    return 0;
}