#ifndef win_h
#include<graphics.h>
#include<windows.h>
#include<iostream>

void tiger_win_screen(){

   cleardevice();
   settextstyle(8,0,5);
   setcolor(WHITE);
   outtextxy(540,220,"CONGRATULATIONS!!");
   outtextxy(520,270,"TIGER WIN THE MATCH !!");
   delay(7000);  
}

void goat_win_screen(){

   cleardevice();
   settextstyle(8,0,5);
   setcolor(WHITE);

   outtextxy(540,220,"CONGRATULATIONS!!");
   outtextxy(520,270,"GOAT WIN THE MATCH !!");
   delay(7000);
  

}

#define win_h
#endif


