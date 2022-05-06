#ifndef board_h

#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream>

struct cordin{
   int x;
   int y;
};
struct cordin scope_track[8], g_scope_track[8], kill_scope_track[8], goat_track[8], tig_track, goat_ind, board[30][30]; 
// goat_track[] is to track the possible move of tiger over goat
//scope_track is to store the possible move of tiger for *
//goat_ind is to store the clicked goat index
//g_scope_track to store the possible move of goat

char board2[50][50];
int  move_count, total_move, s_track ,tiger_suc_input, goat_suc_input ;  //move_count for count a tiger's move
int total_goat=20, goat_win_flag, tiger_win_flag , killed_goat;
int mode_start, back_menu_flag , ai_goat_mode, ai_tiger_mode ;




void cordinatew(){

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

   }


void board_initialize(){
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         board2[i][j]='*';
      }
   }  
   board2[0][0]='T';
   board2[0][4]='T';
   board2[4][0]='T';
   board2[4][4]='T';
}

void welcome(){

   settextstyle(8,0,5);
   setcolor(WHITE);

   outtextxy(650,200,"WELCOME TO");
    
   outtextxy(530,250,"THE BAGH BONDI GAME!!");

   settextstyle(8,0,3);
   outtextxy(650,430,"WAIT A SECCOND.....");
    
   delay(7);

}


int tiger_possible_move(int m1,int m2){ 

   int   move_count=0;
   if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
     (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

      if(board2[m1-1][m2+1]=='*'){  
         move_count++;
      }
      else if(board2[m1-1][m2+1]=='G'){
         if(board2[m1-2][m2+2]=='*') move_count++;
      }

      if(board2[m1+1][m2-1]=='*'){
         move_count++;
      }
      else if(board2[m1+1][m2-1]=='G'){
         if(board2[m1+2][m2-2]=='*') move_count++;
      }


      if(board2[m1-1][m2-1]=='*'){ 
         move_count++;
      }
      else if(board2[m1-1][m2-1]=='G'){
         if(board2[m1-2][m2-2]=='*') move_count++;
      } 

        
      if(board2[m1+1][m2+1]=='*'){
         move_count++;
      }
      else if(board2[m1+1][m2+1]=='G'){
         if(board2[m1+2][m2+2]=='*') move_count++;
      }


      if(board2[m1-1][m2]=='*'){
         move_count++;
      }
      else if(board2[m1-1][m2]=='G'){
         if(board2[m1-2][m2]=='*') move_count++;
      }   


      if(board2[m1+1][m2]=='*'){ 
         move_count++;
      }
      else if(board2[m1+1][m2]=='G'){
         if(board2[m1+2][m2]=='*') move_count++;
      } 


      if(board2[m1][m2+1]=='*'){
        move_count++;
      }
      else if(board2[m1][m2+1]=='G'){
         if(board2[m1][m2+2]=='*') move_count++;
      }  

          
      if(board2[m1][m2-1]=='*'){ 
         move_count++;
      }
      else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') move_count++;
      } 

        
   }   


   else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
      (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

      if(board2[m1-1][m2]=='*'){
         move_count++;
      }
      else if(board2[m1-1][m2]=='G'){
         if(board2[m1-2][m2]=='*') move_count++;
      }  


      if(board2[m1+1][m2]=='*'){ 
         move_count++;
      }
      else if(board2[m1+1][m2]=='G'){
         if(board2[m1+2][m2]=='*') move_count++;
      }  


      if(board2[m1][m2+1]=='*'){ 
         move_count++;
      }
      else if(board2[m1][m2+1]=='G'){
         if(board2[m1][m2+2]=='*') move_count++;
      }      
          
      if(board2[m1][m2-1]=='*'){ 
         move_count++;
      }
      else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') move_count++;
      }


   }


   return move_count;

  }


int tiger_info(){
   int temp=0;
   total_move=0;  
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){ 
         if(board2[i][j]=='T'){  
            temp=tiger_possible_move(i,j);
            total_move=total_move + temp;
            if(temp==0) {
               setlinestyle(0,0,10); setcolor(RED);  
               rectangle(board[i][j].x-28,board[i][j].y-28,board[i][j].x+28, board[i][j].y+28);
            }
         }
      }
   }

   return total_move;

}    


void board_view(){
   cordinatew();
   cleardevice();

   setfillstyle(SOLID_FILL,CYAN);
   floodfill(79,49,CYAN);

   //outer rectangle
   setcolor(DARKGRAY);
   setlinestyle(0,0,1);
   rectangle(500,100,1100,700);
   setfillstyle(SOLID_FILL,DARKGRAY);
   floodfill(501,101,DARKGRAY); 

   setcolor(BLACK);
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

   cordinatew();
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){ 
         if(board2[i][j]=='T'){

            readimagefile("TIGER.jpg",board[i][j].x-20, board[i][j].y-20,board[i][j].x+20, board[i][j].y+20);

         }else if(board2[i][j]=='G'){
            readimagefile("GOAT.jpg",board[i][j].x-20, board[i][j].y-20,board[i][j].x+20, board[i][j].y+20);
         }
      }
   }


   goat_win_flag=tiger_info();


}

#define board_h
#endif
