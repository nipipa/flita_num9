#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *matrix, *graf;
    char mas[100];
    char s = ' ';
    int i = 0, a = 0;
    int k,j, rez1, kol;
    matrix = fopen("matrix_of_incendence198.txt", "r"); // открываем файл с матрицей
    while(!feof(matrix)){
        if (a == 0 && s == '\n'){ // обраюатываем матрицу и записываем в массив
            a = i;
        }
        if (s == '1' || s == '0'){
            mas[i] = s;
            i++;
        }
        fscanf(matrix, "%c", &s);
    } 
    for ( j = 1; j <= a; j++){ // выводим список смежности
        kol = 0; 
        for ( k = j; k <= i; k++){
            if(mas[k-1] == '1'){
                if (kol > 0){
                    printf("%d\n", k/(a+1)+1);
                    break;
                }
                if (kol == 0){
                    kol++;
                    printf("%d: ", k/(a+1)+1);
                }
            }
            k += a-1; 
        }
    }
    graf = fopen("graf.gv", "w"); // создаем файл для GraphViz
    fprintf(graf, "digraph Grah {\n"); 
    for (j = 1; j <= a; j++){
        kol = 0;
        for (k = j; k <= i; k++){
            if(mas[k-1] == '1'){
                if (kol > 0){
                    fprintf(graf, "\"%d\"\n",  k/(a+1)+1); // записываем в файл данные для отображения в графвизе графа
                    break;
                }
                if (kol == 0){
                    kol++;
                    fprintf(graf, "\"%d\"-> ",  k/(a+1)+1);
                }
            }
            k += a-1;
        }
    }
    fprintf(graf, "}"); 
    fclose(graf); // закрываем файл

    return 0; 
}   
