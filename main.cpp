#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "backend/lexer.hpp"

std::string printTokenType(TokenType type)
{
    switch (type)
    {
    case TokenType::LEFT_PAREN:
        return "LEFT_PAREN";
    case TokenType::RIGHT_PAREN:
        return "RIGHT_PAREN";
    case TokenType::EQUAL:
        return "EQUAL";
    case TokenType::EQUAL_EQUAL:
        return "EQUAL_EQUAL";
    case TokenType::NOT_EQUAL:
        return "NOT_EQUAL";
    case TokenType::IDENTIFIER:
        return "IDENTIFIER";
    case TokenType::NUMBER:
        return "NUMBER";
    case TokenType::COMMA:
        return "COMMA";
    case TokenType::PLUS:
        return "PLUS";
    case TokenType::ENDFILE:
        return "EOF";
    case TokenType::ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

std::string read_file(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        throw std::runtime_error("Failed to open file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// g++ main.cpp backend/lexer.cpp -o main && ./main test.py
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << "filename" << std::endl;
        return 1;
    }

    std::string source = read_file(argv[1]);

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.tokenize();

    for (const Token &t : tokens)
    {
        std::cout << printTokenType(t.type) << " : " << '\'' << t.value << '\'' << '\n';
    }

    return 0;
}
