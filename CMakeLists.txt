cmake_minimum_required(VERSION 3.17)
project(IRMX2)

set(CMAKE_CXX_STANDARD 14)

add_executable(IRMX2 main.cpp Decryptor_de_Text.cpp Decryptor_de_Text.h Decryptor_de_Block.cpp Decryptor_de_Block.h Utilities.cpp Utilities.h Decryptor.cpp Decryptor.h DecryptorFactory.h)