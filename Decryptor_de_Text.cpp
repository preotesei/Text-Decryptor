#include "Decryptor_de_Text.h"

std::string Decryptor_For_Nothing::decrypt(std::string Text) {
    return Text;
}

Decryptor_For_Text_Rotation::Decryptor_For_Text_Rotation(int rotations) : Rotations(rotations) {}

std::string Decryptor_For_Text_Rotation::decrypt(std::string Text) {
    reverse(Text.begin(), Text.begin() + Rotations);
    reverse(Text.begin() + Rotations, Text.end());
    reverse(Text.begin(), Text.end());
    return Text;
}


Decryptor_For_Text_Caesar::Decryptor_For_Text_Caesar(int distance) : Distance(distance) {}

std::string Decryptor_For_Text_Caesar::decrypt(std::string Text) {
    for(auto &Character : Text){
        if(Character >= 'a' && Character <= 'z'){
            Character = Character - Distance;
            if(Character < 'a'){
                Character += 'z' - 'a' + 1;
            }
        }
        else if(Character >= 'A' && Character <= 'Z'){
            Character = Character - Distance;
            if(Character < 'A') {
                Character += 'Z' - 'A' + 1;
            }
        }
    }
    return Text;
}


Decryptor_For_Text_XOR::Decryptor_For_Text_XOR(char key) : Key(key) {}

std::string Decryptor_For_Text_XOR::decrypt(std::string Text) {
    for(auto &Character : Text){
        Character = (Character ^ Key);
    }
    return Text;
}


