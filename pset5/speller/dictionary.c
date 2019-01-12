// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 

#include "dictionary.h"

#define ALPHABET_LENGTH 27

typedef struct node
{
    bool is_word;
    struct node* children[ALPHABET_LENGTH];
}
node;

node *root = NULL;

int numberOfWords = 0;

void freenode(node* firstnode)
{
    for(int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if (firstnode -> children[i] != NULL)
        {
            freenode(firstnode -> children[i]);
        }
    }
    free(firstnode);
    return;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node* crawl = NULL;
    crawl=root;

    // traverse trie per char

    for (int x = 0; x < strlen(word); x++)
    {
        int index = 0;
        
        if (isalpha(word[x]))
        {
            index = tolower(word[x]) - 'a';
        }
        else if (word[x] == '\'')
        {
            index = ALPHABET_LENGTH - 1;
        }
        else
        {
            printf("ERROR: Could not parse word\n");
            return false;
        }

        if (crawl->children[index] == NULL)
        {
            //not a word - false
            return false;
        }

        crawl = crawl->children[index];
    }

    return crawl -> is_word;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    root = (struct node *)malloc(sizeof(struct node));

    root->is_word = false;

    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }

    node* trav = NULL;

    int character = 0;

    // for every dictionary word, iterate through the trie
    while (EOF != (character = fgetc(dict)))
    {
        trav = root;

        // for each character in word
        for(; isalpha(character) || character == '\'' ; character = fgetc(dict))
        {
            int index = 0;

            if (isalpha(character))
            {
               index = tolower(character) - 'a';
            }
            else if (character == '\'')
            {
                index = ALPHABET_LENGTH - 1;
            }
            else
            {
                printf("ERROR: Could not parse dictionary word\n");
                fclose(dict);
                return false;
            }

            if (trav->children[index] == NULL)
            {
             //   trav->children[index] = (struct node *)malloc(sizeof(struct node));
                node *pNode = (node *)malloc(sizeof(node));

                if (pNode)
                {
                    pNode->is_word = false;
                    // init node
                    for (int i = 0; i < ALPHABET_LENGTH; i++)
                    {
                        pNode->children[i] = NULL;
                    }
                    trav->children[index] = pNode;
                }
                else
                {
                    printf("ERROR: Could not allocate space for node, memory issue.");
                    fclose(dict);
                    return false;
                }
            }
            trav = trav->children[index];
        }
        // reached end of word, set end of word to true for current pointer.
        trav->is_word = true;
        numberOfWords++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node* firstnode = root;
    freenode(firstnode);
    return true;
}
