#include "TileList.h"


int main(){
    char name[50];
    printf("Hello what is your name? ");
    fgets(name, sizeof(name),stdin);
    name[strlen(name)-1] = '\0';
    int numOfSamples;
    printf("Dear %s, how many samples of each tile would you like to have?", name);
    scanf("%d",&numOfSamples);
    struct tileList *bag=TL_createEmptyBag();
    bag=TL_generateBag(numOfSamples,bag);
    
    
    

    // TL_show(bag);
    
    while(1){
        if(len(bag) == 0){
            printf("Farawell Dear %s! Come back soon!",name);
            break;
        }
        printf("Perfect, your bag contains %d number of tiles.\n",len(bag));
        int numOfTiles;
        printf("Dear %s, how many tiles would you like to pick from the bag?", name);
        scanf("%d",&numOfTiles);
        if(numOfTiles > len(bag)){
            numOfTiles = len(bag);
        }
        struct tileList *deck=TL_createEmptyBag();
        
        for(int i=0; i<numOfTiles; i++){
            int random_index=generate(len(bag));
            deck=TL_addTile(deck,TL_nth(bag,random_index)->tile);
            TL_removeTile(&bag,random_index);
        }
        
        TL_show(deck);
        printf("\n");
    }
    
    
    printf("\n");
    return 0;
}

//create 16 data structures with A B C D nd different colors in rder to
//make a collection of n*16 tiles