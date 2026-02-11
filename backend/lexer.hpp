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
    std::string lexeme;
    int line;
};

class Lexer
{
private:
    std::vector<std::string, std::string> Tokens;
    int lineNumber;
    bool isAlpha();
    bool isInt();
    bool isSkippable();
    void lineIncrementor();
    std::vector<Token> tokenize(const std::string &source);
};

#endif