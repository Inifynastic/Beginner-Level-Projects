#include <iostream>
#include <cctype>
#include "vscomputer.cpp"
#include "vsplayer.cpp"

int main(){
    char value;
    bool data = true;
    while(data){
        std::cout<<"Would you like to play against computer or human?(C/H): ";
        std::cin>> value;
        std::toupper(value);

        if(value == 'C'){
            vscomputer();
            data = false;
            break;
        }else if(value == 'H'){
            vsplayer();
            data = false;
            break;
        }else{
            std::cout<<"Enter the correct value(C/H)"<<std::endl;
            data = true;
        }
    }
}