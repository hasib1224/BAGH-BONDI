#ifndef menu_h
#include"board.h"

int menu(){
   cleardevice();
    setfillstyle(SOLID_FILL,RED);
    floodfill(79,49,RED);
     
    readimagefile("COVER.jpg",2,2,1590, 790);

     //....UPPER RECTANGLE AND TEXT...
    setcolor(BLUE);
    rectangle(580,245,1055,310);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(581, 246, BLUE);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(590,260,"PLAY WITH  FRIENDS");

    //....LOWER RECTANGLE AND TEXT...
    setcolor(BLUE);
    rectangle(580,385,1055,450);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(581, 386, BLUE);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(590,400,"PLAY WITH COMPUTER");
   
   mode_start=0;
    while(1){   
        POINT cursor;
        int x,y;
        while(1){
            if(GetAsyncKeyState(VK_LBUTTON)){
               GetCursorPos(&cursor);
               x=cursor.x;
               y=cursor.y-20;

               if((x>580 && x<1055) && (y>245 && y<310)){
                  mode_start=1;
                  break;                   
               }
               if((x>580 && x<1055) && (y>385 && y<450)){     
                  mode_start=2;
                  //cout<<"menu.h";
                  break;

               }
            }
         }
         if(mode_start==1||mode_start==2) break;
      }

      return mode_start;

   }


#define menu_h
#endif


