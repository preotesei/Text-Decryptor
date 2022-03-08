#ifndef IRMX2_UTILITIES_H
#define IRMX2_UTILITIES_H

#include <bits/stdc++.h>

class Utilities {
public:
    static void MakeVector(std::string filename, unsigned long long *v);
    static std::string MakeStringFile(unsigned long long *v);
    static unsigned int GetABit(unsigned long long a, unsigned long long n);
    static unsigned int SumOfXOR(unsigned int B, int j, unsigned long long a);
    static int BitControl_Verify(unsigned long long *v);
};


#endif //IRMX2_UTILITIES_H
