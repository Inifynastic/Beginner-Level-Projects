#include <iostream>

void DrawBoard1(char* Spaces);
void Player1Move1(char* spaces, char player);
void Player2Move1(char* spaces, char player);
bool CheckWinner1(char player, char player2, char* spaces);
bool CheckDraw1(char* spaces);

int vsplayer(){
    char spaces[9]{' ',' ',' ',' ',' ',' ',' ',' ',' '};
    const char player1{'O'};
    const char player2{'X'};
    //char test;
    bool running{true};
    /*std::cout<<"Would you like to play against computer or another player?(P/C): ";
    std::cin >> test;
    std::toupper(test);
    */

    DrawBoard1(spaces);
    while(running){
        Player1Move1(spaces, player1);
        DrawBoard1(spaces);
        if(CheckWinner1(player1, player2, spaces)){
            running = false;
            break;
        }else if(CheckDraw1(spaces)){
            running = false;
            break;
        }

        std::cout<<std::endl;

        Player2Move1(spaces, player2);
        DrawBoard1(spaces);

        std::cout<<std::endl;

        if(CheckWinner1(player1, player2, spaces)){
            running = false;
            break;
        }else if(CheckDraw1(spaces)){
            running = false;
            break;
        }
    }
    return 0;
}

void DrawBoard1(char* spaces){
    
    // std::cout<<"     ┃     ┃     "<<std::endl;
    std::cout<<"  "<<spaces[0]<<"  ┃  "<<spaces[1]<<"  ┃  "<<spaces[2]<<"  "<<std::endl;
    std::cout<<"━━━━━╋━━━━━╋━━━━━"<<std::endl;
    std::cout<<"  "<<spaces[3]<<"  ┃  "<<spaces[4]<<"  ┃  "<<spaces[5]<<"  "<<std::endl;
    std::cout<<"━━━━━╋━━━━━╋━━━━━"<<std::endl;
    std::cout<<"  "<<spaces[6]<<"  ┃  "<<spaces[7]<<"  ┃  "<<spaces[8]<<"  "<<std::endl;
}

void Player1Move1(char* spaces, char player){
    int number;
    do{
        std::cout<<"Enter the number(1-9)["<< player<<"]: ";
        std::cin>>number;
        number--;
        if(number < 0 || number > 9){
            std::cout<<"Enter a valid number.(1-9)"<<std::endl;
        }else{
            if( spaces[number] == ' '){
                spaces[number] = player;
                break;
            }else{
                std::cout<<"The Space is occupied."<<std::endl;
            }
        }
    }while(number < 0 || number > 9);
}
void Player2Move1(char* spaces, char player){
    int number;
    do{
        std::cout<<"Enter the number(1-9)["<< player<<"]: ";
        std::cin>>number;
        number--;
        if(number < 0 || number > 9){
            std::cout<<"Enter a valid number.(1-9)"<<std::endl;
        }else{
            if( spaces[number] == ' '){
                spaces[number] = player;
                break;
            }else{
                std::cout<<"The Space is occupied."<<std::endl;
            }
        }
    }while(number < 0 || number > 9);
}

bool CheckWinner1(char player1, char player2, char* spaces){
       if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player1 ? std::cout << "Player1 WINS!\n" : std::cout << "Player2 WINS!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player1 ? std::cout << "Player1 WINs!\n" : std::cout << "Player2 WINS\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player1 ? std::cout << "Player1 WINS!\n" : std::cout << "Player2 WINS\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player1 ? std::cout << "Player1 WINs!\n" : std::cout << "Player2 WINS\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player1 ? std::cout << "Player1 WINs!\n" : std::cout << "Player2 WINS\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player1 ? std::cout << "Player1 WINs!\n" : std::cout << "Player2 WINS\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player1 ? std::cout << "Player1 WINS!\n" : std::cout << "Player2 WINS\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player1 ? std::cout << "Player1 WINS!\n" : std::cout << "Player2 WINS\n";
    }
    else{
        return false;
    }

    return true;
}
bool CheckDraw1(char* spaces){
    for(int i = 0; i <9; ++i){
        if(spaces[i] == ' ')
        return false;
    }
    std::cout <<"Its a Draw!"<<std::endl;
    return true;
}
