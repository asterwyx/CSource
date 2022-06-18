#include <iostream>

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // First determine how many effective bits this number has.
        int effectiveBits = 1;
        int higherBound = 1;
        while (higherBound != 0)
        {
            if (higherBound <= n)
            {
                effectiveBits++;
                higherBound <<= 1;
            }
            else
            {
                break;
            }
        }
        int effectiveMask = higherBound - 1;
        int tmp = n ^ (n << 1) | 1; 
    
        return (effectiveMask & tmp) == effectiveMask;
    }
};


int main()
{
    // int higherBound = 1;
    // int effectiveBits = 1;
    // while (effectiveBits < 72)
    // {
    //     // std::cout << higherBound << std::endl;
    //     std::cout << higherBound - 1 << std::endl;
    //     higherBound <<= 1;
    //     effectiveBits++;
    // }
    Solution solution;
    auto result = solution.hasAlternatingBits(5);
    return 0;
}