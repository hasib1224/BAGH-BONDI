

#include"goat.h"
#include"globalVariable.h"

void goat_input_WhenGoatNumber_NotZero(){
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

                     tigers_turn_print();
                     k=1;break;

                  }
               }
            }
         }

        if(k==1){ break;}
      }
   }


}


void goat_input_WhenGoatNumber_Zero(){
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
                           k=1;
                           goat_suc_input=5;

                           tigers_turn_print();
                           break;

                        }

                     }

                     for(q=0;q<=s_track;q++){
                        g_scope_track[q].x=0;
                        g_scope_track[q].y=0;
                        goat_ind.x=0;
                        goat_ind.y=0;
                     }

                     k=1;

                  }
                  else if(board2[i][j]=='G') k=1;

               }
            }
         }
      }
      if(k==1){break;}
   }


}









