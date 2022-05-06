#include<bits/stdc++.h>
using namespace std;
#include"TwoPlayerMode.h"
#include"AI_MENU.h"
#include"menu.h"


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

 
