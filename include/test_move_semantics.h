#pragma once
// Please see https://ru.stackoverflow.com/questions/490753

#include <vector>
#include <string>
#include <iostream>

class TestMoveSemantic
{
public:
    TestMoveSemantic()
    {
        std::cout << "( default constructor ) was executed" << std::endl;
    }

    TestMoveSemantic(const std::string& buff)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, buff.c_str(), buffSize);
        std::cout << "( constructor ) was executed" << std::endl;
    }

    ~TestMoveSemantic()
    { 
        destroy();
        std::cout << "( destructor ) was executed" << std::endl;
    }

    TestMoveSemantic(const TestMoveSemantic& other)
        : pBuff(nullptr)
        , buffSize(other.buffSize)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
        std::cout << "( copy constructor ) was executed" << std::endl;
    }

    TestMoveSemantic& operator=(const TestMoveSemantic& other)
    {
        destroy();
        buffSize = other.buffSize;
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
        std::cout << "( copy assignment operator ) was executed" << std::endl;
        return *this;
    }

    TestMoveSemantic(TestMoveSemantic&& tmp)
        : pBuff(tmp.pBuff)
        , buffSize(tmp.buffSize)
    {
        tmp.pBuff = nullptr; 
        std::cout << "( move constructor ) was executed" << std::endl;
    }

    TestMoveSemantic& operator=(TestMoveSemantic&& tmp)
    {
        destroy();
        buffSize = tmp.buffSize;
        pBuff = tmp.pBuff;

        tmp.pBuff = nullptr;
        std::cout << "( move assignment operator ) was executed" << std::endl;
        return *this;
    }

    static TestMoveSemantic factory(const std::string& buff)
    {
        TestMoveSemantic retBuff(buff);
        std::cout << "( factory ) was executed" << std::endl;
        return retBuff;
    }

private:
    void destroy()
    {
        if (pBuff)
            delete[] pBuff, pBuff = nullptr;
        std::cout << "( destroy ) was executed" << std::endl;
    }

    char *pBuff = nullptr;
    size_t buffSize = 0;
};