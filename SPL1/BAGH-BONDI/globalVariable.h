
#ifndef globalVariable_h
#include"twoPlayerMode.h"


//TWO PLAYER VARIABLES
extern struct cordin scope_track[8], g_scope_track[8], kill_scope_track[8], goat_track[8], tig_track, goat_ind, board[30][30];

extern char board2[50][50];
extern int  move_count, total_move, s_track ,tiger_suc_input, goat_suc_input ;  //move_count for count a tiger's move
extern int total_goat, goat_win_flag, tiger_win_flag , killed_goat;
extern int mode_start, back_menu_flag , ai_goat_mode, ai_tiger_mode ;



//AI VARIABLES EXTERN
extern int g1,g2,g3,g4,t1,t2,t3,t4;  //Temporary_variable_to_take_input
extern char ai_board[50][50];
extern int g_count;       //GOAT NUMBER IS UPTO 20
extern int ai_killed_goat;
extern int move_from[2],move_to[2] , tiger_kill_move_flag;
extern int highest_search_depth;
extern string ai_turn;



#define globalVariable_h
#endif // globalVariable_h


