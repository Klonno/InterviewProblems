#pragma once

typedef struct tableEntry {
    char *string;
    struct tableEntry *next;
} tableEntry;

//
// Chained Hash Table
// If a word is duplicated follow the chain of tableEntry * (linear search) to find the word.
//
class Hash
{
private:
    tableEntry** m_table;
    int m_size;
    void DeleteChain(tableEntry* pEntry);

public:
    Hash(int tableSize);
    virtual ~Hash();
    unsigned int ComputeHashIndex(char *str);

    void Add(char* str);

    const char* Find(char* str);
};

