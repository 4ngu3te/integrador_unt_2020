
#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int c_loadFromLog(char* path,LinkedList* arrList);
int c_listLog(LinkedList* arrList);
int c_saveAs(char* path,LinkedList* arrList);
int c_informes(LinkedList* this,LinkedList* warnings,LinkedList* errors);
#endif /* CONTROLLER_H_ */
