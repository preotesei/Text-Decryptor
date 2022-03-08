#include "Decryptor_de_Block.h"

void Decryptor_For_Block_Nothing::decrypt(unsigned long long int *v) {
    }

void Decryptor_For_Block_Reverse::decrypt(unsigned long long int *v) {
    unsigned long long Temporary = 0;
    unsigned long long Vector_Copy;
    for(int i = 0 ; i < 128 ; ++i){
        Vector_Copy = v[i];
        for(int j = 0 ; j < 64 ; ++j){
            Temporary = (Temporary << 1) + (Vector_Copy & 1);
            Vector_Copy = (Vector_Copy >> 1);
        }
        v[i] = Temporary;
    }
}

Decryptor_For_Block_Rotation::Decryptor_For_Block_Rotation(int rotation) : Rotation(rotation) {}

unsigned long long Decryptor_For_Block_Rotation::Rotation_To_Left(unsigned long long int Number, int Dimension) {
    return (Number << Dimension) | (Number >> (64 - Dimension));
}

void Decryptor_For_Block_Rotation::decrypt(unsigned long long int *Vector) {
    unsigned long long temporary;
    for(int i = 0 ; i < 128 ; ++i){
        temporary = Rotation_To_Left(Vector[i], Rotation);
        Vector[i] = temporary;
    }
}


Decryptor_For_Block_XOR::Decryptor_For_Block_XOR(std::string key) : Key(std::move(key)) {}

long long Decryptor_For_Block_XOR::BinaryFromString(std::string Key) {
    unsigned long long Temp = 0;
    for(char i : Key){
        Temp = (Temp << 1) + ((int)i - 48);
    }
    return Temp;
}

void Decryptor_For_Block_XOR::decrypt(unsigned long long int *v) {
    unsigned long long key = BinaryFromString(Key);
    int Increments = 64 / Key.length();
    unsigned long long nr = 0;
    for (int i = 0; i < Key.length(); ++i) {
        nr = (nr << 1) + 1;
    }
    unsigned long long temp;
    unsigned long long replacement;
    unsigned long long mask;
    for(int i = 0 ; i < 128 ; ++i){
        temp = v[i];
        mask = nr;
        for(int j = 0 ; j < Increments ; ++j){
            replacement = (temp & mask);
            replacement = (replacement << (Key.length()*j));
            v[i] -= replacement;
            replacement = (replacement >> (Key.length()*j));
            replacement = (replacement ^ key);
            replacement = (replacement << (Key.length()*j));
            v[i] += replacement;
            temp = (temp >> Key.length());
        }
    }
}