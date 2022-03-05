
#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream>
//#include"board.cpp"
void welcome();

void cordinatew(); 
void board_view();
void goat_input();
void tiger_scope();
void tiger_scope_print(int m1,int m2);

void tiger_input();
int tiger_possible_move(int m1,int m2);
int tiger_info();

 void goat_scope();
 void goat_scope_print(int m1, int m2);
 void goat_input_2();

void tiger_win_screen();
void goat_win_screen();

int menu();
void two_player_mode();
int ai_mode();

struct cordin{
   int x;
   int y; };

char board2[50][50];
int  move_count, total_move, s_track ,tiger_suc_input, goat_suc_input;  //move_count for count a tiger's move
int total_goat=20, goat_win_flag, tiger_win_flag , killed_goat;
int mode_start, back_menu_flag;;

struct cordin scope_track[8], g_scope_track[8], kill_scope_track[8], goat_track[8], tig_track, goat_ind, board[30][30]; 
// goat_track[] is to track the possible move of tiger over goat
//scope_track is to store the possible move of tiger for *
//goat_ind is to store the clicked goat index
//g_scope_track to store the possible move of goat

 
//...MAIN FUNCTION.....
int main(){

//int j=0,k=0,m,x,y;
  

for(int i=0;i<5;i++){
   for(int j=0;j<5;j++){
       board2[i][j]='*';
   }
}
    
board2[0][0]='T';
board2[0][4]='T';
board2[4][0]='T';
board2[4][4]='T';

   initwindow(1600,800,"MENU",0,0,false,true);   
   setfillstyle(SOLID_FILL,CYAN);
   floodfill(79,49,CYAN);

   welcome();
   cleardevice();

//........CO-ORDINATE ASSIGNING............
 cordinatew();
//........DISPLAY THE BOARD................
//board_view();
menu();


//...UNLIMITED SUCCESFUL INPUT FOR GOAT AND TIGER....




while(1){
    if(mode_start==1){
       two_player_mode();
       menu();
    }

    else if(mode_start==2){
        ai_mode();
        if(back_menu_flag==1) menu();
     }
    
 } 





 

   getch();
   //closegraph();
   return 0;

}




//....... CO-ORDINATE ASSIGNING...,....
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

  //...GOAT INPUT........
void goat_input(){
   POINT cursor;
   int x,y;

while(1){
  if(GetAsyncKeyState(VK_LBUTTON)){
      GetCursorPos(&cursor);
      x=cursor.x;
      y=cursor.y-20;
      int k;
       for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                    if(board2[i][j]=='*'){
                      readimagefile("GOAT.jpg",board[i][j].x-20,board[i][j].y-20,board[i][j].x+20, board[i][j].y+20);
                      total_goat--;
                      board2[i][j]='G';
                      goat_suc_input=5;  //goat input successfully
                      k=1;break;
                     } 
                  }
               }
         }//return k;

      if(k==1) break;
   }              
}
   
   
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



void tiger_scope(){
   int k = 0;
   POINT cursor;
   int x=0,y=0;
  

   while(1){
   if(GetAsyncKeyState(VK_LBUTTON)){
      GetCursorPos(&cursor);
      x=cursor.x;
      y=cursor.y-20;

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                if(board2[i][j]=='T'){

                  tig_track.x=i;
                  tig_track.y=j;
                  cleardevice();
                  board_view();
                   
                  tiger_scope_print(i,j);
                  tiger_input();
                  k=1;
               } 
            }
         }
      }//return k;
    //  if(k==1) break;
   }  if(k==1) break;             
}

  
}          
  

void tiger_scope_print(int m1,int m2){
   setlinestyle(0,0,10);
   setcolor(GREEN);
   cordinatew();
   s_track=0; //move_count=0;

   //for(int q=0;q<=7;q++){scope_track[q].x=0;scope_track[q].y=0;}

   //int   move_count=0;
    if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
   (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

      if(board2[m1-1][m2+1]=='*'){ rectangle(board[m1-1][m2+1].x-20,board[m1-1][m2+1].y-20,board[m1-1][m2+1].x+20, board[m1-1][m2+1].y+20);
         scope_track[s_track].x=m1-1; scope_track[s_track].y=m2+1;  s_track++;}
       else if(board2[m1-1][m2+1]=='G'){
         if(board2[m1-2][m2+2]=='*') { rectangle(board[m1-2][m2+2].x-20,board[m1-2][m2+2].y-20,board[m1-2][m2+2].x+20, board[m1-2][m2+2].y+20);
           kill_scope_track[s_track].x=m1-2; kill_scope_track[s_track].y=m2+2; 
           goat_track[s_track].x=m1-1; goat_track[s_track].y=m2+1; s_track++; }}

           

        if(board2[m1+1][m2-1]=='*'){ rectangle(board[m1+1][m2-1].x-20,board[m1+1][m2-1].y-20,board[m1+1][m2-1].x+20, board[m1+1][m2-1].y+20);
        scope_track[s_track].x=m1+1;scope_track[s_track].y=m2-1; s_track++;}
        else if(board2[m1+1][m2-1]=='G'){
          if(board2[m1+2][m2-2]=='*') {rectangle(board[m1+2][m2-2].x-20,board[m1+2][m2-2].y-20,board[m1+2][m2-2].x+20, board[m1+2][m2-2].y+20);
           kill_scope_track[s_track].x=m1+2; kill_scope_track[s_track].y=m2-2; 
            goat_track[s_track].x=m1+1; goat_track[s_track].y=m2-1; s_track++;}}



        if(board2[m1-1][m2-1]=='*'){ rectangle(board[m1-1][m2-1].x-20, board[m1-1][m2-1].y-20, board[m1-1][m2-1].x+20, board[m1-1][m2-1].y+20);
         scope_track[s_track].x=m1-1; scope_track[s_track].y=m2-1; s_track++;}
        else if(board2[m1-1][m2-1]=='G'){
            if(board2[m1-2][m2-2]=='*'){rectangle(board[m1-2][m2-2].x-20,board[m1-2][m2-2].y-20,board[m1-2][m2-2].x+20, board[m1-2][m2-2].y+20);
             kill_scope_track[s_track].x=m1-2; kill_scope_track[s_track].y=m2-2; 
              goat_track[s_track].x=m1-1; goat_track[s_track].y=m2-1;  s_track++; }}
        


        if(board2[m1+1][m2+1]=='*'){ rectangle(board[m1+1][m2+1].x-20,board[m1+1][m2+1].y-20,board[m1+1][m2+1].x+20, board[m1+1][m2+1].y+20);
         scope_track[s_track].x=m1+1;scope_track[s_track].y=m2+1; s_track++;}
        else if(board2[m1+1][m2+1]=='G'){
            if(board2[m1+2][m2+2]=='*') {rectangle(board[m1+2][m2+2].x-20,board[m1+2][m2+2].y-20,board[m1+2][m2+2].x+20, board[m1+2][m2+2].y+20);
             kill_scope_track[s_track].x=m1+2; kill_scope_track[s_track].y=m2+2; 
              goat_track[s_track].x=m1+1; goat_track[s_track].y=m2+1; s_track++;}}



        if(board2[m1-1][m2]=='*'){ rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         scope_track[s_track].x=m1-1;scope_track[s_track].y=m2; s_track++;}
        else if(board2[m1-1][m2]=='G'){
            if(board2[m1-2][m2]=='*') {rectangle(board[m1-2][m2].x-20,board[m1-2][m2].y-20,board[m1-2][m2].x+20, board[m1-2][m2].y+20);
             kill_scope_track[s_track].x=m1-2; kill_scope_track[s_track].y=m2;
              goat_track[s_track].x=m1-1; goat_track[s_track].y=m2; s_track++;}}



        if(board2[m1+1][m2]=='*'){ rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         scope_track[s_track].x=m1+1;scope_track[s_track].y=m2;  s_track++;}
        else if(board2[m1+1][m2]=='G'){
            if(board2[m1+2][m2]=='*') {rectangle(board[m1+2][m2].x-20,board[m1+2][m2].y-20,board[m1+2][m2].x+20, board[m1+2][m2].y+20);
             kill_scope_track[s_track].x=m1+2; kill_scope_track[s_track].y=m2;
              goat_track[s_track].x=m1+1; goat_track[s_track].y=m2;  s_track++;}  }



         if(board2[m1][m2+1]=='*'){ rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
          scope_track[s_track].x=m1;scope_track[s_track].y=m2+1;  s_track++;}
         else if(board2[m1][m2+1]=='G'){
            if(board2[m1][m2+2]=='*') { rectangle(board[m1][m2+2].x-20,board[m1][m2+2].y-20,board[m1][m2+2].x+20, board[m1][m2+2].y+20);
             kill_scope_track[s_track].x=m1;kill_scope_track[s_track].y=m2+2; 
              goat_track[s_track].x=m1; goat_track[s_track].y=m2+1;  s_track++;}}
          


        if(board2[m1][m2-1]=='*'){  rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         scope_track[s_track].x=m1;scope_track[s_track].y=m2-1; s_track++;}
        else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') { rectangle(board[m1][m2-2].x-20,board[m1][m2-2].y-20,board[m1][m2-2].x+20, board[m1][m2-2].y+20);
          kill_scope_track[s_track].x=m1; kill_scope_track[s_track].y=m2-2;
           goat_track[s_track].x=m1; goat_track[s_track].y=m2-1;  s_track++;}}
        
    }   


    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

                if(board2[m1-1][m2]=='*'){ rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         scope_track[s_track].x=m1-1;scope_track[s_track].y=m2;  s_track++;}
        else if(board2[m1-1][m2]=='G'){
            if(board2[m1-2][m2]=='*') { rectangle(board[m1-2][m2].x-20,board[m1-2][m2].y-20,board[m1-2][m2].x+20, board[m1-2][m2].y+20);
            kill_scope_track[s_track].x=m1-2; kill_scope_track[s_track].y=m2;
             goat_track[s_track].x=m1-1; goat_track[s_track].y=m2;  s_track++; }   }
           

        if(board2[m1+1][m2]=='*'){ rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         scope_track[s_track].x=m1+1;scope_track[s_track].y=m2; s_track++;}
        else if(board2[m1+1][m2]=='G'){
            if(board2[m1+2][m2]=='*') { rectangle(board[m1+2][m2].x-20,board[m1+2][m2].y-20,board[m1+2][m2].x+20, board[m1+2][m2].y+20);
            kill_scope_track[s_track].x=m1+2; kill_scope_track[s_track].y=m2; 
             goat_track[s_track].x=m1+1; goat_track[s_track].y=m2;  s_track++;}   }


         if(board2[m1][m2+1]=='*'){rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
         scope_track[s_track].x=m1;scope_track[s_track].y=m2+1;  s_track++;}
         else if(board2[m1][m2+1]=='G'){
            if(board2[m1][m2+2]=='*')  { rectangle(board[m1][m2+2].x-20,board[m1][m2+2].y-20,board[m1][m2+2].x+20, board[m1][m2+2].y+20);
            kill_scope_track[s_track].x=m1; kill_scope_track[s_track].y=m2+2;
             goat_track[s_track].x=m1; goat_track[s_track].y=m2+1;  s_track++;}   }

          
        if(board2[m1][m2-1]=='*'){ rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         scope_track[s_track].x=m1;scope_track[s_track].y=m2-1;  s_track++;  }
        else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*')  { rectangle(board[m1][m2-2].x-20,board[m1][m2-2].y-20,board[m1][m2-2].x+20, board[m1][m2-2].y+20);
            kill_scope_track[s_track].x=m1; kill_scope_track[s_track].y=m2-2;
             goat_track[s_track].x=m1; goat_track[s_track].y=m2-1;  s_track++;}   }

    }

   /*
    for(int i=0;i<s_track;i++){
           cout<<scope_track[i].x<<" "<<scope_track[i].y<<"\n";
        }
        cout<<"........";

          for(int m=0;m<5;m+=1){cout<<"  "<<m;}
   cout<<"\n";          
     for(int i=0;i<5;i++){
        cout<<i;
         for(int j=0;j<5;j++){
           cout<< " " << board2[i][j]<<" ";
             }cout<<"\n"; 
        } */



   

}



//.......problemmmmmmmm........
void tiger_input(){
   cordinatew();
   int k=0;
   POINT cursor;
   int x,y,q;
   

   while(1){
      cordinatew();
      if(GetAsyncKeyState(VK_LBUTTON)){
      GetCursorPos(&cursor);
      x=cursor.x;
      y=cursor.y-20;

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                if(board2[i][j]=='*'){
                   for( q=0;q<=s_track;q++){
                        if(i==scope_track[q].x && j==scope_track[q].y){

                           board2[i][j]='T';
                           board2[tig_track.x][tig_track.y]='*';
                           cout<<scope_track[q].x<<" "<<scope_track[q].y<<"hvjhfchv";
                           cleardevice();
                           board_view();
                           k=1;
                           tiger_suc_input=6; //tiger succes input
                           break;
                          
                          // break;
                        }else if(i==kill_scope_track[q].x && j==kill_scope_track[q].y){
                           //cout<<kill_scope_track[q].x<<kill_scope_track[q].y<<endl;

                           cordinatew();
                           board2[i][j]='T';
                           board2[tig_track.x][tig_track.y]='*';
                           board2[goat_track[q].x][goat_track[q].y]='*';
                           killed_goat++;

                           //cout<<killed_goat<<endl;
                          // cout<<tig_track.x<<tig_track.y;
                          // cout<<goat_track[q].x<<goat_track[q].y<<endl;
                          // total_goat--;
                          // cout<<"total_goat="<<total_goat<<"/n";
                           cordinatew();
                           cleardevice();
                           board_view();
                           k=1;
                           tiger_suc_input=6; //tiger succes input
                           break;

                        }
                       
                     }   
                        for(q=0;q<=s_track;q++){ scope_track[q].x=125; scope_track[q].y=125; kill_scope_track[q].x=125; kill_scope_track[q].y=125; 
                       /* goat_track[q].x=0; goat_track[q].y=0;*/}           
                    k=1;
                  } else if(board2[i][j]=='T') k=1; 
                  
            }
         }
      }
   }        
   if(k==1) break;      
}


}





int tiger_possible_move(int m1,int m2){ 
     int   move_count=0;
     if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
     (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

        if(board2[m1-1][m2+1]=='*'){  move_count++;}
        else if(board2[m1-1][m2+1]=='G'){
            if(board2[m1-2][m2+2]=='*') move_count++;}

        if(board2[m1+1][m2-1]=='*'){ move_count++;}
        else if(board2[m1+1][m2-1]=='G'){
            if(board2[m1+2][m2-2]=='*') move_count++;}

        if(board2[m1-1][m2-1]=='*'){ move_count++;}
        else if(board2[m1-1][m2-1]=='G'){
            if(board2[m1-2][m2-2]=='*') move_count++;}    
        
        if(board2[m1+1][m2+1]=='*'){ move_count++;}
        else if(board2[m1+1][m2+1]=='G'){
            if(board2[m1+2][m2+2]=='*') move_count++;}

        if(board2[m1-1][m2]=='*'){ move_count++;}
        else if(board2[m1-1][m2]=='G'){
            if(board2[m1-2][m2]=='*') move_count++;}   


        if(board2[m1+1][m2]=='*'){ move_count++;}
        else if(board2[m1+1][m2]=='G'){
            if(board2[m1+2][m2]=='*') move_count++;}  

         if(board2[m1][m2+1]=='*'){move_count++;}
         else if(board2[m1][m2+1]=='G'){
            if(board2[m1][m2+2]=='*') move_count++;}      
          
        if(board2[m1][m2-1]=='*'){ move_count++;}
        else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') move_count++;} 
        
    }   


    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

                if(board2[m1-1][m2]=='*'){move_count++;}
        else if(board2[m1-1][m2]=='G'){
            if(board2[m1-2][m2]=='*') move_count++;}   

        if(board2[m1+1][m2]=='*'){ move_count++;}
        else if(board2[m1+1][m2]=='G'){
            if(board2[m1+2][m2]=='*') move_count++;}  

         if(board2[m1][m2+1]=='*'){ move_count++;}
         else if(board2[m1][m2+1]=='G'){
            if(board2[m1][m2+2]=='*') move_count++;}      
          
        if(board2[m1][m2-1]=='*'){ move_count++;}
        else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') move_count++;} 

    }


    return move_count;

  }




int tiger_info(){
       int temp=0;
       total_move=0;  //.............newwwwwwwwwwwwwww cmnt...............
       for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){ 
                  if(board2[i][j]=='T'){
                      
                      temp=tiger_possible_move(i,j);
                      // cout<<temp;
                      total_move=total_move + temp;
                      if(temp==0) {  setlinestyle(0,0,10); setcolor(RED);  rectangle(board[i][j].x-28,board[i][j].y-28,board[i][j].x+28, board[i][j].y+28);}
                    }
                }
        }
        return total_move;
   }    




void goat_scope(){
   int k = 0;
   POINT cursor;
   int x=0,y=0;
  

   while(1){
   if(GetAsyncKeyState(VK_LBUTTON)){
      GetCursorPos(&cursor);
      x=cursor.x;
      y=cursor.y-20;

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                if(board2[i][j]=='G'){

                  goat_ind.x=i;
                  goat_ind.y=j;
                  cleardevice();
                  board_view(); 
                   
                  goat_scope_print(i,j); 
                  goat_input_2();
                  k=1;
               } 
            }
         }
      }//return k;
    //  if(k==1) break;
   }  if(k==1) break;             
}

  
}          




void goat_scope_print(int m1,int m2){
   setlinestyle(0,0,10);
   setcolor(GREEN);
   cordinatew();
   s_track=0; //move_count=0;

   //for(int q=0;q<=7;q++){scope_track[q].x=0;scope_track[q].y=0;}

   //int   move_count=0;
    if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
   (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

      if(board2[m1-1][m2+1]=='*'){ rectangle(board[m1-1][m2+1].x-20,board[m1-1][m2+1].y-20,board[m1-1][m2+1].x+20, board[m1-1][m2+1].y+20);
         g_scope_track[s_track].x=m1-1; g_scope_track[s_track].y=m2+1;  s_track++;}
       

           

        if(board2[m1+1][m2-1]=='*'){ rectangle(board[m1+1][m2-1].x-20,board[m1+1][m2-1].y-20,board[m1+1][m2-1].x+20, board[m1+1][m2-1].y+20);
        g_scope_track[s_track].x=m1+1; g_scope_track[s_track].y=m2-1; s_track++;}
        



        if(board2[m1-1][m2-1]=='*'){ rectangle(board[m1-1][m2-1].x-20,board[m1-1][m2-1].y-20,board[m1-1][m2-1].x+20, board[m1-1][m2-1].y+20);
         g_scope_track[s_track].x=m1-1; g_scope_track[s_track].y=m2-1; s_track++;}
       
        


        if(board2[m1+1][m2+1]=='*'){ rectangle(board[m1+1][m2+1].x-20,board[m1+1][m2+1].y-20,board[m1+1][m2+1].x+20, board[m1+1][m2+1].y+20);
         g_scope_track[s_track].x=m1+1; g_scope_track[s_track].y=m2+1; s_track++;}
        



        if(board2[m1-1][m2]=='*'){ rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         g_scope_track[s_track].x=m1-1; g_scope_track[s_track].y=m2; s_track++;}
        



        if(board2[m1+1][m2]=='*'){ rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         g_scope_track[s_track].x=m1+1; g_scope_track[s_track].y=m2;  s_track++;}
         



         if(board2[m1][m2+1]=='*'){ rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
          g_scope_track[s_track].x=m1; g_scope_track[s_track].y=m2+1;  s_track++;}
         
          


        if(board2[m1][m2-1]=='*'){  rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         g_scope_track[s_track].x=m1; g_scope_track[s_track].y=m2-1; s_track++;}
       
        
    }   


    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

                if(board2[m1-1][m2]=='*'){ rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         g_scope_track[s_track].x=m1-1; g_scope_track[s_track].y=m2;  s_track++;}
       
           

        if(board2[m1+1][m2]=='*'){ rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         g_scope_track[s_track].x=m1+1; g_scope_track[s_track].y=m2; s_track++;}
        


         if(board2[m1][m2+1]=='*'){rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
         g_scope_track[s_track].x=m1; g_scope_track[s_track].y=m2+1;  s_track++;}
         

          
        if(board2[m1][m2-1]=='*'){ rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         g_scope_track[s_track].x=m1; g_scope_track[s_track].y=m2-1;  s_track++;  }
        

    }

   /*
    for(int i=0;i<s_track;i++){
           cout<<scope_track[i].x<<" "<<scope_track[i].y<<"\n";
        }
        cout<<"........";

          for(int m=0;m<5;m+=1){cout<<"  "<<m;}
   cout<<"\n";          
     for(int i=0;i<5;i++){
        cout<<i;
         for(int j=0;j<5;j++){
           cout<< " " << board2[i][j]<<" ";
             }cout<<"\n"; 
        } */



   

}





//.......problemmmmmmmm........
void goat_input_2 (){
   cordinatew();
   int k=0;
   POINT cursor;
   int x,y,q;
   

   while(1){
      cordinatew();
      if(GetAsyncKeyState(VK_LBUTTON)){
      GetCursorPos(&cursor);
      x=cursor.x;
      y=cursor.y-20;

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                if(board2[i][j]=='*'){
                   for( q=0;q<=s_track;q++){
                        if(i==g_scope_track[q].x && j==g_scope_track[q].y){

                           board2[i][j]='G';
                           board2[goat_ind.x][goat_ind.y]='*';

                          // cleardevice();
                          // board_view();
                           k=1;
                           goat_suc_input=5; //tiger succes input
                           break;
                          
                          // break;
                        }
                       
                     }   
                        for(q=0;q<=s_track;q++){g_scope_track[q].x=0; g_scope_track[q].y=0;  goat_ind.x=0; goat_ind.y=0;}           
                    k=1;
                  } else if(board2[i][j]=='G') k=1;
                  
            }
         }
      }
   }        
   if(k==1) break;      
}


}



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


void welcome(){

    settextstyle(8,0,5);
    setcolor(WHITE);

    outtextxy(650,200,"WELCOME TO");
    
    outtextxy(530,250,"THE BAGH BONDI GAME!!");

    settextstyle(8,0,3);
    outtextxy(650,430,"WAIT A SECCOND.....");
    
    delay(700);

}


void two_player_mode(){
   cleardevice();
   board_view();

   while(1){
      tiger_suc_input=0;
      goat_suc_input=0;

      while(1){                 //.....goat input loop.......
         if(total_goat>0){
            goat_input(); 
            if(goat_suc_input==5){
              cleardevice();
              board_view();
              break;
            }
         }else if(total_goat==0){
            goat_scope();
            if(goat_suc_input==5){
              cleardevice();
              board_view();
              break;
            }
         }

      }


      if( goat_win_flag!=0){          //.....Tiger input loop........
         while(1){
            tiger_scope(); 
            if(tiger_suc_input==6) break;
         
         } 
      }


      if(killed_goat==5){      //.....TIGER WINNING SCREEEN.......
        tiger_win_screen();
        break;
      }

      if(goat_win_flag==0){   //.....GOAT WINNING SCREEN..........
        goat_win_screen();
        break;

      }



   }   

}

int menu(){

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
                   break;

                }
            }
        }
        if(mode_start) break;
    }
    return mode_start;

   // getch();
   // closegraph();
}




int ai_mode(){
    cleardevice();           
    readimagefile("UNDER_DEVELOP.jpg",500,200,1100, 500);
    settextstyle(8,0,3);
    setcolor(WHITE);
    outtextxy(670,530,"UNDER DEVELOPING....");

    setcolor(BLUE);
    rectangle(1255,90,1500,145);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(1256, 91, BLUE);

    settextstyle(10,0,4);
    setcolor(WHITE);
    outtextxy(1260,100,"BACK TO MENU");


    
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
            }
        }
        if(back_menu_flag) break;
    }
    return back_menu_flag;


    getch();
    //closegraph();

}



