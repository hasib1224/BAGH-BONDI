
#include"tiger.h"
//#include"twoPlayerMode.h"
#include"globalVariable.h"

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
                     tigers_turn_print();

                     tiger_scope_print(i,j);
                     tiger_input();
                     k=1;
                  }
               }
            }
         }

      }

      if(k==1) break;
   }

}




