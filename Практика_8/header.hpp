#pragma once
#include "stdint.h"
#include <cstddef>
extern size_t FIELD_WIDTH;
//Ширина поля

struct Pos {
    size_t x, y;
};
enum class CellState { //Состояние клетки
    Empty, X, O
};

enum class PlayerSign { //Игрок
    X, O
};

enum class TurnOutCome { //Результат Хода
    CONTINUE,
    DRAW,
    X_WON,
    O_WON
};



using GameField = CellState*;

//Прототипы Logic

void Get_Field (GameField*);
bool is_valid_pos(size_t , size_t ); //Проверка координат
CellState get_cell(GameField const& , size_t , size_t);//Получение значения клетки
bool set_cell(GameField& , size_t , size_t , CellState ); //Установка клетки
bool is_draw(GameField const& ); //Проверка на ничью
CellState is_line_full(GameField const& , size_t , size_t , short , short ); //Проверка строк
TurnOutCome check_turn_outcome(GameField const& ); //Результат хода
CellState sign_to_cell(PlayerSign, bool );
PlayerSign next_player(PlayerSign ); // Смена игрока

//Прототипы IO
void print_greeting(void);
Pos query_player_move(GameField const& ); //Запрос хода
void print_cell(CellState ); // Печать ячейки
void print_field(GameField const& ); // Отрисовка поля
void print_game_outcome(TurnOutCome ); // Результат игры
PlayerSign get_current_player(bool&);

//Прототипы AI
size_t get_empty_cells(size_t* , GameField const& );
Pos get_random_empty_cell(GameField const& );
Pos make_predictive_move(GameField const&);
Pos query_ai_move(GameField const&);




