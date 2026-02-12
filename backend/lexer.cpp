#include "lexer.hpp"

bool Lexer::isAlpha(char src)
{
    return (char)toupper(src) != (char)tolower(src);
}

bool Lexer::isInt(char src) {}

bool Lexer::isSkippable(char src) {}

void Lexer::advance()
{
    position++;
}

std::vector<Token> Lexer::tokenize(const std::string &src)
{
}
