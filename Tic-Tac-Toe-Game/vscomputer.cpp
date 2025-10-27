#include <iostream>
#include <cctype>
#include <ctime>

void DrawBoard(char* Spaces);
void Player1Move(char* spaces, char player);
void ComputerMove(char* spaces, char computer);
bool CheckWinner(char player, char player2, char* spaces);
bool CheckDraw(char* spaces);

int vscomputer(){
    char spaces[9]{' ',' ',' ',' ',' ',' ',' ',' ',' '};
    const char player1{'O'};
    const char player2{'X'};
    bool running{true};

    DrawBoard(spaces);
    while(running){
        Player1Move(spaces, player1);
        DrawBoard(spaces);
        if(CheckWinner(player1, player2, spaces)){
            running = false;
            break;
        }else if(CheckDraw(spaces)){
            running = false;
            break;
        }

        std::cout<<std::endl;

        ComputerMove(spaces, player2);
        DrawBoard(spaces);

        std::cout<<std::endl;

        if(CheckWinner(player1, player2, spaces)){
            running = false;
            break;
        }else if(CheckDraw(spaces)){
            running = false;
            break;
        }
    }
    return 0;
}

void DrawBoard(char* spaces){
    
    // std::cout<<"     ┃     ┃     "<<std::endl;
    std::cout<<"  "<<spaces[0]<<"  ┃  "<<spaces[1]<<"  ┃  "<<spaces[2]<<"  "<<std::endl;
    std::cout<<"━━━━━╋━━━━━╋━━━━━"<<std::endl;
    std::cout<<"  "<<spaces[3]<<"  ┃  "<<spaces[4]<<"  ┃  "<<spaces[5]<<"  "<<std::endl;
    std::cout<<"━━━━━╋━━━━━╋━━━━━"<<std::endl;
    std::cout<<"  "<<spaces[6]<<"  ┃  "<<spaces[7]<<"  ┃  "<<spaces[8]<<"  "<<std::endl;
}

void Player1Move(char* spaces, char player){
    int number;
    do{
        std::cout<<"Enter the number(1-9): ";
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

void ComputerMove(char* spaces, char computer){
    int number;
    srand(time(nullptr));
    
    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool CheckWinner(char player1, char player2, char* spaces){
       if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player1 ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }

    return true;
}
bool CheckDraw(char* spaces){
    for(int i = 0; i <9; ++i){
        if(spaces[i] == ' ')
        return false;
    }
    std::cout <<"Its a Draw!"<<std::endl;
    return true;
}