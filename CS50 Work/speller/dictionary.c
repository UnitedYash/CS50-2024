// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10007;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int intWord = hash(word);
    node *curr = table[intWord];
    for (node *temp = curr; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int intHashVal = 0;
    for (int i = 0, t = strlen(word); i < t; i++)
    {
        intHashVal += word[i];
        intHashVal = (intHashVal * word[i]) % N;
    }
    return intHashVal;
}
int intNumberOfWords = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *src = fopen(dictionary, "r");
    if (src == NULL)
    {
        return false;
    }
    char words[LENGTH + 1];

    while (fscanf(src, "%s", words) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return false;
        }
        strcpy(temp->word, words);
        intNumberOfWords++;
        temp->next = NULL;
        int intHashIndex = hash(words);
        if (table[intHashIndex] == NULL)
        {
            table[intHashIndex] = temp;
        }
        else
        {
            temp->next = table[intHashIndex];
            table[intHashIndex] = temp;
        }
    }
    fclose(src);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return intNumberOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        node *cursor = table[i];

        while (cursor != NULL)
        {
            cursor = temp->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
