#include <iostream>

// g++ main.cpp -o main && ./main test.py (to run the program)
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << "filename" << std::endl;
        return 1;
    }

    std::cout << "hello world" << std::endl;

    return 0;
}