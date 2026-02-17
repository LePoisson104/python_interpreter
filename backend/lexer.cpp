#include <iostream>
#include "lexer.hpp"
#include <vector>

Lexer::Lexer(const std::string &src) : src(src), position(0) {}

bool Lexer::isAlpha(char c)
{
    return (char)toupper(c) != (char)tolower(c);
}

bool Lexer::isInt(char c)
{
    return c >= '0' && c <= '9';
}

bool Lexer::isAtEnd() const
{
    return position >= src.length();
}

void Lexer::advance()
{
    position++;
}

char Lexer::currentChar()
{
    return src[position];
}

std::string Lexer::createIdentifier()
{
    std::string identifier;

    while (isAlpha(currentChar()))
    {
        identifier += currentChar();
        advance();
    }
    position--; // take one step back because the next char is not part of the identifier which we need for the next token
    return identifier;
}

std::string Lexer::createInteger()
{
    std::string intStr;

    while (isInt(currentChar()))
    {
        intStr += currentChar();
        advance();
    }

    position--;
    return intStr;
}

Token Lexer::createEqualEqual()
{
    advance(); // consume first '='

    if (!isAtEnd() && currentChar() == '=')
    {
        advance(); // consume second '='
        return {TokenType::EQUAL_EQUAL, "=="};
    }

    return {TokenType::EQUAL, "="};
}

Token Lexer::createNotEqual()
{
    advance();

    if (!isAtEnd() && currentChar() == '=')
    {
        advance();
        return {TokenType::NOT_EQUAL, "!="};
    }

    return {TokenType::ERROR, "Unexpected token type !"};
}

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while (!isAtEnd())
    {
        char c = currentChar();

        if (isAlpha(c))
        {
            tokens.push_back({TokenType::IDENTIFIER, createIdentifier()});
        }
        else if (isInt(c))
        {
            tokens.push_back({TokenType::NUMBER, createInteger()});
        }
        else
        {
            switch (c)
            {
            case '(':
                tokens.push_back({TokenType::LEFT_PAREN, "("});
                break;
            case ')':
                tokens.push_back({TokenType::RIGHT_PAREN, ")"});
                break;
            case '=':
                tokens.push_back(createEqualEqual());
                break;
            case '!':
                tokens.push_back(createNotEqual());
                break;
            case '+':
                tokens.push_back({TokenType::PLUS, "+"});
                break;
            case '-':
                tokens.push_back({TokenType::MINUS, "-"});
                break;
            case '*':
                tokens.push_back({TokenType::MULTIPLY, "*"});
                break;
            case '/':
                tokens.push_back({TokenType::DIVIDE, "/"});
                break;
            case ',':
                tokens.push_back({TokenType::COMMA, ","});
                break;
            }
        }
        advance();
    }
    return tokens;
}
