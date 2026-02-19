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
    MULTIPLY,
    DIVIDE,
    // One or two character tokens;
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    NOT,
    NOT_EQUAL,
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
    // Erro token
    ERROR,
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
public:
    explicit Lexer(const std::string &src);
    std::vector<Token> tokenize();

private:
    bool isAlpha(char c);
    bool isInt(char c);
    bool isAtEnd() const;
    bool match(char expected);
    std::string createIdentifier();
    std::string createNumber();
    Token createString();
    char currentChar();
    void advance();

    std::string src;
    int position;
};

#endif