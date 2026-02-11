#include "lexer.hpp"

void Lexer::lineIncrementor()
{
    lineNumber++;
}

bool Lexer::isAlpha(char src)
{
    return (char)toupper(src) != (char)tolower(src);
}

std::vector<Token> Lexer::tokenize(const std::string &src)
{
}
