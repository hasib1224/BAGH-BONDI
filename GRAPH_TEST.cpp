
#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream> 

struct cordin{
    int x;
    int y; };

int main(){
   // int gd=DETECT,gm;
    //initgraph(&gd,&gm,(char*)"");
   // circle(250,350,200);
   //rectangle(80,50,440,410);
   //line(120,50,120,410);
   //floodfill(122,70,RED);
   // line(160,50,160,410);

   struct cordin tiger[5];

   tiger[1].x=500;  tiger[1].y=100;
   tiger[2].x=500;  tiger[2].y=700;
   tiger[3].x=1100;  tiger[3].y=100;
   tiger[4].x=1100;  tiger[4].y=700;




   int height=GetSystemMetrics(SM_CYSCREEN);
   int weidth=GetSystemMetrics(SM_CXSCREEN);
    initwindow(1600,800,"MENU",0,0,false,true);

/*
    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(600,150,"Two Player");
    rectangle(590,150,860,190);
    outtextxy(600,200,"vs Machine");
    rectangle(590,200,860,240);
    outtextxy(600,250,"AI vs AI");
    rectangle(590,250,860,290);
    outtextxy(600,450,"Scoreboard");
    rectangle(590,450,900,490);
    //rectangle(590,150,860,190);

    rectangle(550,80,950,600);
    rectangle(549,79,949,599);
    rectangle(548,78,948,598);  */
       

       //FOR BACKGROUND DISPLAY
       setfillstyle(SOLID_FILL,CYAN);
       floodfill(79,49,CYAN);
         
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
                //circle(tiger[i].x, tiger[i].y, radious); 
                 settextstyle(10,0,5);
                 outtextxy(tiger[i].x, tiger[i].y,"T"); 
               }








           settextstyle(10,0,5);
           //outtextxy(500,100,"T");


           






    //circle(800,400,20);
    //setcolor(WHITE);
    //readimagefile("TIGER.jpg",75,55,95,75);
    //writeimagefile("HELLO HASIB",0,0);
   //outtextxy(0,0,"HASIB");
   // setfillstyle(SOLID_FILL,GREEN);
  // floodfill(79,49,WHITE); 

    /*

   while(1){
      // cleardevice();
       GetCursorPos(&cursor);
      
       if(GetAsyncKeyState(VK_LBUTTON)){
           
           circle(cursor.x,cursor.y,50);
           //setcolor(GREEN);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(cursor.x,cursor.y,WHITE);
            }

           if(GetAsyncKeyState(VK_RBUTTON))break;
          
        
        delay(220);
   }
   */




    getch();
    closegraph();
    return 0;

}

