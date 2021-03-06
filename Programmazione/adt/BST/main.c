/* Realizzare un ADT per un Binary Search Tree
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "bst.h"
#define SIZE 10 // numbers of node

int main(){

    treeInit();

    int i;
    srand(time(NULL));
    for(i=0;i<SIZE;i++)
        treeAdd(rand()%100); // random key for node


    /*treeVisit(0); // visit inOrder
    treeVisit(1); // visit preOrder
    treeVisit(2); // visit postOrder

    treePrint(); // print tree

    printf("\nMIN::%d\n\n",treeMin()); // search for min

    treeDeleteMin(); // delete min
    treePrint();     // and print again tree
    */
    treePrint();

    /* RICERCA NODO
    Item key;
    printf("\n[?] Inserisci la key da cercare::");
    scanf("%d",&key);
    printf("%d\n",treeSearch(key));
    */


    Item a,b;
    printf("Inserisci i due nodi di cui calcolare la distanza::");
    scanf("%d %d",&a,&b);
    printf("Distanza::%d\n",treeDistance(a,b));

    /*  ELIMINAZIONE NODO
    Item key;
    printf("\n[?] Inserisci la key da eliminare::");
    scanf("%d",&key);
    treeDelete(key);
    treePrint();
    */

    return 0;
}
