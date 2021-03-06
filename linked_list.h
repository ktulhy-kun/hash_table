#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "errors.h"
#include <stdlib.h>

typedef struct _Element {
  struct _Element *next;
  void *data;
} Element;

typedef struct {
  Element *root;
  Element *end;
  u_int64_t nCollision;
} LinkedList;

#ifndef MEMORY_ALLOCATE_ERROR
#define MEMORY_ALLOCATE_ERROR (72100)
#endif

#ifndef LINK_ERROR
#define LINK_ERROR (72101)
#endif

#define DEBUG_LINKED_LIST

LinkedList *initializeList(Error *error);
int insertDataIntoList(LinkedList *list, void *data, Error *error);
Element *findDataInList(LinkedList *list, void *data, int (*isConcur)(void *, void *));
int removeDataFromList(LinkedList *list, void *data, int (*isConcur)(void *, void *));
void setError(Error *error, int errorValue, char *str);
void deleteList(LinkedList **list);
#ifdef DEBUG_LINKED_LIST
void printList(LinkedList *list);
#endif
/* Todo: написать фукнцию, разрушающую список/элемент */

#endif // LINKED_LIST_H
