
#include"tiger.h"
#include"twoPlayerMode.h"
#include"globalVariable.h"

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

   /*

   //new added for debugging
   for(int m=0;m<5;m+=1){ cout<<"  "<<m;}
   cout<<"\n";
    for(int i=0;i<5;i++){
        cout<<i;
        for(int j=0;j<5;j++){
           cout<<" "<<board2[i][j]<<" ";
        }cout<<"\n";
    }

    */

    char *print_goatNum = numToString(total_goat);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(70,90,"GOAT REMAIN:");

    settextstyle(10,0,5);
    setcolor(GREEN);
    outtextxy(380,90,print_goatNum);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(70,140,"KILLED GOAT:");

    if(ai_killed_goat==0){
        char *printKillGoatNum = numToString(killed_goat);
        settextstyle(10,0,5);
        setcolor(RED);
        outtextxy(380,140,printKillGoatNum);
    }
    else{
        char *printAiKillGoatNum = numToString(ai_killed_goat);
        settextstyle(10,0,5);
        setcolor(RED);
        outtextxy(380,140,printAiKillGoatNum);
    }



   goat_win_flag=tiger_info();


}


char* numToString(int num){

    char *str = new char[1];
    int i=0;
    if(num>0){
        while(num){
            str[i++] = '0' + num%10;
            num = num/10;
        }
    }
    else{
        str[i] = '0';
    }
    str[i] = '\0';
    strrev(str);

    return str;
}



void goats_turn_print(){
    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(70,200,"GOAT'S TURN");

}
void tigers_turn_print(){
    settextstyle(10,0,5);
    setcolor(RED);
    outtextxy(70,200,"TIGER'S TURN");
}







