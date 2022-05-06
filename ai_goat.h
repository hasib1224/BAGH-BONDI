#ifndef aiGoat_h
#define aiGoat_h
#include "AI_MINI-MAX.h"
#include"WinningScreen.h"
#include"TwoPlayerMode.h"


void ai_goat(){

    board_initialize();
    ai_killed_goat=0;
    g_count=20; 
    total_goat=20;
    killed_goat=0; 

    board_view();

    while(1){
        while(1){   
            int value;
            board2_TO_ai_board();
            ai_turn="GOAT";
    
            value = ai_goat_minimax(0, -infinity, +infinity);

            if(move_from[0]==999||move_from[1]==999){
                board2[ move_to[0] ] [  move_to[1]  ]='G';
                g_count--;
                total_goat--;
                board_view();
            }
            else{
                board2[ move_to[0] ] [  move_to[1]  ]='G';
                board2[ move_from[0] ] [  move_from[1]  ]='*';
                total_goat=0;
                g_count=0;
                board_view();
            }

            if(value==infinity) {
                goat_win_screen();
                cout<<"CONGRATULATIONS!! GOAT WIN THE MATCH!!!";
                break;
            }
            else if(value==(-infinity)){
                tiger_win_screen();
                cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!"; 
                break;
            }
            
            break;
        }

        if(goat_win_flag!=0){
            while(1){
                tiger_scope(); 
                if(tiger_suc_input==6) break;
            } 
        }
        else break;

        if(killed_goat==5){      
            tiger_win_screen();
            break;
        }
    }

}


#endif