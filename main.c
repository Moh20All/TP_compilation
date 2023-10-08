#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//The transition list structre
typedef struct transition_list{
    char tr;
    struct transition_list* next_tr;//next node list
    struct state* state; // next state
}transition;
//The states list structre
typedef struct states_list{
    int st_name;
    struct transition_list * tran_st;//The head of transition list
    struct state_list* next_st;//netx node list
}state;
// Global variables
state* ST_Head = NULL;
// the creation function of state list
void creation_st(){
    state* states = NULL,*Q=NULL,*temp;
    int nb_st=0 , i=0 , st;
    printf("Enter how many states u have : ");
    scanf("%d",&nb_st);
    while(i<nb_st){// Enter states
        temp = (state*)malloc(sizeof(state));
        printf("Enter state : ");
        scanf("%d",&st);
        temp->st_name = st ;
        temp->tran_st = NULL;
        temp->next_st = NULL;
        if(states == NULL ){
            states= temp;
        }else{
        Q->next_st =temp;
        }
        Q = temp;
        i++;
    }
    ST_Head = states;
}
// Display
void display_st(){
    state* states = ST_Head;
    state* next = NULL;
    transition* tran = NULL;
    while(states!=NULL){
        printf("%d|",states->st_name);
        tran = states->tran_st;
        while(tran!=NULL){
            next = tran->state;
            printf(" (%c->%d) ",tran->tr,next->st_name);
            tran= tran->next_tr;
        }
        printf("|\n");
        states= states->next_st;
    }
}
//the creation function of transition
void creation_tr(){
    state* states = ST_Head; // List states
    state* start =NULL; // The start state
    state* end = NULL; // The end state
    transition* temp_tr = NULL;
    transition* Q = NULL;
    int nb_tr=0 , i=0 ,founded = 0 ,N=0;
    char tr,a[3];
    printf("\n\nEnter how many Transition have : ");
    scanf("%d",&nb_tr);
    while(i<nb_tr){
        scanf("%s",a);
        states = ST_Head ;
        N = a[0]-48;
        if(N>=0&&N<=100){
        while(states->next_st!=NULL && !founded){// Find a[0] state and locate it
            if(states->st_name == N){
            founded = 1;
            start = states;
            }
            states=states->next_st;
        }
        states = ST_Head ;
        if(founded == 0){ // Transition not found
        printf("\n The first state cannot be found\n");
        }else{
        founded=0;
        N = a[2]-48;
        while(states->next_st!=NULL && !founded){// find the next state
            if(states->st_name == N){
            founded = 1;
            end = states;
            }//if
            states=states->next_st;
        }//while
        }//else
        // create temp Node
        temp_tr = (transition*)malloc(sizeof(transition));
        temp_tr->tr = a[1]; // transition name
        temp_tr->next_tr =NULL;
        temp_tr->state = end;
        if(start->tran_st == NULL){// Link the transition to first state
            start->tran_st = temp_tr;
        }else{
            Q = start->tran_st;
            while(Q->next_tr!=NULL){
                Q=Q->next_tr;
            }
            Q->next_tr = temp_tr;

        }//else
        i++;
        }//first if
    }
}
int main()
{
    creation_st();
    creation_tr();
    display_st();
    return 0;
}
