#include "stdafx.h"
#include "NewClass.h"

#if FALSE
CNewClass::CNewClass()
{
}
#endif
CNewClass::CNewClass(int foo) : m_foo(0)
{

}


CNewClass::~CNewClass()
{
}

//
// Overload multiplication operator
//
int CNewClass::operator*(CNewClass& newClass)
{
    return this->m_foo * newClass.m_foo;
}


//
// Overload equality operator
//
bool CNewClass::operator==(CNewClass& newClass)
{
    bool isEqual;

    (this->m_foo == newClass.m_foo) ? isEqual = true : isEqual = false;

    return isEqual;
}


const char* CNewClass::ReturnConstString()
{
    return "Foo";
}

void CNewClass::CannotAlterMember() const
{
    // error C3490: 'm_foo' cannot be modified because it is being accessed through a const object	c:\users\scott\documents\visual studio 2013\projects\cppinterviews\cppinterviews\newclass.cpp	26	1	CppInterviews
    // m_foo = 5;
}

void CNewClass::CannotAlterParameter(int const x, const int y)
{
    // error C3892 : 'x' : you cannot assign to a variable that is const	c : \users\scott\documents\visual studio 2013\projects\cppinterviews\cppinterviews\newclass.cpp	32	1	CppInterviews
    // x = 10;

    // error C3892: 'y' : you cannot assign to a variable that is const	c:\users\scott\documents\visual studio 2013\projects\cppinterviews\cppinterviews\newclass.cpp	35	1	CppInterviews
    // y = 15;
}

int& CNewClass::ReferenceMethod(int& x)
{
    int y = 5;
    int& ry = y;
    x = 1;

    return ry;
}