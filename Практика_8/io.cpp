
#include <iostream>
#include <iomanip>
#include "header.hpp"


void print_greeting() {
    std::cout << "Welcome to the game\n";
}

size_t FIELD_WIDTH;
void Get_Field (GameField* p)
{
    bool flag = false;
    std::cout << "Input Field Width\n";
    while(!flag) {
        std::cin >> FIELD_WIDTH;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Error: please input numbers!\nTry yet<";
        }
        else flag = true;
    }
    
    *p = new CellState[FIELD_WIDTH*FIELD_WIDTH]{};
    
}


Pos query_player_move(GameField const& field) { //Запрос хода
    Pos pos;
    std::cout << "Input Two number in range [1-" << FIELD_WIDTH << "]\n >";
    bool ok = false;
    while(!ok) {
        std::cin >> pos.x >> pos.y;
        pos.x--;
        pos.y--;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Error: please input numbers!\nTry yet<";
        }

        else if (!is_valid_pos(pos.x, pos.y)) {
            std::cout << "Eror: position is out of field\nTry yet<";
        }

        else if(get_cell(field, pos.x, pos.y) != CellState::Empty) {
            std::cout << "Eror: Cell is not empty\nTry yet<";
        }
        else {
            ok = true;
        }
    }
    return pos;
}

void print_cell(CellState cell) { // Печать ячейки
    switch (cell)
    {
        case CellState::Empty:
            std::cout << ".";
            break;

        case CellState::X:
            std::cout << "X";
            break;

        case CellState::O:
            std::cout << "O";
            break;
    }

}
void print_field(GameField const& field) { // Отрисовка поля
    std::cout.fill('=');
    std::cout << std::setw(FIELD_WIDTH + 5) << "\n";
    for(size_t col = 0; col < FIELD_WIDTH; col++)
    {
        std::cout << "||";
        for(size_t row = 0; row < FIELD_WIDTH; row++)
        {
            print_cell(get_cell(field, row, col));
        }
        std::cout << "||\n";
    }
    std::cout.fill('=');
    std::cout << std::setw(FIELD_WIDTH + 5) << "\n";
}

void print_game_outcome(TurnOutCome outcome) { // Результат игры
    switch (outcome)
    {
        case TurnOutCome::DRAW:
            std::cout << "It's a draw\n";
            break;

        case TurnOutCome::X_WON:
            std::cout << "X win!\n";
            break;

        case TurnOutCome::O_WON:
            std::cout << "O win!\n";
            break;

        default:
            break;
    }

}

PlayerSign get_current_player(bool& flag) {//За кого играем
    char CP;
    std::cout << "Input Sign player (X or O)\n< ";
    std::cin >> CP;
    switch (CP)
    {
    case 'X':
        return PlayerSign::X;
    
    default:
        flag = false;
        return PlayerSign::O;
    }
}