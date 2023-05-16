#include <stdio.h>
#include "string.h"
#include "Tree.h"
#include "stdlib.h"
#include "locale.h"
#include "Game.h"
int main() {
    FILE* logger = copyFile();
    FILE* file = fopen("C:\\Users\\botme\\AkinatorC\\save.txt", "r");
    if (file == NULL) return -1;
    struct Node* root = readTreeFromFile(file);
    fclose(file);
    printf("1 - yes, 0 - no\n");
    int done = 0;
    while (!done) {
        struct Node* temp = root;
        do {
            temp = game(temp, logger);
        } while (temp != NULL);
        printf("Set 0 to continue, set 1 to exit and save, set 2 to exit\n");
        int i = -1;
        i = setArraySize(i, 3);
        log(file, NULL, &i);
        if (i == 1) {
            file = fopen("C:\\Users\\botme\\AkinatorC\\save.txt", "w");
            if (file == NULL) return -1;
            writeTreeToFile(file, root);
            fclose(file);
            done = 1;
        }
        else if (i == 2) {
            fclose(file);
            done = 1;
        }
    }

    freeTree(root);
    fclose(logger);
    return 0;
}
