#include <stdio.h>
#include <stdlib.h>

/*Integrantes:
    -Eleazar Vasquez
    -Manuel Jaramillo
    -Patricio Canales
*/
int field = 1;
int main(){
    
    //Se piden las dimensiones del tablero
    int fil, col;
    scanf("%i %i", &fil, &col);
    while(fil!=0 & col!=0){
        char tablero[fil*col];

        //Se pide el tablero de las dimensiones fil*col
        char tableroRelleno[fil*col];
        int puntero = 0;
        for (int i=0; i<fil; i++){
            char text[col];
            scanf("%s", text);
            for (int p=0; p<col; p++){
                tableroRelleno[puntero] = text[p];
                puntero = puntero+1;
            }
        }
        //Se crea el tablero lleno de 0's
        for (int i=0; i<fil; i++){
            for(int j=0; j<col; j++){
                tablero[i*col + j] = '0';
            }
        }
        //Reemplazar los 0 por * donde corresponda
        for(int i=0; i<fil*col; i++){
            if (tableroRelleno[i] == '*'){
                tablero[i] = '*';
            }
        }
        //Sumar alrededores del *
        for(int i=0; i<fil*col; i++){
            if (tablero[i] == '*'){
                for(int f=-1; f<=1; f++){ //Recorrer un espacio de 3 filas
                    for(int c= i+(col*f)-1; c<=i+(col*f)+1; c++){ // Recorrer un espacio de 3 columnas
                        if((c>=0 & c<=(fil*col-1))& (tablero[c] != '*')){  //Evita que intente escribir en posiciones no definidas o sobre otros '*'
                            tablero[c] = (int)tablero[c]+1;
                            if((i%col==col-1) & (c==i+(col*f)+1)){  //Evita que *'s de la última columna sumen a su derecha
                                tablero[c] = (int)tablero[c]-1;
                            }
                            if((i%col==0) & (c==i+(col*f)-1)){ //Evita que *'s de la primera columna sumen a su izquierda
                                tablero[c] = (int)tablero[c]-1;
                            }   
                        }
                    }
                }
            }
        }
        //Se imprime el tablero final
        printf("\nField #%i:\n", field);
        for (int i=0; i<fil; i++){
            for(int j=0; j<col; j++){
                printf("%c", tablero[i*col+j]);
            }
            printf("\n");
        }
        field++;
        printf("\n");
        scanf("%i %i", &fil, &col);
    }
}