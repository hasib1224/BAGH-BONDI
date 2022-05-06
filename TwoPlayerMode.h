#ifndef twoPlayer_h
#include"goat.h"
#include"WinningScreen.h"
#include"menu.h"

void two_player_mode(){
   board_initialize();
   total_goat=20, killed_goat=0 ;
   
   cleardevice();
   board_view();

   while(1){
      tiger_suc_input=0;
      goat_suc_input=0;

      while(1){                 //.....goat input loop.......
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


      if( goat_win_flag!=0 ){ 
         //.....Tiger input loop........
         while(1){
            tiger_scope(); 
            if(tiger_suc_input==6) break;
         
         } 

      }


      if(killed_goat==5){      //.....TIGER WINNING SCREEEN.......
        tiger_win_screen();
        break;
      }

      if(goat_win_flag==0){   //.....GOAT WINNING SCREEN..........
        goat_win_screen();
        break;

      }


   }   

}

#define twoPlayer_h
#endif



