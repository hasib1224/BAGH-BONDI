
#include"goat.h"
#include"globalVariable.h"


void goat_move_scope(){
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
                    goats_turn_print();

                    goat_move_scope_print(i,j);
                    goat_input_WhenGoatNumber_Zero();
                    k=1;

                  }
               }
            }
        }

      }

      if(k==1) break;

   }


}


void goat_move_scope_print(int m1,int m2){

   setlinestyle(0,0,10);
   setcolor(GREEN);
   cordinatew();

   s_track=0;


   if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
      (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){
      if(board2[m1-1][m2+1]=='*'){
         rectangle(board[m1-1][m2+1].x-20,board[m1-1][m2+1].y-20,board[m1-1][m2+1].x+20, board[m1-1][m2+1].y+20);
         g_scope_track[s_track].x=m1-1;
         g_scope_track[s_track].y=m2+1;
         s_track++;
      }


      if(board2[m1+1][m2-1]=='*'){
         rectangle(board[m1+1][m2-1].x-20,board[m1+1][m2-1].y-20,board[m1+1][m2-1].x+20, board[m1+1][m2-1].y+20);
         g_scope_track[s_track].x=m1+1;
         g_scope_track[s_track].y=m2-1;
         s_track++;
      }


      if(board2[m1-1][m2-1]=='*'){
         rectangle(board[m1-1][m2-1].x-20,board[m1-1][m2-1].y-20,board[m1-1][m2-1].x+20, board[m1-1][m2-1].y+20);
         g_scope_track[s_track].x=m1-1;
         g_scope_track[s_track].y=m2-1;
         s_track++;
      }


      if(board2[m1+1][m2+1]=='*'){
         rectangle(board[m1+1][m2+1].x-20,board[m1+1][m2+1].y-20,board[m1+1][m2+1].x+20, board[m1+1][m2+1].y+20);
         g_scope_track[s_track].x=m1+1;
         g_scope_track[s_track].y=m2+1;
         s_track++;
      }


      if(board2[m1-1][m2]=='*'){
         rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         g_scope_track[s_track].x=m1-1;
         g_scope_track[s_track].y=m2;
         s_track++;
      }


      if(board2[m1+1][m2]=='*'){
         rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         g_scope_track[s_track].x=m1+1;
         g_scope_track[s_track].y=m2;
         s_track++;
      }


      if(board2[m1][m2+1]=='*'){
         rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
         g_scope_track[s_track].x=m1;
         g_scope_track[s_track].y=m2+1;
         s_track++;
      }


      if(board2[m1][m2-1]=='*'){
         rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         g_scope_track[s_track].x=m1;
         g_scope_track[s_track].y=m2-1;
         s_track++;
      }

   }


   else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
      (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){
      if(board2[m1-1][m2]=='*'){
         rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         g_scope_track[s_track].x=m1-1;
         g_scope_track[s_track].y=m2;
         s_track++;
      }


      if(board2[m1+1][m2]=='*'){
         rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         g_scope_track[s_track].x=m1+1;
         g_scope_track[s_track].y=m2;
         s_track++;
      }

      if(board2[m1][m2+1]=='*'){
         rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
         g_scope_track[s_track].x=m1;
         g_scope_track[s_track].y=m2+1;
         s_track++;
      }

      if(board2[m1][m2-1]=='*'){
         rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         g_scope_track[s_track].x=m1;
         g_scope_track[s_track].y=m2-1;
         s_track++;
      }

   }

}











