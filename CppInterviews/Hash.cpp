#include "stdafx.h"
#include "Hash.h"
#include <iostream>

Hash::Hash(int tableSize) : m_table(new tableEntry*[tableSize]),
m_size(tableSize)
{
    for (int i = 0; i < tableSize; ++i)
    {
        m_table[i] = NULL;
    }
}


void Hash::DeleteChain(tableEntry* pEntry)
{
    if (NULL == pEntry->next)
    {
        delete pEntry;
    }
    else
    {
        DeleteChain(pEntry->next);
    }
}

Hash::~Hash()
{
    for (int i = 0; i < m_size; ++i)
    {
        if (m_table[i] != NULL)
        {
            DeleteChain(m_table[i]);
        }
    }
    if (m_table != NULL)
    {
        delete m_table;
    }
}

unsigned int Hash::ComputeHashIndex(char *str)
{

    unsigned int hashval;

    /* we start our hash out at 0 */
    hashval = 0;

    /* for each character, we multiply the old hash by 31 and add the current
    * character.  Remember that shifting a number left is equivalent to
    * multiplying it by 2 raised to the number of places shifted.  So we
    * are in effect multiplying hashval by 32 and then subtracting hashval.
    * Why do we do this?  Because shifting and subtraction are much more
    * efficient operations than multiplication.
    */
    for (; *str != '\0'; str++) hashval = *str + (hashval << 7) - hashval;

    /* we then return the hash value mod the hashtable size so that it will
    * fit into the necessary range
    */
    return hashval % m_size;
}

void Hash::Add(char* str)
{
    unsigned int hash = this->ComputeHashIndex(str);
    std::cout << "Hash index of " << str << " is " << hash << std::endl;

    tableEntry* newEntry = new tableEntry();

    newEntry->string = str;
    newEntry->next = NULL;

    if (m_table[hash] == NULL)
    {
        m_table[hash] = newEntry;
    }
    else
    {
        // go to the end of the chain in the entry array index @ hash
        tableEntry* chain = m_table[hash];
        while (chain->next != NULL)
            chain = chain->next;
        chain->next = newEntry;
    }
}

const char* Hash::Find(char* str)
{
    char* found = NULL;

    unsigned int hash = this->ComputeHashIndex(str);

    if (m_table[hash]->next == NULL)
        found = m_table[hash]->string;
    else
    {
        tableEntry* chain = m_table[hash];
        while (chain != NULL)
        {
            if (0 == strcmp(chain->string, str))
            {
                found = chain->string;
                break;
            }
            else
            {
                chain = chain->next;
            }
        }
    }
    return found;
}
