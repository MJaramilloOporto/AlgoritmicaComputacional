/*Integrantes:
    -Eleazar Vasquez
    -Manuel Jaramillo
    -Patricio Canales
*/
#include <cstdio>
 
int main ()
{
    int i, j;
    while (1) {
        scanf ("%d %d", &i, &j);
        int i_aux = i;
        int j_aux = j;
 
        if (i>j){
            int aux = i;
            i = j;
            j = aux;
        }
 
        int cadena_mas_larga = 0;
        int cadena_actual;
 
        while ( i <= j ) {
            int n = i;
            cadena_actual = 1;
 
            while ( n != 1 ) {
                if (n%2 ==1){
                    n = (3*n) +1;
                }else{
                    n = n/2;
                }
                cadena_actual++;
            }
            if ( cadena_actual > cadena_mas_larga )
                cadena_mas_larga = cadena_actual;
            i++;
        }
 
        printf ("%d %d %d\n", i_aux, j_aux, cadena_mas_larga);
    }
 
    return 0;
}
 