#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return (a<b)? a:b;
}

int min_cost(int **a, int **t, int n){

    int **b = calloc(2, sizeof(int *));
    for (int i = 0; i < 2; i++){
        b[i] = calloc(n, sizeof(int));
    }

    b[0][n-1] = a[0][n-1];
    b[1][n-1] = a[1][n-1];

    if(n > 1){

        for (int x = n-2; x >= 0; x--){
            b[0][x] = a[0][x] + min(b[0][x+1], t[0][x] + b[1][x+1]);
            b[1][x] = a[1][x] + min(b[1][x+1], t[1][x] + b[0][x+1]);
        }
    }

    return min(b[0][0], b[0][0]);
}

int main(void){

    int n;
    printf("Ingrese la cantidad de estaciones: "); 
    scanf("%d", &n);
    printf("\n");
    
    int **a = calloc(2, sizeof(int *));
    for (int i = 0; i < 2; i++){
        a[i] = calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++){
        printf("Ingrese el costo de la estacion #%d de la Linea 1: ", i); 
        scanf("%d", &a[0][i]);
    }
    printf("\n");
    for (int x = 0; x < n; x++){
        printf("Ingrese el costo de la estacion #%d de la Linea 2: ", x); 
        scanf("%d", &a[1][x]);
    }

    int **t = calloc(2, sizeof(int *));
    for (int i = 0; i < 2; i++){
        t[i] = calloc(n-1, sizeof(int));
    }

    printf("\n");
    for (int s = 0; s < n-1; s++){
        printf("Ingrese el costo de la estacion #%d de la Linea 1 a siguiente estacion de la Linea 2: ", s);
        scanf("%d0", &t[0][s]);
    }
    printf("\n");
    for (int a = 0; a < n-1; a++){
        printf("Ingrese el costo de la estacion #%d de la Linea 2 a siguiente estacion de la Linea 1: ", a);
        scanf("%d0", &t[1][a]);
    }

    int res = min_cost(a, t, n);

    printf("\nEl costo minimo es = %d\n", res);
    
    return 0;
}

