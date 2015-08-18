#pragma once
class CNewClass
{
private:
    int m_foo;

public:
   // CNewClass();
    CNewClass(int foo);
    virtual ~CNewClass();

    const void ConstMethod();

    const char* ReturnConstString();
    void CannotAlterMember() const;
    void CannotAlterParameter(const int x, int const y);

    int& ReferenceMethod(int& x);

    bool operator==(CNewClass& newClass);
    int operator*(CNewClass& newClass);
};

