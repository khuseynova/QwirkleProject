#include <stdio.h>

#include <ctype.h>
#include "color.c"

int main(){
    char name[50];
    char str[50];
    char letter;
    char colorN[10];
    

    printf("Hello what is your name? ");
    fgets(name, sizeof(name),stdin);
    name[strlen(name)-1] = '\0';
    while(1){
        
        printf("\nDear %s, enter a capital letter and a color : ",name);
        fgets(str, sizeof (str),stdin);
        sscanf(str,"%c %s",&letter,colorN);
        int variables =  sscanf(str,"%c %s",&letter,colorN);
        char *color_name = colorN;
        color colour = C_fromColorName(color_name);
        color bg_color;
        
        if(variables == 1 && isupper(letter)){
            C_printChar(letter,C_DEFAULT,C_DEFAULT);
        }
        else if (isupper(letter) && variables == 2 )
        {
            
            
            if(colour != C_UNKNOWN)
            {
                bg_color == C_BLACK;
                C_printChar(letter,colour,bg_color); 
                
            }
            if(colour == C_UNKNOWN){
                
                printf("\nDear %s, I cannot recognize this color\nThe only recognized colors are red, green, blue, yellow, purple, orange or white.\n",name);
            }
            
        }
        
        else if(islower(letter)){
            printf("\nDear %s, I wish you farewell and hope to see you again!\n",name);
            break;
        }
    }
    
    
    printf("\n");
    return 0;
}
