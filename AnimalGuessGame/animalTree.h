/*animal.h file*/

#ifndef ANIMALTREE_H
#define ANIMALTREE_H

struct aTree;
struct aTree* iniTree();
void resetTree(struct aTree* tree);
void addNewAnimal(struct aTree* tree, char str[], char str1[], char str2[]);
void displayData(struct aTree* tree, char str[]);
int hasNext(struct aTree* tree);
void copyTree(struct aTree* tree);
void deleteTree(struct aTree *tree);

#endif
