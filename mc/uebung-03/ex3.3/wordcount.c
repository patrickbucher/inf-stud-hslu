/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100

typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} tnode;

int getch();
void ungetch(int);
int getword(char *, int);

tnode *addtree(tnode *, char *);
void treeprint(tnode *);
tnode *newnode(char *);
tnode *findnode(tnode *, char *);
tnode *findnotfull(tnode *);
void cleanup(tnode *);

char buf[BUFSIZE];
int bufp = 0;

int main()
{
    tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    cleanup(root);

    return 0;
}

void treeprint(tnode *node) {
    if (node != NULL) {
        treeprint(node->left);
        treeprint(node->right);
        printf("%4d\t%s\n", node->count, node->word);
    }
}

void cleanup(tnode *node) {
    if (node != NULL) {
        free(node->word);
        cleanup(node->left);
        cleanup(node->right);
        free(node);
    }
}

tnode *addtree(tnode *root, char *word)
{
    tnode *node;
    
    if (root == NULL) {
        return newnode(word);
    }

    node = findnode(root, word);
    if (node != NULL) {
        node->count++;
    } else {
        node = findnotfull(root);
        if (node->left == NULL) {
            node->left = newnode(word);
        } else {
            node->right = newnode(word);
        }
    }

    return root;
}

tnode *findnode(tnode *node, char *word)
{
    tnode *tmp;

    if (node == NULL || node->word == NULL) {
        return NULL;
    }
    if (strcmp(node->word, word) == 0) {
        return node;
    }
    tmp = findnode(node->left, word);
    if (tmp != NULL) {
        return tmp;
    }
    return findnode(node->right, word);
}

tnode *findnotfull(tnode *node)
{
    tnode *tmp;

    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL || node->right == NULL) {
        return node;
    }
    tmp = findnotfull(node->left);
    if (tmp != NULL) {
        return tmp;
    }
    return findnotfull(node->right);
}

tnode *newnode(char *word)
{
    tnode *node;
    
    node = (tnode *)malloc(sizeof(tnode));
    node->word = malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(node->word, word);
    node->count = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int getch()
{
    return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
    if (bufp > BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getword(char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()));
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
