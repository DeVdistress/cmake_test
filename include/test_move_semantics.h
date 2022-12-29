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
        std::cout << "( Default constructors ) was executed" << std::endl;
    }

    TestMoveSemantic(const std::string& buff)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, buff.c_str(), buffSize);
        std::cout << "( Constructors ) was executed" << std::endl;
    }

    ~TestMoveSemantic() { destroy(); }

    TestMoveSemantic(const TestMoveSemantic& other)
        : pBuff(nullptr)
        , buffSize(other.buffSize)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
        std::cout << "( Copy constructors ) was executed" << std::endl;
    }

    TestMoveSemantic& operator=(const TestMoveSemantic& other)
    {
        destroy();
        buffSize = other.buffSize;
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
        std::cout << "( Copy assignment operator ) was executed" << std::endl;
        return *this;
    }

    TestMoveSemantic(TestMoveSemantic&& tmp)
        : pBuff(tmp.pBuff)
        , buffSize(tmp.buffSize)
    {
        tmp.pBuff = nullptr;
        std::cout << "( Move constructors ) was executed" << std::endl;
    }

    TestMoveSemantic& operator=(TestMoveSemantic&& tmp)
    {
        destroy();
        buffSize = tmp.buffSize;
        pBuff = tmp.pBuff;
        tmp.pBuff = nullptr;
        std::cout << "( Move assignment operator ) was executed" << std::endl;
        return *this;
    }

    static TestMoveSemantic factory(const std::string& buff)
    {
        TestMoveSemantic retBuff(buff);
        std::cout << "( TestMoveSemantic's Factory ) was executed" << std::endl;
        return retBuff;
    }

private:
    void destroy()
    {
        if (pBuff)
            delete[] pBuff;
        std::cout << "( Destructor ) was executed" << std::endl;
    }

    char *pBuff = nullptr;
    size_t buffSize = 0;
};