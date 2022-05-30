

#include"tiger.h"
#include"globalVariable.h"

void tiger_scope_print(int m1,int m2){

    for(int q=0;q<8;q++){
      scope_track[q].x=125;
      scope_track[q].y=125;
      kill_scope_track[q].x=125;
      kill_scope_track[q].y=125;
   }


   tiger_suc_input=0;

   setlinestyle(0,0,10);
   setcolor(GREEN);
   cordinatew();
   s_track=0;

   if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
      (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

      if(board2[m1-1][m2+1]=='*'){
         rectangle(board[m1-1][m2+1].x-20,board[m1-1][m2+1].y-20,board[m1-1][m2+1].x+20, board[m1-1][m2+1].y+20);

         scope_track[s_track].x=m1-1;
         scope_track[s_track].y=m2+1;
         s_track++;
      }
      else if(board2[m1-1][m2+1]=='G'){

         if(board2[m1-2][m2+2]=='*') {
            rectangle(board[m1-2][m2+2].x-20,board[m1-2][m2+2].y-20,board[m1-2][m2+2].x+20, board[m1-2][m2+2].y+20);

            kill_scope_track[s_track].x=m1-2;
            kill_scope_track[s_track].y=m2+2;

            goat_track[s_track].x=m1-1;
            goat_track[s_track].y=m2+1;
            s_track++;
         }
      }



      if(board2[m1+1][m2-1]=='*'){
         rectangle(board[m1+1][m2-1].x-20,board[m1+1][m2-1].y-20,board[m1+1][m2-1].x+20, board[m1+1][m2-1].y+20);

         scope_track[s_track].x=m1+1;
         scope_track[s_track].y=m2-1;
         s_track++;
      }
      else if(board2[m1+1][m2-1]=='G'){
         if(board2[m1+2][m2-2]=='*') {
            rectangle(board[m1+2][m2-2].x-20,board[m1+2][m2-2].y-20,board[m1+2][m2-2].x+20, board[m1+2][m2-2].y+20);

            kill_scope_track[s_track].x=m1+2; kill_scope_track[s_track].y=m2-2;
            goat_track[s_track].x=m1+1;
            goat_track[s_track].y=m2-1;
            s_track++;
         }
      }


      if(board2[m1-1][m2-1]=='*'){
         rectangle(board[m1-1][m2-1].x-20, board[m1-1][m2-1].y-20, board[m1-1][m2-1].x+20, board[m1-1][m2-1].y+20);

         scope_track[s_track].x=m1-1;
         scope_track[s_track].y=m2-1;
         s_track++;
      }
      else if(board2[m1-1][m2-1]=='G'){
         if(board2[m1-2][m2-2]=='*'){rectangle(board[m1-2][m2-2].x-20,board[m1-2][m2-2].y-20,board[m1-2][m2-2].x+20, board[m1-2][m2-2].y+20);

            kill_scope_track[s_track].x=m1-2;
            kill_scope_track[s_track].y=m2-2;

            goat_track[s_track].x=m1-1;
            goat_track[s_track].y=m2-1;
            s_track++;
         }
      }


      if(board2[m1+1][m2+1]=='*'){
         rectangle(board[m1+1][m2+1].x-20,board[m1+1][m2+1].y-20,board[m1+1][m2+1].x+20, board[m1+1][m2+1].y+20);

         scope_track[s_track].x=m1+1;
         scope_track[s_track].y=m2+1;
         s_track++;
      }

      else if(board2[m1+1][m2+1]=='G'){
         if(board2[m1+2][m2+2]=='*') {
            rectangle(board[m1+2][m2+2].x-20,board[m1+2][m2+2].y-20,board[m1+2][m2+2].x+20, board[m1+2][m2+2].y+20);

            kill_scope_track[s_track].x=m1+2;
            kill_scope_track[s_track].y=m2+2;

            goat_track[s_track].x=m1+1;
            goat_track[s_track].y=m2+1;
            s_track++;
         }
      }



      if(board2[m1-1][m2]=='*'){
         rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);

         scope_track[s_track].x=m1-1;
         scope_track[s_track].y=m2;
         s_track++;
      }

      else if(board2[m1-1][m2]=='G'){
         if(board2[m1-2][m2]=='*') {
            rectangle(board[m1-2][m2].x-20,board[m1-2][m2].y-20,board[m1-2][m2].x+20, board[m1-2][m2].y+20);

            kill_scope_track[s_track].x=m1-2;
            kill_scope_track[s_track].y=m2;

            goat_track[s_track].x=m1-1;
            goat_track[s_track].y=m2;
            s_track++;
         }
      }



      if(board2[m1+1][m2]=='*'){
         rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);

         scope_track[s_track].x=m1+1;
         scope_track[s_track].y=m2;
         s_track++;
      }
        else if(board2[m1+1][m2]=='G'){
            if(board2[m1+2][m2]=='*') {
                rectangle(board[m1+2][m2].x-20,board[m1+2][m2].y-20,board[m1+2][m2].x+20, board[m1+2][m2].y+20);

                kill_scope_track[s_track].x=m1+2; kill_scope_track[s_track].y=m2;
                goat_track[s_track].x=m1+1; goat_track[s_track].y=m2;  s_track++;
            }
        }



      if(board2[m1][m2+1]=='*'){
         rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);

         scope_track[s_track].x=m1;
         scope_track[s_track].y=m2+1;
         s_track++;
      }
      else if(board2[m1][m2+1]=='G'){
         if(board2[m1][m2+2]=='*') {
            rectangle(board[m1][m2+2].x-20,board[m1][m2+2].y-20,board[m1][m2+2].x+20, board[m1][m2+2].y+20);

            kill_scope_track[s_track].x=m1;
            kill_scope_track[s_track].y=m2+2;

            goat_track[s_track].x=m1;
            goat_track[s_track].y=m2+1;
            s_track++;
         }
      }


      if(board2[m1][m2-1]=='*'){
         rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);

         scope_track[s_track].x=m1;
         scope_track[s_track].y=m2-1;
         s_track++;
      }

      else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') {
            rectangle(board[m1][m2-2].x-20,board[m1][m2-2].y-20,board[m1][m2-2].x+20, board[m1][m2-2].y+20);

            kill_scope_track[s_track].x=m1;
            kill_scope_track[s_track].y=m2-2;

            goat_track[s_track].x=m1;
            goat_track[s_track].y=m2-1;
            s_track++;
         }
      }


   }


   else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
      (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

      if(board2[m1-1][m2]=='*'){
         rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);

         scope_track[s_track].x=m1-1;
         scope_track[s_track].y=m2;
         s_track++;
      }
      else if(board2[m1-1][m2]=='G'){
         if(board2[m1-2][m2]=='*') { rectangle(board[m1-2][m2].x-20,board[m1-2][m2].y-20,board[m1-2][m2].x+20, board[m1-2][m2].y+20);

            kill_scope_track[s_track].x=m1-2;
            kill_scope_track[s_track].y=m2;

            goat_track[s_track].x=m1-1;
            goat_track[s_track].y=m2;
            s_track++;
         }
      }


      if(board2[m1+1][m2]=='*'){
         rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);

         scope_track[s_track].x=m1+1;
         scope_track[s_track].y=m2;
         s_track++;
      }
      else if(board2[m1+1][m2]=='G'){
         if(board2[m1+2][m2]=='*') {
            rectangle(board[m1+2][m2].x-20,board[m1+2][m2].y-20,board[m1+2][m2].x+20, board[m1+2][m2].y+20);

            kill_scope_track[s_track].x=m1+2;
            kill_scope_track[s_track].y=m2;

            goat_track[s_track].x=m1+1;
            goat_track[s_track].y=m2;
            s_track++;
         }
      }


      if(board2[m1][m2+1]=='*'){
         rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);

         scope_track[s_track].x=m1;
         scope_track[s_track].y=m2+1;
         s_track++;
      }

      else if(board2[m1][m2+1]=='G'){
         if(board2[m1][m2+2]=='*')  {
            rectangle(board[m1][m2+2].x-20,board[m1][m2+2].y-20,board[m1][m2+2].x+20, board[m1][m2+2].y+20);

            kill_scope_track[s_track].x=m1;
            kill_scope_track[s_track].y=m2+2;

            goat_track[s_track].x=m1;
            goat_track[s_track].y=m2+1;
            s_track++;
         }
      }


      if(board2[m1][m2-1]=='*'){
         rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);

         scope_track[s_track].x=m1;
         scope_track[s_track].y=m2-1;
         s_track++;
      }
      else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*')  {
            rectangle(board[m1][m2-2].x-20,board[m1][m2-2].y-20,board[m1][m2-2].x+20, board[m1][m2-2].y+20);

            kill_scope_track[s_track].x=m1;
            kill_scope_track[s_track].y=m2-2;

            goat_track[s_track].x=m1;
            goat_track[s_track].y=m2-1;
            s_track++;
         }
      }

   }

}





