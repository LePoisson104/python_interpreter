#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "backend/lexer.hpp"

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

// g++ main.cpp -o main && ./main test.py (to run the program)
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
        std::cout << t.value << '\n';
    }

    return 0;
}
