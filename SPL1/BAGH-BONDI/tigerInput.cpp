
#include"tiger.h"
#include"globalVariable.h"

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

                           cleardevice();
                           board_view();
                           goats_turn_print();

                           k=1;
                           tiger_suc_input=6;
                           break;

                        }
                        else if(i==kill_scope_track[q].x && j==kill_scope_track[q].y){

                           cordinatew();
                           board2[i][j]='T';
                           board2[tig_track.x][tig_track.y]='*';
                           board2[goat_track[q].x][goat_track[q].y]='*';
                           killed_goat++;

                           cordinatew();
                           cleardevice();

                           board_view();
                           goats_turn_print();

                           k=1;
                           tiger_suc_input=6;
                           break;

                        }

                     }

                     for(q=0;q<8;q++){
                        scope_track[q].x=125;
                        scope_track[q].y=125;
                        kill_scope_track[q].x=125;
                        kill_scope_track[q].y=125;
                     }

                     k=1;
                  }

                  else if(board2[i][j]=='T') k=1;

               }
            }
         }
      }

      if(k==1) break;
   }


}

