#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main(){
    char y;
    double a,b,c=0.0;
    double silnia, delta,temp;
    double wynik;

    for (int i=1;i<20;i++){

    printf("\n"
            "\nMenu:\n"
            "a) Dodawanie\n"
            "b) Odejmowanie\n"
            "c) Mnożenie\n"
            "d) Dzielenie\n"
            "e) Pierwiastek kwadratowy\n"
            "f) Potęgowanie\n"
            "g) Silnia\n"
            "h) Rozwiązanie rówanania kwadratowego\n"
            "q) Exit\n"
            "Wybierz:"
        );

    scanf(" %c",&y); 
    
      
        wynik=0;
    switch (y) {
        case 'a' :
            printf("Wpisz pierwsza liczbe:\n");
            scanf(" %lf",&a);
            printf("Wpisz druga liczbe:\n");
            scanf(" %lf",&b);
            
            wynik = a+b;
            printf("%g",wynik);
        break;
        case 'b':
            printf("Wpisz pierwsza liczbe:\n");
            scanf(" %lf",&a);
            printf("Wpisz druga liczbe:\n");
            scanf(" %lf",&b);
        
        wynik= a-b;
        printf("%g",wynik);
        break;
        case 'c':
            printf("Wpisz pierwsza liczbe:\n");
            scanf(" %lf",&a);
            printf("Wpisz druga liczbe:\n");
            scanf(" %lf",&b);
        
         wynik= a*b;
         printf("%g",wynik);
        break;
        case 'd':
            printf("Wpisz pierwsza liczbe:\n");
            scanf(" %lf",&a);
			printf("Wpisz druga liczbe:\n");
            scanf(" %lf",&b);
            
        if(b!=0){
            wynik= a/b;
            printf("%g",wynik);
        }
        else{
            printf("Error");
        }
         
        break;
        case 'e':
			printf("Wpisz liczbe do spieriwastkowania:\n");
            scanf(" %lf",&a);

            if(a>0){
                wynik= sqrt(a);
                printf("%g",wynik);
            }
            else{
                printf("Error");
            }
        break;
        case 'f':
			printf("Wpisz pierwsza liczbe:\n");
            scanf(" %lf",&a);
			printf("Wpisz druga liczbe:\n");
            scanf(" %lf",&b);
            
            if(a>=0 && a<=100 && b<=10){
                wynik=pow(a,b);
                printf("%g",wynik);
            }
            else{
            printf("Error");
        }
        break;
        case 'g':
			printf("Wpisz liczbe do obliczenia silni:\n");
            scanf(" %lf",&a);
            wynik =1.0;
             if(a>0 && a<100){
                 for(int i =a; i>1;i--){
                     wynik*=i;
                }
                printf("%g",wynik);
             }
             else if(a==0.0){
                 printf("%.1lf",wynik);
             }
             else {
                  printf("Error");
             }
            
        break;
        case 'h':
			printf("Wpisz A:\n");
            scanf(" %lf",&a);
			printf("Wpisz B:\n");
            scanf(" %lf",&b);
			printf("Wpisz C:\n");
            scanf(" %lf",&c);
            
            if(a==0){
                printf("Error: To nie jest równanie kwadratowe i nie liczę reszty");
            }
            else{
                double delta = b*b - 4*a*c;
                if(delta ==0){
                      printf("%g\n", -b/(2*a));}
                else if(delta>0){
                    wynik= (-b-sqrt(delta))/(2*a);
                    printf("%.1lf\n", wynik);
                    wynik= (-b+sqrt(delta))/(2*a);
                    printf("%.1lf\n", wynik);
                   
                }
                else{
                     printf("Error: Brak rozwiązania");
                }
            }
        break;
        case 'q':
            return;
        default:
            printf("Error");
            break;
        
    }
     
    } 
}