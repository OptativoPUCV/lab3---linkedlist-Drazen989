#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *lista = (List *)malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
  return lista;

}

void * firstList(List * lista) {
  if (lista->head == NULL) {
    
    return NULL;
  }
  lista->current = lista->head;
  return lista->current->data;
  
  
}

void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL){
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  if (list->tail == NULL) {
    return NULL;
  }
  list->current = list->tail;
  return list->current->data;
}

void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL){
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node * nuevo = createNode(data);
  if (list->head == NULL){
    list->head = nuevo;
    list->tail = nuevo;
    list->current = nuevo; 
  }
  else{
    nuevo->next = list->head;
    list->head->prev = nuevo;
    list->head = nuevo;
    list->current = nuevo;
  }
  
}

void pushBack(List * list, void * data) {
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node * nuevo = createNode(data);
  if (list->current == NULL){
    list->head = nuevo;
    list->tail = nuevo;
    list->current = nuevo;
  }
  else{
    nuevo->next = list->current->next;
    nuevo->prev = list->current;
    list->current->next = nuevo;
    if (nuevo->next != NULL){
      nuevo->next->prev = nuevo;
    }
    else{
      list->tail = nuevo;
    }
  }
}

void * popFront(List * list) {
  list->current = list->head;
  return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if (list->current == NULL){
    return NULL;
  }
  else{
    Node * aux = list->current;
    if (list->current->prev != NULL){
      list->current->prev->next = list->current->next;
    }
    else{
      list->head = list->current->next;
    }
    if (list->current->next != NULL){
      list->current->next->prev = list->current->prev;
    }
    else{
      list->tail = list->current->prev;
    }
    
    list->current = list->current->next;
    return aux->data;
  }
  
}


void cleanList(List * list) {
  while (list->head != NULL) {
    popFront(list);
      
  }
  
  
}