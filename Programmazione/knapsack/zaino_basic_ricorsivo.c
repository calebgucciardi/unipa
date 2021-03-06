/* Risolvere il problema delle zaino
 * utilizzando una funzione ricorsiva
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OBJ 12
#define MAX_WEIGHT 25
#define max(a,b) ((a)>(b) ? (a) : (b) )



// S T R U C T
struct obj{
    int value;
    int weight;
};

typedef struct obj Obj;

// P R O T O T I P I
int bestChoice(Obj *shop, int dim,int weight);

// M A I N
void main(){

    // V A R
    Obj shop[NUM_OBJ];
    int i;
    
    // I N I T - S H O P
    srand(time(NULL));
    for(i=0;i<NUM_OBJ;i++){
        shop[i].value = (rand() % 100)+1;
        shop[i].weight = (rand() % 15)+1;
    }

    // P R I N T - S H O P
    for(i=0;i<NUM_OBJ;i++){
        printf("[ %d$ %dKg ] ",shop[i].value, shop[i].weight);
        (i+1)%4 ? 0:printf("\n");
    }
    printf("\n"); 

    printf("Peso Massimo::%d\n",MAX_WEIGHT);
    printf("Valore raggiugnto::%d\n",bestChoice(shop,NUM_OBJ,MAX_WEIGHT));

}

/* * * * bestChoice() * * * *
 * Trova il miglior compromesso tra valore-peso
 * */
int bestChoice(Obj *shop, int dim,int weight){
    static int dp[NUM_OBJ][MAX_WEIGHT+1];

    if((weight==0)||(dim==0))
        return 0;
    if(shop[dim-1].weight>weight){
        if(dp[dim-1][weight]==0)
            dp[dim-1][weight] = bestChoice(shop,dim-1,weight);
        return dp[dim-1][weight];
    }

    if(dp[dim-1][weight-shop[dim-1].weight]==0)
        dp[dim-1][weight-shop[dim-1].weight] = bestChoice(shop,dim-1,weight-shop[dim-1].weight)+shop[dim-1].value;
    if(dp[dim-1][weight]==0)
        dp[dim-1][weight] = bestChoice(shop,dim-1,weight);

    return max(dp[dim-1][weight-shop[dim-1].weight],dp[dim-1][weight]);

}
