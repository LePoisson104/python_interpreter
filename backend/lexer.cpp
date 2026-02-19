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

bool Lexer::match(char expected)
{
    advance();
    if (!isAtEnd() && currentChar() == expected)
    {
        advance();
        return true;
    }

    return false;
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

Token Lexer::createString()
{
    std::string strVal;
    advance();
    while (currentChar() != '"')
    {
        strVal += currentChar();
        advance();
    }
    return {TokenType::STRING, strVal};
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
                tokens.push_back(match('=') ? Token{TokenType::EQUAL_EQUAL, "=="} : Token{TokenType::EQUAL, "="});
                break;
            case '!':
                tokens.push_back(match('=') ? Token{TokenType::NOT_EQUAL, "=="} : Token{TokenType::ERROR, "Unexpected token !"});
                break;
            case '<':
                tokens.push_back(match('=') ? Token{TokenType::LESS_EQUAL, "<="} : Token{TokenType::ERROR, "<"});
                break;
            case '>':
                tokens.push_back(match('=') ? Token{TokenType::GREATER_EQUAL, ">="} : Token{TokenType::ERROR, ">"});
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
            case '"':
                tokens.push_back(createString());
                break;
            }
        }
        advance();
    }
    return tokens;
}
