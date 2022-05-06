#ifndef ai_menu
#define ai_menu

#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include "board.h"

#define infinity 9999999


int g1,g2,g3,g4,t1,t2,t3,t4;  //Temporary_variable_for_input
  //char board[50][50];
  char ai_board[50][50];
  int g_count=20;       //GOAT NUMBER IS UP TO 20
  int t_count=4;        // TOTAL TIGER IS
  //int total_move=0;     //TIGERS POSSIBLE MOVE NUMBER      
  int killed_g=0 ;       // KILLED GOAT NUMBER  
  int ai_killed_goat=0;

  int move_from[2],move_to[2] , tiger_kill_move_flag=0 ;

  int highest_search_depth = 2;

  string ai_turn;

  enum MoveType { GOAT_PLACE, GOAT_MOVE , TIGER_MOVE, TIGERS_KILL_MOVE};

  struct Move{
      MoveType type;
      int from[2],to[2] ;
   };


void ai_mode(){
    cleardevice();           
    // readimagefile("UNDER_DEVELOP.jpg",500,200,1100, 500);
    //  settextstyle(8,0,3);
    //  setcolor(WHITE);
    //  outtextxy(670,530,"UNDER DEVELOPING....");

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(610,90,"PLAY AS");


    setcolor(BLUE);
    rectangle(520,140,680,200);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(521, 141, BLUE);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(525,145,"TIGER");

    setcolor(BLUE);
    rectangle(760,140,930,200);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(761, 141, BLUE);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(770,150,"GOAT");


    setcolor(BLUE);
    rectangle(1255,90,1500,145);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(1256, 91, BLUE);

    settextstyle(10,0,4);
    setcolor(WHITE);
    outtextxy(1260,100,"BACK TO MENU");


    back_menu_flag=0;
    ai_goat_mode=0;
    ai_tiger_mode=0;

    while(1){
      POINT cursor;
      int x,y;
      while(1){
        if(GetAsyncKeyState(VK_LBUTTON)){

          GetCursorPos(&cursor);
          x=cursor.x;
          y=cursor.y-20;

          if((x>1255 && x<1500) && (y>90 && y<145)){
            back_menu_flag=1;
            break;                           
          }
          else if((x>520 && x<680) && (y>140 && y<200)){
            ai_tiger_mode=1;
            break;
          }
          else if((x>760 && x<930) && (y>140 && y<200)){
            ai_goat_mode=1;
            break;
          }

        }
      }

       if(back_menu_flag==1) break;
      else if(ai_tiger_mode==1){
        cout<<"ai.h";
        break;
      }
       else if(ai_goat_mode==1){
         break;
        }

    }
    


  }

  #endif


