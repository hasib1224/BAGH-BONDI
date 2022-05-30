
#include"aiMiniMax.h"
#include"globalVariable.h"

int ai_goat_minimax(int depth, int alpha, int beta){

    int stat_value = ai_goat_position_evaluate();

    if(depth == highest_search_depth || stat_value == infinity || stat_value == (-infinity)){

        return stat_value ;
    }


    int counter=0;
    struct Move ai_move[21];
    counter = generate_move_type ( counter, ai_move);


    int val;

    for(int i=0; i<counter;i++){

       switch (ai_move[i].type){
            case TIGER_MOVE:

                ai_tiger_move( i,  ai_move );

               val = ai_goat_minimax( depth+1, alpha, beta);

                if (val < beta){
                    beta = val;
                }
                reverse_ai_tiger_move(i,  ai_move);
                if (alpha >= beta){
                    return beta;
                }
            break;


            case TIGERS_KILL_MOVE:
                ai_tigers_kill_move( i,  ai_move);
                val=ai_goat_minimax( depth+1 ,  alpha,  beta);
                if (val < beta){
                    beta = val;
                }
                reverse_ai_tigers_kill_move(i,  ai_move);
                if (alpha >= beta){
                    return beta;
                }

            break;

            case GOAT_MOVE:
                ai_goat_move(i, ai_move);
                val=ai_goat_minimax(depth+1, alpha, beta);

                if (val > alpha){
                    alpha = val;
                    if (depth == 0){
                        move_from[0] = ai_move[i].from[0];
                        move_from[1] = ai_move[i].from[1];

                        move_to[0] = ai_move[i].to[0];
                        move_to[1] = ai_move[i].to[1];
                    }
                }
                reverse_ai_goat_move(i, ai_move);

                if (alpha >= beta){
                    return alpha;
                }

            break;

            case  GOAT_PLACE:
                ai_goat_place(  i ,ai_move );

                val = ai_goat_minimax(depth+1, alpha, beta);

                if (val > alpha){
                    alpha = val;
                    if (depth == 0){
                        move_from[0] = 999 ;
                        move_from[1] = 999 ;

                        move_to[0] = ai_move[i].to[0];
                        move_to[1] = ai_move[i].to[1];
                    }
                }

                reverse_ai_goat_place(i, ai_move);
                if (alpha >= beta){
                    return alpha;
                }
            break;
        }

    }
    if (ai_turn=="GOAT")
        return alpha ;

    else return beta ;

}


int ai_tiger_minimax(int depth, int alpha, int beta){

    int stat_value = ai_tiger_position_evaluate();

    if(depth == highest_search_depth || stat_value == infinity || stat_value == (-infinity)){

        return stat_value ;
    }



    int counter=0;
    struct Move ai_move[21];
    counter = generate_move_type ( counter, ai_move);


    int val;

    for(int i=0; i<counter;i++){

       switch (ai_move[i].type){

            case TIGER_MOVE:
                ai_tiger_move( i,  ai_move );
                val = ai_tiger_minimax( depth+1, alpha, beta);

                if (val > alpha){
                    alpha = val;
                    if (depth == 0){
                        move_from[0] = ai_move[i].from[0];
                        move_from[1] = ai_move[i].from[1];

                        move_to[0] = ai_move[i].to[0];
                        move_to[1] = ai_move[i].to[1];
                    }
                }
                reverse_ai_tiger_move(i,  ai_move);
                if (alpha >= beta){
                    return alpha;
                }

            break;


            case TIGERS_KILL_MOVE:
                ai_tigers_kill_move( i,  ai_move);
                val=ai_tiger_minimax( depth+1 ,  alpha,  beta);

                if (val > alpha){
                    alpha = val;
                    if (depth == 0){
                        tiger_kill_move_flag = 1;
                        move_from[0] = ai_move[i].from[0];
                        move_from[1] = ai_move[i].from[1];

                        move_to[0] = ai_move[i].to[0];
                        move_to[1] = ai_move[i].to[1];
                    }
                }
                reverse_ai_tigers_kill_move(i,  ai_move);
                if (alpha >= beta){
                    return alpha;
                }

            break;

            case GOAT_MOVE:
                ai_goat_move(i, ai_move);
                val=ai_tiger_minimax(depth+1, alpha, beta);

                if (val < beta){
                    beta = val;
                }
                reverse_ai_goat_move(i, ai_move);

                if (alpha >= beta){
                    return beta;
                }

            break;

            case  GOAT_PLACE:
                ai_goat_place(  i , ai_move );

                val = ai_tiger_minimax(depth+1, alpha, beta);

                if (val < beta){
                    beta = val;
                }

                reverse_ai_goat_place(i, ai_move);
                if (alpha >= beta){
                    return beta;
                }

            break;

        }

    }

    if (ai_turn=="TIGER")
        return alpha;

    else return beta;

}








