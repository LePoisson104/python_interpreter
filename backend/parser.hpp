#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include "lexer.hpp"

class Parser
{
public:
    explicit Parser(const Token &tokens);
    std::vector<Token> produceAST();

private:
    Token at();
    Token eat();
    Token expect();

    bool notEOF();

    std::vector<Token> tokens;
};

#endif