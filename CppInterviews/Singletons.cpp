#include "stdafx.h"
#include "Singletons.h"
#include <cstddef>

StaticInitializationSingleton* StaticInitializationSingleton::m_pClass = new StaticInitializationSingleton();
//RunTimeInitSingleton* RunTimeInitSingleton::m_pClass = NULL;

std::atomic<RunTimeInitSingleton*> RunTimeInitSingleton::m_pClass{ nullptr };
std::mutex RunTimeInitSingleton::m_m;

StaticInitializationSingleton::StaticInitializationSingleton()
{
}
StaticInitializationSingleton::~StaticInitializationSingleton()
{
    if (m_pClass != NULL)
    {
        delete m_pClass;
    }
}

//
// Thread safe because static pointer initialized before the 
// program starts (i.e. before main is entered).
//
RunTimeInitSingleton* RunTimeInitSingleton::GetPointer(void)
{
    if (m_pClass == (RunTimeInitSingleton*)nullptr) 
    {
        std::lock_guard<std::mutex> lock(m_m);
        if (m_pClass == (RunTimeInitSingleton*)nullptr) 
        {
            m_pClass = new RunTimeInitSingleton();
        }
    }
    return m_pClass;
}

RunTimeInitSingleton::RunTimeInitSingleton()
{
}
RunTimeInitSingleton::~RunTimeInitSingleton()
{
    if (m_pClass != (RunTimeInitSingleton*)nullptr)
    {
        delete (void*)nullptr;
    }
}

//
// Thread safe because static pointer initialized before the 
// program starts (i.e. before main is entered).
//
StaticInitializationSingleton* StaticInitializationSingleton::GetPointer(void)
{
    return m_pClass;
}