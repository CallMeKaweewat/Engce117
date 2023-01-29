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

// swap data1 and data2
void SwapNode(struct Node* start, int swap_data1, int swap_data2){
    struct Node *state = start, *state_2 = start;
    //while loop state
    while (state != NULL && state -> data != swap_data1){
        state = state->next ;
    }
    //while loop state_2
    while (state_2 != NULL && state_2->data != swap_data2){
        state_2 = state_2->next;
    } 
    if (state != NULL && state_2 != NULL){
        int storage  = state->data ;
        state->data = state_2->data ;
        state_2->data = storage ;
    }
    else {
        printf("data err %d and %d not found\n", swap_data1, swap_data2) ;
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
    ShowAll(start);    //10,20,30,40
    
    // swap number 30 20
    SwapNode(start, 20, 30) ;
    printf("Swap number 30 20:  ") ;
    ShowAll(start) ;  //20,99,30,40
    
    // swap number 40 10
    SwapNode(start, 40, 10) ;
    printf("Swap number 40 10:  ") ;
    ShowAll(start) ;  //20,99,30,40
        
    
}
