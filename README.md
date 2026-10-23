# C++ Py++ Interpreter

A simple Python-like interpreter written in **C++** but with better visibility.  
This project parses and executes a small subset of Py++ syntax to demonstrate how interpreters work under the hood.

## Features

- Written entirely in **C++**
- Supports basic Python-style syntax
- Tokenization (lexing)
- Parsing into an abstract syntax tree (AST)
- Expression evaluation
- Variable assignment
- Simple error handling

> This project is for learning purposes and is **not** a full Python implementation.

## Example

```python
x = 5
y = x + 3
print(y)

if x < y {
    print("bigger")
}

for i in range x {
    print(i)
}

