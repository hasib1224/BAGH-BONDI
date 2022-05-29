#ifndef tiger_h
#define tiger_h

#include"board.h"


void tiger_scope_print(int m1,int m2){
   
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
                           //cout<<scope_track[q].x<<" "<<scope_track[q].y<<"hvjhfchv";
                           cleardevice();
                           board_view();
                           k=1;
                           tiger_suc_input=6; //tiger succes input
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
                           k=1;
                           tiger_suc_input=6; //tiger succes input
                           break;

                        }
                       
                     }   

                     for(q=0;q<=s_track;q++){ 
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
         }
    
      } 

      if(k==1) break;             
   }

}

#endif
























