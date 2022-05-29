#include"aiMode.h"
#include"globalVariable.h"
#include"tiger.h"
#include"goat.h"
#include"aiMiniMax.h"

void ai_mode(){
    cleardevice();
    // readimagefile("UNDER_DEVELOP.jpg",500,200,1100, 500);
    //  settextstyle(8,0,3);
    //  setcolor(WHITE);
    //  outtextxy(670,530,"UNDER DEVELOPING....");

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(610,90,"PLAY AS");


    setcolor(BLUE);
    rectangle(520,140,680,200);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(521, 141, BLUE);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(525,145,"TIGER");

    setcolor(BLUE);
    rectangle(760,140,930,200);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(761, 141, BLUE);

    settextstyle(10,0,5);
    setcolor(WHITE);
    outtextxy(770,150,"GOAT");


    setcolor(BLUE);
    rectangle(1255,90,1500,145);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(1256, 91, BLUE);

    settextstyle(10,0,4);
    setcolor(WHITE);
    outtextxy(1260,100,"BACK TO MENU");


    back_menu_flag=0;
    ai_goat_mode=0;
    ai_tiger_mode=0;

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
          else if((x>520 && x<680) && (y>140 && y<200)){
            ai_goat();
            ai_tiger_mode=1;
            break;
          }
          else if((x>760 && x<930) && (y>140 && y<200)){
            ai_tiger();
            ai_goat_mode=1;
            break;
          }

        }
      }

      if(back_menu_flag==1) break;
      else if(ai_tiger_mode==1){
        break;
      }
      else if(ai_goat_mode==1){
        break;
      }

    }



  }



void ai_goat(){

    board_initialize();
    ai_killed_goat=0;
    g_count=20;
    total_goat=20;
    killed_goat=0;

    board_view();
    goats_turn_print();

    while(1){

        while(1){
            int value;
            board2_TO_ai_board();
            ai_turn="GOAT";

            value = ai_goat_minimax(0, -infinity, +infinity);

            if(move_from[0]==999||move_from[1]==999){
                board2[ move_to[0] ] [  move_to[1]  ]='G';
                g_count--;
                total_goat--;
                delay(4000);


                board_view();
                tigers_turn_print();
            }
            else{
                board2[ move_to[0] ] [  move_to[1]  ]='G';
                board2[ move_from[0] ] [  move_from[1]  ]='*';
                total_goat=0;
                g_count=0;
                delay(4000);

                board_view();
                tigers_turn_print();
            }

            if(value==infinity) {
                delay(4000);
                goat_win_screen();
               //cout<<"CONGRATULATIONS!! GOAT WIN THE MATCH!!!";
                break;
            }
            else if(value==(-infinity)){
                delay(4000);
                tiger_win_screen();
                //cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!";
                break;
            }

            break;
        }

        if(goat_win_flag!=0){
            while(1){
                tiger_scope();
                if(tiger_suc_input==6) break;
            }
        }
        else break;

        if(killed_goat==5){
            tiger_win_screen();
            break;
        }
    }

}



void ai_tiger(){
    board_initialize();
    ai_killed_goat=0;
    g_count=20;
    total_goat=20;
    killed_goat=0;


    board_view();
    goats_turn_print();

    while(1){
        int value;
        goat_suc_input=0;
        board2_TO_ai_board();

        while(1){
            if(total_goat>0){
                goat_input_WhenGoatNumber_NotZero();
                if(goat_suc_input==5){
                    cleardevice();


                    board_view();
                    tigers_turn_print();
                    break;
                }
            }
            else if(total_goat==0){
                goat_move_scope();
                if(goat_suc_input==5){
                    cleardevice();

                    board_view();
                    tigers_turn_print();
                    break;
                }
            }
        }

        while(1){

            ai_turn="TIGER";
            board2_TO_ai_board();

            value = ai_tiger_minimax(0, -infinity, +infinity);

            if(tiger_kill_move_flag==1){
                board2[ move_to[0] ] [ move_to[1] ]='T';
                board2[ move_from[0] ] [ move_from[1] ]='*';
                board2[ (move_to[0] + move_from[0] )/2 ] [ (move_to[1] + move_from[1] )/2 ] = '*';
                ai_killed_goat++;
                tiger_kill_move_flag = 0;
                delay(4000);

                board_view();
                goats_turn_print();
                break;
            }
            else{
                board2[ move_to[0] ] [ move_to[1] ]='T';
                board2[ move_from[0] ] [ move_from[1] ]='*';
                delay(4000);

                board_view();
                goats_turn_print();
                break;

            }

        }

        if(value==infinity) {
            delay(4000);
            tiger_win_screen();
            //cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!";
            break;
        }
        else if(value==(-infinity)){
            delay(4000);
            goat_win_screen() ;
            //cout<<"CONGRATULATIONS!! GOAT WIN THE MATCH!!!";
            break;
        }

    }

}








