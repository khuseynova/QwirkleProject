#ifndef BLAH
#define BLAH
#include "Tile.h"
struct tileList {
    struct tile tile;
    struct tileList *next;
};
struct tileList* TL_createEmptyBag();

struct tileList* TL_newTile(struct tile tile);
struct tileList* TL_addTile(struct tileList *bag,struct tile tile);
void TL_removeTile(struct tileList **bag,int index);
struct tileList* TL_generateBag(int sampleNum,struct tileList *bag);
void TL_show(struct tileList *plist);
struct tile TL_getTile(struct tileList *bag);
struct tileList* TL_nth(struct tileList *plist, int n);

int generate(int length);
int len(struct tileList *list);

#endif