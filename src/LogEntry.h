#include "LinkedList.h"
#ifndef LOGENTRY_H_
#define LOGENTRY_H_

typedef struct
{
  char date[11];
  char time[6];
  char serviceName[65];
  int gravedad;
  char msg[65];
}LogEntry;

#endif /* LOGENTRY_H_ */

LogEntry* new_entry();
LogEntry* entryNewParam(char* date,char* time,char* serviceName,char* gravedad,char* msg);

int setDate(LogEntry* this, char* date);
int setTime(LogEntry* this, char* time);
int setServiceName(LogEntry* this, char* serviceName);
int setGravedad(LogEntry* this, int gravedad);
int setMensaje(LogEntry* this, char* msg);

int getDate(LogEntry* this, char* date);
int getTime(LogEntry* this, char* time);
int getServiceName(LogEntry* this, char* serviceName);
int getGravedad(LogEntry* this, int* gravedad);
int getMensaje(LogEntry* this, char* msg);

int menu();
void header();
int listarEntrada(LogEntry* this);

int calcGravedad_warnings(void* element);
int calcGravedad_errors(void* element);

int ordenamiento(void* gravedad1,void* gravedad2);
