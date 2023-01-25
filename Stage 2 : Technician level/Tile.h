#ifndef TILE
#define TILE
#include "color.h"

struct tile{
    char letter;
    char *color;
    
};

struct tile T_create(char letter,char *color);
void T_show(struct tile t);
#endif

