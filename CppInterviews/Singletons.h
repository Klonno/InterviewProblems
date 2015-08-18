#pragma once
#include <atomic>
#include <mutex>

//
// pointer initialized at run-time. Needs to be thread safe.
// 
class RunTimeInitSingleton
{
private:
    static std::atomic<RunTimeInitSingleton*> m_pClass;
    static std::mutex m_m;

    RunTimeInitSingleton();
    ~RunTimeInitSingleton();

public:
    static RunTimeInitSingleton* GetPointer(void);

};


//
// Static pointer initialized at program start.
// Statics are initialized before the program starts (i.e. before main is entered).
// Good = is thread safe. 
// Bad = Pointer may never be used!
//
class StaticInitializationSingleton
{
private:
    static StaticInitializationSingleton* m_pClass; 

    StaticInitializationSingleton();
    ~StaticInitializationSingleton();

public:
    static StaticInitializationSingleton* GetPointer(void);

};

