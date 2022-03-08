#include "Utilities.h"

void Utilities::MakeVector(std::string filename, unsigned long long int *v) {
    std::ifstream date;
    date.open(filename, std::ios::in | std::ios::binary);
    char *temp = new char[8];
    for (int i = 0; i < 128; ++i) {
        date.read(temp, 8);
        std::reverse(temp, temp + 8);
        v[i] = *reinterpret_cast<long long *>(temp);
    }
}

std::string Utilities::MakeStringFile(unsigned long long int *v) {
    std::string StringFile;
    std::string temp;
    bool Stop_Condition = true;
    int i = 0;
    while(Stop_Condition){
        unsigned long long val = v[i];
        for(int j = 0 ; j < 6 ; ++j){
            temp = (char)(val >> (8*(7-j)));
            StringFile.append(temp);
        }
        i = ((v[i] >> 8) & 255);
        if(i == 255)
            Stop_Condition = false;
    }
    StringFile.erase(std::remove(StringFile.begin(), StringFile.end(), '\0'), StringFile.end());
    return StringFile;
}

unsigned int Utilities::GetABit(unsigned long long int a, unsigned long long int n) {
    return (a >> n) & 1;
}

unsigned int Utilities::SumOfXOR(unsigned int B, int j, unsigned long long int a) {
    while(j >= 0){
        B = (B ^ GetABit(a, j));
        j -= 8;
    }
    return B;
}

int Utilities::BitControl_Verify(unsigned long long int *v) {
    bool Stop_Condition = true;
    int idx = 0;
    unsigned int B56, B57, B58, B59, B60, B61, B62, B63;
    while(Stop_Condition){
        B56 = SumOfXOR(GetABit(v[idx], 48), 40, v[idx]);
        B57 = SumOfXOR(GetABit(v[idx], 49), 41, v[idx]);
        B58 = SumOfXOR(GetABit(v[idx], 50), 42, v[idx]);
        B59 = SumOfXOR(GetABit(v[idx], 51), 43, v[idx]);
        B60 = SumOfXOR(GetABit(v[idx], 52), 44, v[idx]);
        B61 = SumOfXOR(GetABit(v[idx], 53), 45, v[idx]);
        B62 = SumOfXOR(GetABit(v[idx], 54), 46, v[idx]);
        B63 = SumOfXOR(GetABit(v[idx], 55), 47, v[idx]);
        if((B56 != GetABit(v[idx], 56)) || (B57 != GetABit(v[idx], 57)) || (B58 != GetABit(v[idx], 58)) || (B59 != GetABit(v[idx], 59)) ||
           (B60 != GetABit(v[idx], 60)) || (B61 != GetABit(v[idx], 61)) || (B62 != GetABit(v[idx], 62)) || (B63 != GetABit(v[idx], 63))){
            return idx;
        }
        idx = ((v[idx] >> 8) & 255);
        if(idx == 255)
            Stop_Condition = false;
    }
    return -42;
}
