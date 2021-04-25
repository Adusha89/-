#include "stdint.h"
#include "header.hpp"
#include <iostream>

size_t FIELD_WIDTH;
void Get_Field (GameField* p)
{
    std::cout << "Input Field Width\n";
    std::cin >> FIELD_WIDTH;
    *p = new CellState[FIELD_WIDTH*FIELD_WIDTH];
}


bool is_valid_pos(size_t row, size_t col) { //Проверка координат
    return row < FIELD_WIDTH && col < FIELD_WIDTH;
}

CellState get_cell(GameField const& field, size_t row, size_t col)//Получение значения клетки
{
    if(is_valid_pos(row, col)){
        return field[col * FIELD_WIDTH + row];
    }
    return CellState::Empty;
}

bool set_cell(GameField& field, size_t row, size_t col, CellState state) { //Установка клетки
    if(is_valid_pos(row, col) && get_cell(field, row, col) == CellState::Empty) {
        field[col * FIELD_WIDTH + row] = state;
        return true;
    }
    return false;
}

bool is_draw(GameField const& field) { //Проверка на ничью
    for(size_t i=0; i < FIELD_WIDTH * FIELD_WIDTH; i++)
    {
        if(field[i] == CellState::Empty) {
            return false;
        }
    }
    return true;
}

CellState is_line_full(GameField const& field, //Проверка строк
    size_t start_x, size_t start_y, 
    short dx, short dy) {
        size_t x = start_x, y = start_y;
        CellState first_cell = get_cell(field, x, y);
        if (first_cell == CellState::Empty) {
            return CellState::Empty;
        }
        while (is_valid_pos(x + dx, y + dy)) {
            x += dx;
            y += dy;
            if (get_cell(field, x, y) != first_cell) {
                return CellState::Empty;
            }
        }
        return first_cell;

}

TurnOutCome check_turn_outcome(GameField const& field) { //Результат хода
    #define CHECK_LINE(start_x, start_y, dx, dy)                                                    \
        if (CellState res = is_line_full(field, start_x, start_y, dx, dy); res != CellState::Empty) \
        {                                                                                           \
           return res == CellState::X ? TurnOutCome::X_WON : TurnOutCome::O_WON;                    \
        }

        for(size_t i=0; i < FIELD_WIDTH; i++) {
            CHECK_LINE(0, i, 1, 0);
            CHECK_LINE(i, 0, 0, 1);
        }
        
        CHECK_LINE(0, 0, 1, 1);
        CHECK_LINE(2, 0, -1, 1);

    #undef CHECK_LINE

        if(is_draw(field)) {
            return TurnOutCome::DRAW;
        }

        return TurnOutCome::CONTINUE;

}

CellState sign_to_cell(PlayerSign sign) {
    return sign == PlayerSign::X ? CellState::X : CellState::O;
}

PlayerSign next_player(PlayerSign current) { // Смена игрока
    return current == PlayerSign::X ? PlayerSign::O : PlayerSign::X;
}