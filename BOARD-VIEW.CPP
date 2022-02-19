
#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream> 

struct cordin{
    int x;
    int y; };

int main(){
   
   struct cordin tiger[5];

   tiger[1].x=500;  tiger[1].y=100;
   tiger[2].x=500;  tiger[2].y=700;
   tiger[3].x=1100;  tiger[3].y=100;
   tiger[4].x=1100;  tiger[4].y=700;

   initwindow(1600,800,"MENU",0,0,false,true);
   
   //FOR BACKGROUND DISPLAY
    setfillstyle(SOLID_FILL,CYAN);
   floodfill(79,49,CYAN);

  //FOR BOARD LINE COLOR
  setcolor(BLACK); 

  //FOR BOARD LINE COLOR
   setcolor(BLACK);

  POINT cursor;

   //outer rectangle
    rectangle(500,100,1100,700);

 //diagonal
 line(500,100,1100,700);
 line(500,700,1100,100);

  //parallel_horizon
 line(500,250,1100,250);
 line(500,400,1100,400);
 line(500,550,1100,550);

 //parallel_vertical
 line(650,100,650,700);
 line(800,100,800,700);
 line(950,100,950,700);

 //middle rectangle
 line(500,400,800,100);
 line(800,100,1100,400);
 line(800,700,1100,400);
 line(500,400,800,700);

int radious=20;

setlinestyle(0,0,10);// linestyle, unsigned upattern,int thickness
          
          

for(int i=1;i<5;i++){
    setcolor(RED);
    readimagefile("TIGER.jpg",tiger[i].x-30, tiger[i].y-30,tiger[i].x+30, tiger[i].y+30);
    }


getch();
closegraph();
return 0;

}

