#include "Decryptor.h"

Decryptor::Decryptor(Decryptor_de_Text *txt, Decryptor_de_Block *block) : txt(txt), block(block) {}

std::string Decryptor::decrypt(const std::string &filename) {
    unsigned long long v[128];
    Utilities::MakeVector(filename, v);
    block->decrypt(v);
    int Verify = Utilities::BitControl_Verify(v);
    if(Verify != -42){
        std::stringstream ss;
        ss << Verify;
        std::string FirstString = "Blocul cu indexul ";
        std::string MiddleNumberString;
        std::string FinalString = " a fost alterat!";
        ss >> MiddleNumberString;
        return FirstString + MiddleNumberString + FinalString;
    }
    std::string CreatedString = Utilities::MakeStringFile(v);
    std::string LastString = txt->decrypt(CreatedString);
    return LastString;
}
