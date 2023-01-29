#include <stdio.h>
#include <stdlib.h>

// Kaweewat Kansupattanakul 65543206003-7
// https://youtu.be/ohZslFnvb-8
struct Node {
    int data ;
    struct Node* next ;
};


// show all
void ShowAll(struct Node* start){
    struct Node* current = start ;
    while (current != NULL){
        printf("%d ", current -> data) ;
        current = current -> next ;
    }
    printf("\n") ;
}

// addnode
void AddNode(struct Node** start, int data){
    struct Node* new_data = (struct Node*) malloc(sizeof(struct Node)) ;
    new_data -> data = data ;
    new_data -> next = *start ;
    *start = new_data ;
}

// update data
void UpdateNode(struct Node* start, int number, int new_num){
    struct Node* current = start ;
    while (current != NULL){
        if (current->data == number){
            current->data = new_num ;
            return ;
        }
        current = current->next ;
    }
}

int main() {
    //fixible code
    struct Node* start = NULL ;
    AddNode(&start, 40) ;
    AddNode(&start, 30) ;
    AddNode(&start, 20) ;
    AddNode(&start, 10) ; 
    printf("Standad number :  ") ;
    ShowAll(start) ;    //10,20,30,40
    
        // Update number
    UpdateNode(start, 10, 99) ;
    printf("Update 10 to 99 :  ") ;
    ShowAll(start) ;  //99,20,30,40
    
        // Update number
    UpdateNode(start, 99, 98) ;
    printf("Update 99 to 98 :  ") ;
    ShowAll(start) ;  //99,20,30,40
          
}
