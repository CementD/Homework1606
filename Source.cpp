#include <iostream>
#include <exception>
using namespace std;

class MathException : public exception {
public:
    const char* what() const override {
        return "Math error occurred!";
    }
};

class DivideByZeroException : public MathException {
public:
    const char* what() const override {
        return "Divide by zero error!";
    }
};

class InvalidArgumentException : public MathException {
public:
    const char* what() const override {
        return "Invalid argument error!";
    }
};

class MemoryException : public exception {
public:
    const char* what() const override {
        return "Memory error occurred!";
    }
};

class OutOfMemoryException : public MemoryException {
public:
    const char* what() const override {
        return "Out of memory error!";
    }
};

class FileException : public exception {
public:
    const char* what() const override {
        return "File error occurred!";
    }
};

class FileOpenException : public FileException {
public:
    const char* what() const override {
        return "File open error!";
    }
};

class FileReadException : public FileException {
public:
    const char* what() const override {
        return "File read error!";
    }
};

class FileWriteException : public FileException {
public:
    const char* what() const override {
        return "File write error!";
    }
};

void demonstrateExceptions() {
    try {
        throw DivideByZeroException();
    }
    catch (const MathException& e) {
        cerr << "MathException caught: " << e.what() << endl;
    }

    try {
        throw InvalidArgumentException();
    }
    catch (const MathException& e) {
        cerr << "MathException caught: " << e.what() << endl;
    }

    try {
        throw OutOfMemoryException();
    }
    catch (const MemoryException& e) {
        cerr << "MemoryException caught: " << e.what() << endl;
    }

    try {
        throw FileOpenException();
    }
    catch (const FileException& e) {
        cerr << "FileException caught: " << e.what() << endl;
    }

    try {
        throw FileReadException();
    }
    catch (const FileException& e) {
        cerr << "FileException caught: " << e.what() << endl;
    }

    try {
        throw FileWriteException();
    }
    catch (const FileException& e) {
        cerr << "FileException caught: " << e.what() << endl;
    }
}

int main() {
    demonstrateExceptions();
    return 0;
}
