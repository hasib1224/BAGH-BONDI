#ifndef aiTiger_h
#define aiTiger_h
//#include"ai_board.h"
#include "AI_MINI-MAX.h"
#include"WinningScreen.h"
#include"TwoPlayerMode.h"


void ai_tiger(){
    board_initialize();
    ai_killed_goat=0;
    g_count=20;
    total_goat=20;
    killed_goat=0;

    board_view();

    while(1){
        int value;
        board2_TO_ai_board();

        while(1){                
            if(total_goat>0){
                goat_input(); 
                if(goat_suc_input==5){
                    cleardevice();
                    board_view();
                    break;
                }
            }
            else if(total_goat==0){
                goat_scope();
                if(goat_suc_input==5){
                    cleardevice();
                    board_view();
                    break;
                }
            }

        }

        while(1){   

            ai_turn="TIGER";
            board2_TO_ai_board();
    
            value = ai_tiger_minimax(0, -infinity, +infinity);

            if(tiger_kill_move_flag==1){
                board2[ move_to[0] ] [ move_to[1] ]='T';
                board2[ move_from[0] ] [ move_from[1] ]='*';
                board2[ (move_to[0] + move_from[0] )/2 ] [ (move_to[1] + move_from[1] )/2 ] = '*';
                ai_killed_goat++;
                tiger_kill_move_flag = 0;
                board_view();
                break;
            }
            else{
                board2[ move_to[0] ] [ move_to[1] ]='T';
                board2[ move_from[0] ] [ move_from[1] ]='*';
                board_view();
                break;
           
            }

        }

        if(value==infinity) {
            tiger_win_screen();
            cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!";
            break;
        }
        else if(value==(-infinity)){
            goat_win_screen() ;
            cout<<"CONGRATULATIONS!! GOAT WIN THE MATCH!!!"; 
            break;
        }

    }
   
}


#endif