#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <strings.h>
#include <ctype.h>

void show_password_state(char guessing_password[], int size);
void fill_array_with_lines(char guessing_password[], int size);
int check_character(char password[],char guessing_password[],char znak);
int main(){
    //************************** INITIALIZING PASSWORDS *******************************
    char* vegetables[] = {
    "MARCHEWKA",
    "GROSZEK",
    "DYNIA",
    "CUKINIA",
    "ZIEMNIAK",
    "POMIDOR",
    "PAPRYKA",
    "KALAREPA",
    "KUKURYDZA",
    "POR"
    };
    
    char * spices[]={
    "CURRY",
    "LUBCZYK",
    "CYNAMON",
    "GORCZYCA",
    "OREGANO",
    "ROZMARYN",
    "KURKUMA",
    "BAZYLIA"
    };
    
  char* fruit[]={
    "BANAN",
    "ARBUZ",
    "LIMONKA",
    "JAGODA",
    "MANDARYNKA",
    "TRUSKAWKA",
    "GRUSZKA",
    "WINOGRONO",
    "PORZECZKA",
    "MELON",
  };
  
  char * cities[]={
      "LONDYN",
      "MADRYT",
      "WARSZAWA",
      "PETERSBURG",
      "BERLIN",
      "RZYM",
      "HAMBURG",
      "PRAGA",
      "ODESSA",
      "MEDIOLAN",
      "BARCELONA",
      
  };
    int vegetables_len = 10;
    int spices_len=8;
    int fruit_len = 10;
    int cities_len=11;
  //------------------- randomly selecting a password ---------------------------------
  
    printf("======= HANGMAN THE GAME! =======\n");
    printf("+-----------+\n");
    printf("|          |\n");
    printf("|          O\n");
    printf("|         /|\\\n");
    printf("|         / \\\n");
    
    srand(time(NULL));
    char* chosen_password;
    printf("Wybierz kategorię:\na) Warzywa\nb) Przyprawy\nc) Owoce\nd) Miasta Europy\n\n");
    char choice = fgetc(stdin);
    if(choice=='a'){
        int  random_index = 0+(int)((double)(vegetables_len)*rand()/RAND_MAX);
        chosen_password=vegetables[random_index];
    }
    else if(choice=='b'){
        int  random_index = 0+(int)((double)(spices_len)*rand()/RAND_MAX);
        chosen_password=spices[random_index];
    }
    else if(choice=='c'){
        int  random_index = 0+(int)((double)(fruit_len)*rand()/RAND_MAX);
        chosen_password=fruit[random_index];
    }
    else if(choice=='d'){
        int  random_index = 0+(int)((double)(cities_len)*rand()/RAND_MAX);
        chosen_password=cities[random_index];
    }
    else{
        printf("Nie rozpoznaje kategorii- zamykam program");
        return 0;
    }

//************************************* guessing process ******************************
    int number_of_attempts =0;
    int max_of_attempts= strlen(chosen_password) +2;
    int guessing_password_size=strlen(chosen_password);
    
    char* guessing_password=malloc(sizeof(char)*(guessing_password_size));
    char typed_letters[max_of_attempts];
    char tmp_char;
    
    fill_array_with_lines(guessing_password, guessing_password_size);
    show_password_state(guessing_password, guessing_password_size);
    
    int found = 0;
    int wrong_quesses=0;
    while(number_of_attempts < max_of_attempts ){
        
        printf("Wpisz wybrany znak:");
        do {
            tmp_char = fgetc(stdin);
        } while(tmp_char == '\n');
        if(isalpha(tmp_char)){
            
            tmp_char = toupper(tmp_char);
            found=check_character(chosen_password, guessing_password,tmp_char);
            if(strcmp(chosen_password,guessing_password)==0){
                printf("\n\n ************ Udalo Ci sie zgadnąć hasło  ************ \n"); 
                printf("\n\n ****************** GRATULACJE !!!!!  **************** \n\n");
                break;
            }
        }
        
        
        if(found==0){
              typed_letters[wrong_quesses]=tmp_char;
              wrong_quesses++;
              number_of_attempts++;
        }
        else{
            found=1;   
        }
            
        printf("password: ");
        show_password_state(guessing_password, guessing_password_size);
        
        printf("Uzyte błędne znaki: ");
        show_password_state(typed_letters, wrong_quesses);
       
    
        printf("Pozostało prob: %d\n", max_of_attempts-number_of_attempts);
        printf("\n");
    
    }
    if(number_of_attempts == max_of_attempts){
     printf("Game Over - you lost\n");
    }
    
     printf("Hasło to: %s",chosen_password);
    return 0;
}


void show_password_state(char password[], int size){
    for(int index = 0; index<size;index++){
      printf("%c ", password[index]);
    }
    printf("\n");
}

void fill_array_with_lines(char guessing_password[], int size){
    for(int index = 0; index<size;index++){
     guessing_password[index]='_';
    }
}

int check_character(char password[],char guessing_password[],char znak){
    int found= 0;
    int size = strlen(password);
    
    for(int i =0;i<size;i++){
        if(password[i]==znak){
            guessing_password[i]=znak;
            found=1;
        }
    }
    return found;
}
    
