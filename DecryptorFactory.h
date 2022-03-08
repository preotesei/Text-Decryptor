#ifndef IRMX2_DECRYPTORFACTORY_H
#define IRMX2_DECRYPTORFACTORY_H
#include <bits/stdc++.h>
#include "Decryptor.h"

using namespace std;

class DecryptorFactory{
public:
    static IDecryptor *makeDecryptor(string const & description){
        stringstream ss(description);
        string TextEncryption;
        ss >> TextEncryption;
        Decryptor_de_Text *txt;
        Decryptor_de_Block *block;
        if(TextEncryption == "NIMIC"){
            string BlockEncryption;
            ss >> BlockEncryption;
            txt = new Decryptor_For_Nothing;
            if(BlockEncryption == "NIMIC"){
                block = new Decryptor_For_Block_Nothing;
            }
            else if(BlockEncryption == "ROTATIE"){
                int Rotation;
                ss >> Rotation;
                block = new Decryptor_For_Block_Rotation(Rotation);
            }
            else if(BlockEncryption == "INVERSARE"){
                block = new Decryptor_For_Block_Reverse;
            }
            if(BlockEncryption == "XOR"){
                string Key;
                ss >> Key;
                block = new Decryptor_For_Block_XOR(Key);
            }
        }
        else if(TextEncryption == "ROTATIE"){
            int Rotation;
            ss >> Rotation;
            string BlockEncryption;
            ss >> BlockEncryption;
            txt = new Decryptor_For_Text_Rotation(Rotation);
            if(BlockEncryption == "NIMIC"){
                block = new Decryptor_For_Block_Nothing;
            }
            if(BlockEncryption == "ROTATIE"){
                int Rotation2;
                ss >> Rotation2;
                block = new Decryptor_For_Block_Rotation(Rotation2);
            }
            if(BlockEncryption == "INVERSARE"){
                block = new Decryptor_For_Block_Reverse;
            }
            if(BlockEncryption == "XOR"){
                string Key;
                ss >> Key;
                block = new Decryptor_For_Block_XOR(Key);
            }
        }
        else if(TextEncryption == "CEZAR"){
            int Distance;
            ss >> Distance;
            string BlockEncryption;
            ss >> BlockEncryption;
            txt = new Decryptor_For_Text_Caesar(Distance);
            if(BlockEncryption == "NIMIC"){
                block = new Decryptor_For_Block_Nothing;
            }
            if(BlockEncryption == "ROTATIE"){
                int Rotation;
                ss >> Rotation;
                block = new Decryptor_For_Block_Rotation(Rotation);
            }
            if(BlockEncryption == "INVERSARE"){
                block = new Decryptor_For_Block_Reverse;
            }
            if(BlockEncryption == "XOR"){
                string Key;
                ss >> Key;
                block = new Decryptor_For_Block_XOR(Key);
            }
        }
        else if(TextEncryption == "XOR"){
            char Key;
            ss >> Key;
            string BlockEncryption;
            ss >> BlockEncryption;
            txt = new Decryptor_For_Text_XOR(Key);
            if(BlockEncryption == "NIMIC"){
                block = new Decryptor_For_Block_Nothing;
            }
            if(BlockEncryption == "ROTATIE"){
                int Rotation;
                ss >> Rotation;
                block = new Decryptor_For_Block_Rotation(Rotation);
            }
            if(BlockEncryption == "INVERSARE"){
                block = new Decryptor_For_Block_Reverse;
            }
            if(BlockEncryption == "XOR"){
                string Key2;
                ss >> Key2;
                block = new Decryptor_For_Block_XOR(Key2);
            }
        }
        else{
            return nullptr;
        }
        return new Decryptor(txt, block);
    }
};

#endif //IRMX2_DECRYPTORFACTORY_H
