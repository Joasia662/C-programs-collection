#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * encode(char password[], int code_key);
char * decode(char password[], int code_key);

int main (void)
{
    int code_key;
    char password[100];
    char password_to_decode[100];
    
    
    printf("Podaj proszę haslo do zakodowania\n");
    fgets(password,100,stdin);
    printf("%s\n",password);
    
    //printf("Podaj proszę haslo do odkodowania\n");
   //fgets(password_to_decode,100,stdin);
    
    printf("Podaj proszę klucz kodowania\n");
    scanf("%d", &code_key);
    if(code_key>94)
    {
        printf("Klucz kodowania nie może przekraczać 94- brak celu w tym działaniu,ponieważ jest tylko 94 widocznych znaków w tablicy ASCII");
        return 0;
    }

    char * coded_password = encode(password, code_key);
    printf("\nZakodowane hasło to: %s", coded_password);
    
   
    char *  uncoded_password = decode(coded_password, code_key);
    printf("Odkodowane hasło to: %s \n", uncoded_password, code_key);
    
    return 0;
}

char* encode(char password[], int key)
{   
    char * result=malloc(sizeof(char)*strlen(password));
    int size = strlen(password);
    for (int index =0; index< size; index++)
    {         if(password[index]>33)
              {
                   result[index]= password[index]+key;
                if(password[index]+key>127) 
                {  
                    int value=password[index]+key-127+33;
                    result[index]= value;
                }
                else if(result[index]<33)
                { 
                    int value = 127- password[index]-key;
                    result[index]= value;
                }
              }
              else result[index]= password[index];
    }
    return result;
}

char* decode(char password[], int key)
{   
    char * result=malloc(sizeof(char)*strlen(password));
    int size = strlen(password);
    for (int index =0; index< size-1; index ++)
    {   if(password[index]>33)
        {
            result[index]= password[index]-key;
            if(password[index]-key>127) 
            {  
                int value=password[index]+key-127;
                result[index]= value;
            }
            else if(result[index]<33)
            { 
                int value =password[index]-key-33+127;
                result[index]= value;
            }
        }
        else result[index]= password[index];
    }
    return result;
}

