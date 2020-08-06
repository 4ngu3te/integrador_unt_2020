#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LogEntry.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"

LogEntry* new_entry()
{
  LogEntry* this = (LogEntry*)malloc(sizeof(LogEntry));;
  if(this!=NULL)
    {
      setDate(this,"");
      setTime(this,"");
      setServiceName(this,"");
      setGravedad(this,0);
      setMensaje(this,"");
    }
  return this;
}
LogEntry* entryNewParam(char* date,char* time,char* serviceName,char* gravedad,char* msg)
{
  LogEntry* this = new_entry();
  if(this!=NULL && date!=NULL && time!=NULL && serviceName!=NULL && gravedad!=NULL && msg!=NULL)
    {
      setDate(this,date);
      setTime(this,time);
      setServiceName(this,serviceName);
      setGravedad(this,atoi(gravedad));
      setMensaje(this,msg);
    }
  return this;
}
/*
 * SETTERS
 */
int setDate(LogEntry* this, char* date)
{
  int ok = -1;
  if(this!=NULL && strlen(date)>0)
    {
      strcpy(this->date,date);
      ok=0;
    }
  return ok;
}
int setTime(LogEntry* this, char* time)
{
  int ok = -1;
  if(this!=NULL)
    {
      strcpy(this->time,time);
      ok=0;
    }
  return ok;
}
int setServiceName(LogEntry* this, char* serviceName)
{
  int ok = -1;
  if(this!=NULL && strlen(serviceName)>0)
    {
      strcpy(this->serviceName,serviceName);
      ok=0;
    }
  return ok;
}
int setGravedad(LogEntry* this, int gravedad)
{
  int ok =-1;
  if(this!=NULL && gravedad >= 0)
    {
      this->gravedad = gravedad;
    }
  return ok;
}
int setMensaje(LogEntry* this, char* msg)
{
  int ok = -1;
  if(this!=NULL && strlen(msg)>0)
    {
      strcpy(this->msg,msg);
      ok=0;
    }
  return ok;
}
/*
 * GETTERS
 */
int getDate(LogEntry* this, char* date)
{
  int ok = -1;
  if(this!=NULL)
    {
      strcpy(date,this->date);
      ok=0;
    }
  return ok;
}
int getTime(LogEntry* this, char* time)
{
  int ok = -1;
  if(this!=NULL)
    {
      strcpy(time,this->time);
      ok=0;
    }
  return ok;
}
int getServiceName(LogEntry* this, char* serviceName)
{
  int ok = -1;
  if(this!=NULL && sizeof(serviceName)<=65)
    {
      strcpy(serviceName,this->serviceName);
      ok=0;
    }
  return ok;
}
int getGravedad(LogEntry* this, int* gravedad)
{
  int ok =-1;
  if(this!=NULL && gravedad >= 0)
    {
      *gravedad = this->gravedad;
    }
  return ok;
}
int getMensaje(LogEntry* this, char* msg)
{
  int ok = -1;
  if(this!=NULL && sizeof(msg)<=65)
    {
      strcpy(msg,this->msg);
      ok=0;
    }
  return ok;
}
int menu()
{
  int opcion = 0;
  printf("\n1.Leer Log.\n2.Procesar información.\n3.Mostrar estadísticas.\n4.Imprimir lista logs\n5.Salir.\n");
  utn_getNumero(&opcion,"\nIngrese un opcion: ","Opcion invalida",1,5,3);
  return opcion;
}
void header()
{
  printf("|  FECHA   |  HORA  |       NOMBRE DEL SERVICIO QUE FALLO      |  MENSAJE DE ERROR  | GRAVEDAD DEL ERROR ");
}

int listarEntrada(LogEntry* this)
{
  int ok =-1;
  if(this!=NULL)
    {
      printf("\n%11s %6s %35s %27s %10d",this->date,this->time,this->serviceName,this->msg,this->gravedad);
      ok=0;
    }
  return ok;
}

int calcGravedad_warnings(void* element)
{
  LogEntry* caso = (LogEntry*)element;
  int tipo;
  int ok=-1;
  getGravedad(caso,&tipo);
  if(element!=NULL)
    {
      if(tipo >= 4 && tipo <= 7)
	{
	  ok = 1;
	}
    }
  return ok;
}

int calcGravedad_errors(void* element)
{
  LogEntry* caso = (LogEntry*)element;
  int tipo;
  int ok=-1;
  getGravedad(caso,&tipo);

  if(element!=NULL)
    {
      if(tipo >= 8)
	{
	  ok = 1;
	}
    }
  return ok;
}

int ordenamiento(void* gravedad1,void* gravedad2)
{
  if(gravedad1!=NULL && gravedad2!=NULL)
    {
      if(((LogEntry*)gravedad1)->gravedad < ((LogEntry*)gravedad2)->gravedad)
	{
	  return 1;
	}
      if(((LogEntry*)gravedad1)->gravedad > ((LogEntry*)gravedad2)->gravedad)
	{
	  return -1;
	}
    }
  return 0;
}
/*
int ordenarLogs(void* element,void* element2,void* element3)
{
  LogEntry* gravedad = (LogEntry*)element;
  LogEntry* gravedad2 = (LogEntry*)element2;
  LogEntry* gravedad3 = (LogEntry*)element3;
  int ok =-1;
  int tipoError;
  if(gravedad!=NULL)
    {
      getGravedad(gravedad,&tipoError);
      if(tipoError == 3)
	{
	  ok=1;
	}
      if(tipoError < 3)
	{
	  ok=
	}
    }
  return ok;
}

int listartres(LinkedList* this)
{
  int gravedad;
  if(this!=NULL)
    {
      getGravedad(this);
    }
}
*/
  /*for(j=0;j<tam[0];j++)
 	{
 	  getGravedad(this,&gravedad[0]);
 	  if(gravedad[0] == 3)
 	    {
 	      listarEntrada(this);
 	    }
 	}
       for(k=0;k<tam[3];j++)
       	{
       	  getGravedad(this,&gravedad[0]);
       	  if(gravedad[1] >=4 && gravedad[1] <=7)
       	    {
       	      listarEntrada(this);
       	    }
       	}
     }*/
