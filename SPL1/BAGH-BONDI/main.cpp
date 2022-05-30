#include<bits/stdc++.h>
using namespace std;
#include"TwoPlayerMode.h"
#include "aiMode.h"




struct cordin scope_track[8], g_scope_track[8], kill_scope_track[8], goat_track[8], tig_track, goat_ind, board[30][30];

char board2[50][50];
int  move_count, total_move, s_track ,tiger_suc_input, goat_suc_input ;  //move_count for count a tiger's move
int total_goat=20, goat_win_flag, tiger_win_flag , killed_goat;
int mode_start, back_menu_flag , ai_goat_mode, ai_tiger_mode ;

// goat_track[] is to track the possible move of tiger over goat
//scope_track is to store the possible move of tiger for *
//goat_ind is to store the clicked goat index
//g_scope_track to store the possible move of goat



//*********Ai variables********
int g1,g2,g3,g4,t1,t2,t3,t4;  //Temporary_variable_to_take_input
char ai_board[50][50];
int g_count=20;       //GOAT NUMBER IS UPTO 20
int ai_killed_goat=0;
int move_from[2],move_to[2] , tiger_kill_move_flag=0 ;
int highest_search_depth = 3;
string ai_turn;


int main(){

   board_initialize();
   initwindow(1600,800,"MENU",0,0,false,true);
   welcome();
   cleardevice();

   cordinatew();

   menu();


   //........GAME WILL START FROM HERE.........
   while(1){
      if(mode_start==1){
         two_player_mode();
         menu();
      }

      else if(mode_start==2){
         ai_mode();

         if(back_menu_flag==1)  menu();
         else if(ai_goat_mode==1) {
            menu();
         }
         else if(ai_tiger_mode==1){
            menu();
         }

      }


   }


   getch();
   return 0;
}

