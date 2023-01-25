#include "TileList.h"


struct tileList* TL_createEmptyBag(){
    return NULL;
}

struct tileList* TL_newTile(struct tile tile){
    struct tileList *list;
    list = (struct tileList*) malloc(sizeof(struct tileList));
    list->tile = tile;
    list->next = NULL;
    return list;
}

struct tileList* TL_addTile(struct tileList *bag,struct tile tile){
    struct tileList *newTile = TL_newTile(tile);
    newTile->next = bag;
    return newTile;    // data must be filled in reverse 


}

void TL_removeTile(struct tileList **bag,int index){
    // If linked list is empty
   if (*bag == NULL)
      return ;
 
   // Store head node
   struct tileList* holder = *bag;
 
    // If head needs to be removed
    if (index == 0)
    {
        *bag = holder->next;   // Change head
        free(holder);               // free old head
        return ;
    }
 
    // Find previous node of the node to be deleted
    for (int i=0; holder!=NULL && i<index-1; i++)
        holder = holder->next;
 
    // If position is more than number of nodes
    // if (holder == NULL || holder->next == NULL)
    //      return ;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct tileList *next = holder->next->next;
 
    // Unlink the node from linked list
    free(holder->next);  // Free memory
 
    holder->next = next;  // Unlink the deleted node from list
}

struct tileList* TL_generateBag(int sampleNum,struct tileList *bag){

    int count=0;
    char letters[4]={'A','B','C','D'};
    for (int i=0;i<sampleNum;i++){
        for(int j=0;j<4;j++){
            bag=TL_addTile(bag,T_create(letters[j],"red"));
            bag=TL_addTile(bag,T_create(letters[j],"blue"));
            bag=TL_addTile(bag,T_create(letters[j],"yellow"));
            bag=TL_addTile(bag,T_create(letters[j],"green"));
        }
    }
    return bag;
}

void TL_show(struct tileList *deck){
    int i = 0;
    struct tileList *list = deck;
    
    while (list != NULL){
        T_show((list->tile));
        list = list->next;
        i++;
    }
    
}

int len(struct tileList *list){
    struct tileList *iter=list;
    int counter=0;
    while(iter!=NULL){
        counter++;
        iter=iter->next;
    }
    return counter;
}

struct tileList* TL_nth(struct tileList *plist, int n){
    int count = 0;
    if (n < len(plist)){
       while (plist != NULL) {
            if (count == n){
                return plist;
            }
            count++;
            plist = plist->next;
        } 
    }
    else{
       printf("n is >= that the length ,unable to proceed -> ");
       return (NULL); 
    }
}


int generate(int length){
    srand(time(0));
    if(length<=0)
    {
        length=1;
    }
    return rand() % length;    
}