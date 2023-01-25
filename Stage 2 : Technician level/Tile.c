#include "Tile.h"

struct tile T_create(char letter,char *color){
    struct tile t;
    
    t.letter = letter;
    t.color = color;
    
    //printf("%c %s", t.letter,t.color);
    return t;
}

void T_show(struct tile t){
    
    color colour = C_fromColorName(t.color);
    color bg_color = C_BLACK;
    
    C_printChar(t.letter,colour,bg_color);
    printf(" ");
}