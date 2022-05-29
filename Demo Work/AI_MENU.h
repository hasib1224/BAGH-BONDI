#ifndef ai_menu
#define ai_menu

#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include "board.h"

#include "ai_goat.h"
#include "ai_tiger.h"



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
            ai_goat(); 
            ai_tiger_mode=1;
            break;
          }
          else if((x>760 && x<930) && (y>140 && y<200)){
            ai_tiger();
            ai_goat_mode=1;
            break;
          }

        }
      }

      if(back_menu_flag==1) break;
      else if(ai_tiger_mode==1){
        break;
      }
      else if(ai_goat_mode==1){
        break;
      }

    }
    


  }

#endif


