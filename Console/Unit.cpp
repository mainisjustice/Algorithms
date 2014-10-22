//---------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <windows.h>
//---------------------------------------------------------------------------
int **mas = NULL;  //матрица вершин графа
int kol = 0;  //количество вершин

//---------------------------------------------------------------------------
//вычисление минимального пути по алгоритму Ф-У
void minFL(int **m, int kl){
try{
        for(int k=0; k<kl; k++){
                for(int i=0; i<kl; i++){
                        for(int j=0; j<kl; j++){
                                //отсеиваиваем пути сами в себя и сложение с бесконечным расстоянием
                                if((i==j)||(m[i][k]<=0)||(m[k][j]<=0)) continue;

                                if( (m[i][k]+m[k][j]<m[i][j]) || (m[i][j]<=0) ) m[i][j] = m[i][k]+m[k][j];
                        }
                }
        }
}catch(...){
        printf("Îøèáêà!");
}
}

//---------------------------------------------------------------------------
//Отчистка переменных
void clear(){
        if(mas!=NULL){
                for(int i=0; i<kol; i++) delete mas[i];
                delete mas;
        }
}

//---------------------------------------------------------------------------
void main()
{
        SetConsoleOutputCP(1251);//чтобы русский язык был виден в консоли
        
        printf("Введите число вершин графа: ");
        scanf("%i",&kol);

        mas = new int*[kol];
        for(int i=0; i<kol; i++) mas[i] = new int[kol];

        printf("Введите матрицу смежности графа: \n");
        for(int i=0; i<kol; i++)
                for(int j=0; j<kol; j++) scanf("%i",&mas[i][j]);

        minFL(mas, kol); //применение алогритма

        printf("Минимальные пути между вершинами: \n");
        for(int i=0; i<kol; i++){
                for(int j=0; j<kol; j++){
                         printf("%i ",mas[i][j]);
                }
                printf("\n");
        }

        clear();

        system("pause");
}
//---------------------------------------------------------------------------
 
