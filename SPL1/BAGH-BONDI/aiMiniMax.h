
#ifndef ai_minimax_h
#define ai_minimax_h

#include"aiMode.h"
#include"globalVariable.h"

bool ai_tiger_win();
int trapped_tigers();

bool ai_goat_win();
bool ai_goat_win();

int ghost_goats();

int possible_captures();

int ai_goat_position_evaluate();
int ai_tiger_position_evaluate();

int  ai_tiger_move_type( int row, int col, int counter, struct Move ai_move[21] );
int ai_goat_move_type(int row, int col, int counter, struct Move ai_move[21]);
int generate_move_type ( int counter, struct Move ai_move[21] );

void ai_goat_move(  int counter, struct Move ai_move[21]);
void reverse_ai_goat_move(  int counter, struct Move ai_move[21] );
void ai_goat_place(  int counter, struct Move ai_move[21] );
void reverse_ai_goat_place( int counter, struct Move ai_move[21]);

void ai_tiger_move(  int counter, struct Move ai_move[21]);
void reverse_ai_tiger_move( int counter, struct Move ai_move[21]);
void ai_tigers_kill_move( int counter, struct Move ai_move[21]);
void reverse_ai_tigers_kill_move(  int counter, struct Move ai_move[21] );

int ai_goat_minimax(int depth, int alpha, int beta);
int ai_tiger_minimax(int depth, int alpha, int beta);

void board2_TO_ai_board();


#endif

