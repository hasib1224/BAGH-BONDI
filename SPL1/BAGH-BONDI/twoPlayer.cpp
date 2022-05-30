

#include"tiger.h"
#include"goat.h"
#include"twoPlayerMode.h"
#include"globalVariable.h"


void two_player_mode(){
   board_initialize();
   total_goat=20, killed_goat=0 ;
   ai_killed_goat=0;

   cleardevice();

   board_view();
   goats_turn_print();

   while(1){
      tiger_suc_input=0;
      goat_suc_input=0;

      while(1){                         //.....goat input loop.......
         if(total_goat>0){
            goat_input_WhenGoatNumber_NotZero();

            if(goat_suc_input==5){
              cleardevice();

              board_view();
              tigers_turn_print();

              break;
            }

         }
         else if(total_goat==0){
            goat_move_scope();

            if(goat_suc_input==5){
              cleardevice();

              board_view();
              tigers_turn_print();

              break;
            }

         }

      }


      if( goat_win_flag!=0 ){
         while(1){                            //.....Tiger input loop........
            tiger_scope();
            if(tiger_suc_input==6) break;

         }

      }


      if(killed_goat==5){
        tiger_win_screen();
        break;
      }

      if(goat_win_flag==0){
        goat_win_screen();
        break;

      }


   }

}



