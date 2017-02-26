#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"
/*implement hash function */
unsigned int bkdr_hash(char* key)
{
    char* str = key;
    unsigned int seed=31;
    unsigned int hash=0;
    while(*str!='\0') {
        hash=hash * seed +(*str++);
    }
    hash%=PRIME_NUMBER;
    return hash;
}


entry *findName(char lastName[], entry **d)
{
    unsigned int index;
    index=bkdr_hash(lastName);
    entry *pHead;
    pHead=d[index];
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }

    return NULL;
}

entry *append(char lastName[], entry **d)
{
    /*get lastName hash number and set index*/
    unsigned int index;
    index=bkdr_hash(lastName);
    /* allocate memory for the new entry and put lastName */
    entry *e;
    e=malloc(sizeof(entry));
    strcpy(e->lastName,lastName);
    /*cut the link-list and add e into*/
    e->pNext=d[index]->pNext;
    d[index]->pNext=e;


    return NULL;
}
void freeList(entry *head)
{
    entry *curr;
    while(head != NULL) {
        curr=head;
        head=head->pNext;
        free(curr);
    }
}

