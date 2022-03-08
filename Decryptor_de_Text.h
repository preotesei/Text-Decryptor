#ifndef IRMX2_DECRYPTOR_DE_TEXT_H
#define IRMX2_DECRYPTOR_DE_TEXT_H
#include <bits/stdc++.h>

class Decryptor_de_Text{
public:
    virtual std::string decrypt(std::string file) = 0;
};

class Decryptor_For_Nothing : public Decryptor_de_Text{
public:
    std::string decrypt(std::string Text) override;
};

class Decryptor_For_Text_Rotation : public Decryptor_de_Text{
private:
    int Rotations;
public:
    Decryptor_For_Text_Rotation(int rotations);

    std::string decrypt(std::string Text) override;
};

class Decryptor_For_Text_Caesar : public Decryptor_de_Text{
private:
    int Distance;
public:
    Decryptor_For_Text_Caesar(int distance);

    std::string decrypt(std::string Text) override;
};

class Decryptor_For_Text_XOR : public Decryptor_de_Text{
private:
    char Key;
public:
    Decryptor_For_Text_XOR(char key);

    std::string decrypt(std::string Text) override;
};

#endif //IRMX2_DECRYPTOR_DE_TEXT_H
