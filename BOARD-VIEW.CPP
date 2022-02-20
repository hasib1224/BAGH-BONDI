
#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream> 
int goat_input(int x,int y);

struct cordin{
    int x;
    int y; }board[30][30];

    char board2[50][50];
    int j=0,k=0,m,x,y;

int main(){
  //...initialize console board....
   for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
               board2[i][j]='*';
            }
        }
    
     board2[0][0]='T';
     board2[0][4]='T';
     board2[4][0]='T';
     board2[4][4]='T';



   
  //........CO-ORDINATE ASSIGNING............
  board[0][0].x=500; board[0][0].y=100;
  board[0][1].x=650; board[0][1].y=100;
  board[0][2].x=800; board[0][2].y=100;
  board[0][3].x=950; board[0][3].y=100;
  board[0][4].x=1100; board[0][4].y=100;

  board[1][0].x=500; board[1][0].y=250;
  board[1][1].x=650; board[1][1].y=250;
  board[1][2].x=800; board[1][2].y=250;
  board[1][3].x=950; board[1][3].y=250;
  board[1][4].x=1100; board[1][4].y=250;

  board[2][0].x=500; board[2][0].y=400;
  board[2][1].x=650; board[2][1].y=400;
  board[2][2].x=800; board[2][2].y=400;
  board[2][3].x=950; board[2][3].y=400;
  board[2][4].x=1100;board[2][4].y=400;

  board[3][0].x=500; board[3][0].y=550;
  board[3][1].x=650; board[3][1].y=550;
  board[3][2].x=800; board[3][2].y=550;
  board[3][3].x=950; board[3][3].y=550;
  board[3][4].x=1100; board[3][4].y=550;

  board[4][0].x=500; board[4][0].y=700;
  board[4][1].x=650; board[4][1].y=700;
  board[4][2].x=800; board[4][2].y=700;
  board[4][3].x=950; board[4][3].y=700;
  board[4][4].x=1100; board[4][4].y=700; 
//...................................................

   initwindow(1600,800,"MENU",0,0,false,true);
   
   //FOR BACKGROUND DISPLAY
    setfillstyle(SOLID_FILL,CYAN);
   floodfill(79,49,CYAN);

  //FOR BOARD LINE COLOR
  setcolor(BLACK); 

  //FOR BOARD LINE COLOR
   setcolor(BLACK);

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

//int radious=20;

//setlinestyle(0,0,10);// linestyle, unsigned upattern,int thickness
          
          

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){ 
            if(board2[i][j]=='T'){
                readimagefile("TIGER.jpg",board[i][j].x-20, board[i][j].y-20,board[i][j].x+20, board[i][j].y+20);
             }
         }
    }

      POINT cursor;
      while(1){
         if(GetAsyncKeyState(VK_LBUTTON)){
             GetCursorPos(&cursor);
             x=cursor.x;
             y=cursor.y;
             k=goat_input(x,y);
            if(k==1) break;
          }          
          
        }



getch();
closegraph();
return 0;

}
 //.....goat input..............
  int goat_input(int x,int y){
    int k;
  
            for(int i=0;i<5;i++){
               for(int j=0;j<5;j++){
                    if((x>=board[i][j].x-20 && x<=board[i][j].x+20) && (y>=board[i][j].y-20 && y<=board[i][j].y+20)){
                      if(board2[i][j]=='*'){
                       readimagefile("GOAT.jpg",board[i][j].x-20,board[i][j].y-20,board[i][j].x+20, board[i][j].y+20);
                       board2[i][j]=='G';
                       k=1;return k;
                      }
                    }
                 }
              }return k;
          }          

