#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

enum class TokenType
{
    // Single-character tokens;
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    MINUS,
    PLUS,
    // One or two character tokens;
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    // Literals
    IDENTIFIER,
    STRING,
    NUMBER,
    // Keywords
    AND,
    ELSE,
    FALSE,
    FOR,
    IF,
    OR,
    PRINT,
    RETURN,
    TRUE,
    WHILE,
    // EOF
    ENDFILE
};

struct Token
{
    TokenType type;
    std::string value;
};

class Lexer
{
private:
    std::vector<Token> Tokens;
    int position;
    bool isAlpha(char src);
    bool isInt(char src);
    bool isSkippable(char src);
    void advance();
    std::vector<Token> tokenize(const std::string &src);
};

#endif