#include <iostream>
#include "lexer.hpp"
#include <vector>

Lexer::Lexer(const std::string &src) : src(src), position(0) {}

bool Lexer::isAlpha(char src)
{
    return (char)toupper(src) != (char)tolower(src);
}

bool Lexer::isInt(char src) {}

bool Lexer::isAtEnd() const
{
    return position >= src.length();
}

char Lexer::advance()
{
    return src[position++];
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while (!isAtEnd())
    {
        char c = advance();

        switch (c)
        {
        case '(':
            tokens.push_back({TokenType::LEFT_PAREN, "("});
            break;
        case ')':
            tokens.push_back({TokenType::RIGHT_PAREN, ")"});
            break;
        case '=':
            tokens.push_back({TokenType::EQUAL, "="});
            break;
        }
    }

    return tokens;
}
