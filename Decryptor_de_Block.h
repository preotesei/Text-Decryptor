#ifndef IRMX2_DECRYPTOR_DE_BLOCK_H
#define IRMX2_DECRYPTOR_DE_BLOCK_H

#include <bits/stdc++.h>

class Decryptor_de_Block {
public:
    virtual void decrypt(unsigned long long int *v) = 0;
};

class Decryptor_For_Block_Nothing : public Decryptor_de_Block{
public:
    void decrypt(unsigned long long int *v) override;
};

class Decryptor_For_Block_Reverse : public Decryptor_de_Block{
public:
    void decrypt(unsigned long long int *v) override;
};

class Decryptor_For_Block_Rotation : public Decryptor_de_Block{
private:
    int Rotation;
public:
    Decryptor_For_Block_Rotation(int rotation);

    static unsigned long long Rotation_To_Left(unsigned long long Number, int Dimension);

    void decrypt(unsigned long long int *Vector) override;
};

class Decryptor_For_Block_XOR : public Decryptor_de_Block{
private:
    std::string Key;
public:
    Decryptor_For_Block_XOR(std::string key);

    static long long BinaryFromString(std::string Key);

    void decrypt(unsigned long long int *v) override;
};



#endif //IRMX2_DECRYPTOR_DE_BLOCK_H
