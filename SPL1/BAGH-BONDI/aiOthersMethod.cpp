

#include"aiMiniMax.h"
#include"globalVariable.h"

bool ai_tiger_win(){
    if(ai_killed_goat==5){
        return true;
    }
    else {return false; }

}

int trapped_tigers(){
    int trapped_tiger_num=0;
    int move_counter=0;

    for(int m1=0;m1<5;m1++){
        for(int m2=0;m2<5;m2++){
           if(ai_board[m1][m2]=='T'){
                move_counter=0;


             if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
                 (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){



                    if( ai_board[m1-1][m2+1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2+1]=='G' && ai_board[m1-2][m2+2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1+1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2-1]=='G' && ai_board[m1+2][m2-2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1-1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2-1]=='G' && ai_board[m1-2][m2-2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1+1][m2+1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2+1]=='G' && ai_board [m1+2][m2+2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1-1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2]=='G' &&  ai_board[m1-2][m2]=='*'){
                        move_counter++;
                    }
                    if( ai_board[m1+1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
                        move_counter++;
                    }
                    if( ai_board[m1][m2+1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
                        move_counter++;
                    }
                    if( ai_board[m1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1][m2-1]=='G' && ai_board[m1][m2-2]=='*'){
                        move_counter++;
                    }


                }

             else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
                    (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

                    if( ai_board[m1-1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2]=='G' && ai_board[m1-2][m2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1+1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1][m2+1]=='*'){
                       move_counter++;
                    }
                    else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1][m2-1]=='G' &&  ai_board[m1][m2-2]=='*'){
                        move_counter++;
                    }

                }

                if(move_counter==0){
                    trapped_tiger_num++;
                }

            }
        }

    }
    return trapped_tiger_num;

}

bool ai_goat_win(){

    if( trapped_tigers()==4){
        return true;
    }
    else return false;

}

int ghost_goats(){
    int ghost_goats=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(ai_board[i][j]=='T'){

                if((i==0 && j==0)||(i==0 && j==2)||(i==0 && j==4)||(i==1 && j==1)||(i==1 && j==3)|| (i==2 && j==0)||(i==2 && j==2)||
                 (i==2 && j==4)||(i==3 && j==1)||(i==3 && j==3)|| (i==4 && j==0)||(i==4 && j==2)||(i==4 && j==4)){


                    if(ai_board[i-1][j+1]=='G' && ai_board[i-2][j+2]=='G'){
                        ghost_goats++;
                    }

                    if(ai_board[i+1][j-1]=='G' && ai_board[i+2][j-2]=='G'){
                        ghost_goats++;
                    }


                    if(ai_board[i-1][j-1]=='G' && ai_board[i-2][j-2]=='G'){
                        ghost_goats++;
                    }


                    if(ai_board[i+1][j+1]=='G' && ai_board[i+2][j+2]=='G'){
                      ghost_goats++;
                    }


                    if(ai_board[i-1][j]=='G' && ai_board[i-2][j]=='G'){
                        ghost_goats++;
                    }


                    if(ai_board[i+1][j]=='G' && ai_board[i+2][j]=='G'){
                     ghost_goats++;
                    }


                    if(ai_board[i][j+1]=='G' && ai_board[i][j+2]=='G'){
                     ghost_goats++;
                    }

                    if(ai_board[i][j-1]=='G' && ai_board[i][j-2]=='G' ){
                        ghost_goats++;
                    }

                }

                else if((i==0 && j==1)||(i==0 && j==3)||(i==1 && j==0)||(i==1 && j==2)||(i==1 && j==4)|| (i==2 && j==1)||(i==2 && j==3)||
                    (i==3 && j==0)||(i==3 && j==2)||(i==3 && j==4)|| (i==4 && j==1)||(i==4 && j==3)){

                    if(ai_board[i-1][j]=='G' && ai_board[i-2][j]=='G'){
                        ghost_goats++;
                    }

                    if(ai_board[i+1][j]=='G' && ai_board[i+2][j]=='G' ){
                        ghost_goats++;
                    }


                    if(ai_board[i][j+1]=='G' && ai_board[i][j+2]=='G'){
                      ghost_goats++;
                    }

                    if(ai_board[i][j-1]=='G' && ai_board[i][j-2]=='G'){
                        ghost_goats++;
                    }

                }

            }
        }
    }

    return ghost_goats;

}


int possible_captures(){
    int possible_captures=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(ai_board[i][j]=='T'){

                if((i==0 && j==0)||(i==0 && j==2)||(i==0 && j==4)||(i==1 && j==1)||(i==1 && j==3)|| (i==2 && j==0)||(i==2 && j==2)||
                 (i==2 && j==4)||(i==3 && j==1)||(i==3 && j==3)|| (i==4 && j==0)||(i==4 && j==2)||(i==4 && j==4)){


                    if(ai_board[i-1][j+1]=='G' && ai_board[i-2][j+2]=='*'){
                        possible_captures++;
                    }

                    if(ai_board[i+1][j-1]=='G' && ai_board[i+2][j-2]=='*'){
                        possible_captures++;
                    }


                    if(ai_board[i-1][j-1]=='G' && ai_board[i-2][j-2]=='*'){
                        possible_captures++;
                    }


                    if(ai_board[i+1][j+1]=='G' && ai_board[i+2][j+2]=='*'){
                      possible_captures++;
                    }


                    if(ai_board[i-1][j]=='G' && ai_board[i-2][j]=='*'){
                        possible_captures++;
                    }


                    if(ai_board[i+1][j]=='G' && ai_board[i+2][j]=='*'){
                     possible_captures++;
                    }


                    if(ai_board[i][j+1]=='G' && ai_board[i][j+2]=='*'){
                     possible_captures++;
                    }

                    if(ai_board[i][j-1]=='G' && ai_board[i][j-2]=='*' ){
                        possible_captures++;
                    }

                }

                else if((i==0 && j==1)||(i==0 && j==3)||(i==1 && j==0)||(i==1 && j==2)||(i==1 && j==4)|| (i==2 && j==1)||(i==2 && j==3)||
                    (i==3 && j==0)||(i==3 && j==2)||(i==3 && j==4)|| (i==4 && j==1)||(i==4 && j==3)){

                    if(ai_board[i-1][j]=='G' && ai_board[i-2][j]=='*'){
                       possible_captures++;
                    }

                    if(ai_board[i+1][j]=='G' && ai_board[i+2][j]=='*' ){
                        possible_captures++;
                    }


                    if(ai_board[i][j+1]=='G' && ai_board[i][j+2]=='*'){
                      possible_captures++;
                    }

                    if(ai_board[i][j-1]=='G' && ai_board[i][j-2]=='*'){
                       possible_captures++;
                    }

                }

            }
        }
    }

    return possible_captures;

}



int ai_goat_position_evaluate(){

    if (ai_tiger_win())
        return -infinity;

    if (ai_goat_win(  )){

        return +infinity;
    }

    return (-1000 * ai_killed_goat + 300 * ghost_goats() - 200 * possible_captures() + 500 * trapped_tigers());
    //cout<<"dhukse";
}


int ai_tiger_position_evaluate(){

    if (ai_tiger_win())
        return +infinity;
    if (ai_goat_win( ))
        return -infinity;

    return (1000 * ai_killed_goat - 300 * ghost_goats() + 200 * possible_captures() - 500 * trapped_tigers() );

}



int  ai_tiger_move_type( int row, int col, int counter, struct Move ai_move[21] ){
    int  m1=row;
    int m2=col;

    int   move_count=0;
    if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
    (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

        if( ai_board[m1-1][m2+1]=='*'){
            ai_move[counter].type= TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2+1;
            counter++;
        }
        else if( ai_board[m1-1][m2+1]=='G' && ai_board[m1-2][m2+2]=='*'){
            ai_move[counter].type= TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2+2;
            counter++;

        }

        if( ai_board[m1+1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2-1;
            counter++;
        }
        else if( ai_board[m1+1][m2-1]=='G' && ai_board[m1+2][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2-2;
            counter++;

        }

        if( ai_board[m1-1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2-1;
            counter++;



        }
        else if( ai_board[m1-1][m2-1]=='G' && ai_board[m1-2][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2-2;
            counter++;


        }

        if( ai_board[m1+1][m2+1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        else if( ai_board[m1+1][m2+1]=='G' && ai_board [m1+2][m2+2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2+2;
            counter++;


        }

        if( ai_board[m1-1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;


        }
        else if( ai_board[m1-1][m2]=='G' &&  ai_board[m1-2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2;
            counter++;


        }
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;


        }
        else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2;
            counter++;


        }
        if( ai_board[m1][m2+1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+2;
            counter++;


        }
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;


        }
        else if( ai_board[m1][m2-1]=='G' && ai_board[m1][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-2;
            counter++;

        }


    }
    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

        if( ai_board[m1-1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;
        }
        else if( ai_board[m1-1][m2]=='G' && ai_board[m1-2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2;
            counter++;

        }
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;
        }
        else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2;
            counter++;

        }

        if( ai_board[m1][m2+1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+2;
            counter++;

        }
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;

        }
        else if( ai_board[m1][m2-1]=='G' &&  ai_board[m1][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-2;
            counter++;

        }

    }

    return counter;

  }


int ai_goat_move_type(int row, int col, int counter, struct Move ai_move[21]){


    int  m1=row;
    int m2=col;

    int   move_count=0;
    if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
    (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

        if( ai_board[m1-1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2+1;
            counter++;
        }


        if( ai_board[m1+1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2-1;
            counter++;
        }


        if( ai_board[m1-1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2-1;
            counter++;



        }

        if( ai_board[m1+1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2+1;
            counter++;

        }

        if( ai_board[m1-1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;


        }
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;


        }
        if( ai_board[m1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;


        }

    }

    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

        if( ai_board[m1-1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;
        }
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;
        }

        if( ai_board[m1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;

        }

    }

    return counter;



}




int generate_move_type ( int counter, struct Move ai_move[21] ){

    if(ai_turn=="TIGER"){

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(ai_board[i][j]=='T'){
                    counter = ai_tiger_move_type( i, j, counter , ai_move);
                }
            }
        }
    }

    else if(ai_turn=="GOAT"){

        if(g_count>0){

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(ai_board[i][j]=='*'){

                        ai_move[counter].type=GOAT_PLACE;

                        ai_move[counter].to[0]=i; ai_move[counter].to[1]=j;

                        counter++;

                    }
                }
            }
        }

        else if(g_count==0){

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(ai_board[i][j]=='G'){

                        counter = ai_goat_move_type( i, j, counter ,ai_move);

                    }
                }
            }
        }


    }
    return counter;
}



void ai_goat_move(  int counter, struct Move ai_move[21]){

    ai_board [ai_move[counter].to[0]] [ai_move[counter].to[1]] = 'G';
    ai_board [ai_move[counter].from[0]] [ai_move[counter].from[1]] = '*';
    ai_turn="TIGER";

}

void reverse_ai_goat_move(  int counter, struct Move ai_move[21] ){

    ai_board [ ai_move[counter].to[0]   ] [ ai_move[counter].to[1] ] = '*';
    ai_board [ ai_move[counter].from[0] ] [ ai_move[counter].from[1] ] = 'G';
    ai_turn="GOAT";
}

void ai_goat_place(  int counter, struct Move ai_move[21] ){

    ai_board[ ai_move[counter].to[0] ] [ ai_move[counter].to[1] ]='G';
    ai_turn = "TIGER";

}

void reverse_ai_goat_place( int counter, struct Move ai_move[21]){

    ai_board[ai_move[counter].to[0] ] [ai_move[counter].to[1] ]= '*';
    ai_turn = "GOAT";

}

void ai_tiger_move(  int counter, struct Move ai_move[21]){

    ai_board [ai_move[counter].to[0]] [ai_move[counter].to[1]] = 'T';
    ai_board [ai_move[counter].from[0]] [ai_move[counter].from[1]] = '*';
    ai_turn = "GOAT";


}

void reverse_ai_tiger_move( int counter, struct Move ai_move[21]){

    ai_board [ai_move[counter].to[0]] [ai_move[counter].to[1]] = '*';
    ai_board [ai_move[counter].from[0]] [ai_move[counter].from[1]] = 'T';
    ai_turn="TIGER";

}

void ai_tigers_kill_move( int counter, struct Move ai_move[21]){

    int temp1, temp2;

    temp1 = (ai_move[counter].to[0] + ai_move[counter].from[0] )/2;
    temp2 = (ai_move[counter].to[1] + ai_move[counter].from[1] )/2;


    ai_board [ ai_move[counter].to[0] ] [ ai_move[counter].to[1] ] = 'T' ;

    ai_board [ ai_move[counter].from[0] ] [ ai_move[counter].from[1] ] = '*' ;

    ai_board [temp1] [temp2] = '*' ;    // replacing dead goat position by "*"

    ai_killed_goat++;
    ai_turn="GOAT";

}

void reverse_ai_tigers_kill_move(  int counter, struct Move ai_move[21] ){

    int temp1, temp2;
    temp1 = (ai_move[counter].to[0] + ai_move[counter].from[0] )/2;
    temp2 = (ai_move[counter].to[1] + ai_move[counter].from[1] )/2;

    ai_board [ ai_move[counter].to[0] ] [ ai_move[counter].to[1] ] = '*' ;
    ai_board [ ai_move[counter].from[0] ] [ ai_move[counter].from[1] ] = 'T' ;
    ai_board [temp1] [temp2] = 'G' ;    // reversing dead goat position by "G"

    ai_killed_goat--;
    ai_turn="TIGER";

}

void board2_TO_ai_board(){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        ai_board[i][j] = board2[i][j];

      }
   }

}







