#ifndef IRMX2_DECRYPTOR_H
#define IRMX2_DECRYPTOR_H

#include <bits/stdc++.h>
#include "Decryptor_de_Block.h"
#include "Decryptor_de_Text.h"
#include "Utilities.h"

class IDecryptor {
public:
    virtual std::string decrypt(std::string const & filename) = 0;
};

class Decryptor : public IDecryptor{
private:
    Decryptor_de_Text *txt;
    Decryptor_de_Block *block;
public:
    Decryptor(Decryptor_de_Text *txt, Decryptor_de_Block *block);

    std::string decrypt(const std::string &filename) override;
};




#endif //IRMX2_DECRYPTOR_H
