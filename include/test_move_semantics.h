#pragma once
// https://ru.stackoverflow.com/questions/490753/%D0%9A%D0%BE%D0%BD%D1%81%D1%82%D1%80%D1%83%D0%BA%D1%82%D0%BE%D1%80-%D0%BF%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D1%89%D0%B5%D0%BD%D0%B8%D1%8F

#include <vector>
#include <string>

class TestClass 
{
public:
    TestClass() = default;

    TestClass(const std::string& buff)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, buff.c_str(), buffSize);
    }

    ~TestClass() { destroy(); }

    TestClass(const TestClass& other)
        : pBuff(nullptr)
        , buffSize(other.buffSize)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
    }

    TestClass& operator=(const TestClass& other)
    {
        destroy();
        buffSize = other.buffSize;
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
        return *this;
    }

    TestClass(TestClass&& tmp)
        : pBuff(tmp.pBuff)
        , buffSize(tmp.buffSize)
    {
        tmp.pBuff = nullptr;
    }

    TestClass& operator=(TestClass&& tmp)
    {
        destroy();
        buffSize = tmp.buffSize;
        pBuff = tmp.pBuff;
        tmp.pBuff = nullptr;
        return *this;
    }

    static TestClass factory(const std::string & buff)
    {
      TestClass retBuff(buff);
      return retBuff;
    }

private:
    void destroy()
    {
        if (pBuff)
            delete[] pBuff;
    }

    char *pBuff = nullptr;
    size_t buffSize = 0;
};