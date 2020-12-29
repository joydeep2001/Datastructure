/*AUTHOR : PASSIONATE_CODER
DATE : 29/12/2020

DESCRIPTION::
Implementation of a Priority Queue
using a Doubly linked list
*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct priority_q{
    int data;
    int pr;
    struct priority_q* next;
    struct priority_q* prev;

};
typedef struct priority_q pq;
pq* start = NULL;

int enqueue(int val, int pr){
    pq* newNode;
    //Creating a new node
    newNode = (pq*)malloc(sizeof(pq));
    //initializing the data and priority of the node
    newNode->data = val;
    newNode->pr = pr;

    //if the node is the first ever node
    if(start == NULL){
        start = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    //if the node is not first ever node
    else{
        pq* temp;
        for(temp = start;temp->next != NULL && temp->pr <= pr;temp = temp->next);
        //if the node is to be inserted at the end
        if(temp->next == NULL){
            newNode->prev = temp;
            temp->next = newNode;
            newNode->next = NULL;
        }
        //if the node is to be inserted at the start
        else if(temp == start){
            temp->prev = newNode;
            newNode->next = start;
            start = newNode;
        }
        //if the node is to be inserted in between of any two node
        else{
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;

        }

    }

}


int dqueue(){
    start = start->next;
    start->prev = 0;

}


int display(){
    pq* temp;
    for(temp = start;temp != NULL;temp = temp->next){
        printf("\(%d, %d)->",temp->data,temp->pr);
    }
    printf("\n");


}


int main(){
    enqueue(10,3);
    enqueue(11,3);
    enqueue(5,2);
    enqueue(1,1);
    enqueue(3,2);
    display();
    dqueue();
    display();
    dqueue();
    display();
    getch();
    return 0;
}
