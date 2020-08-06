#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LogEntry.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"

int c_loadFromLog(char* path,LinkedList* arrList)
{
  int ok=-1;
   FILE* pFile;
   if(path!=NULL && arrList!=NULL)
     {
       pFile =fopen(path,"r");
 	if(pFile!=NULL)
 	  {
 	      if(parserFromLog(pFile,arrList)==0)
 		{
 		  printf("\nLeido\n");
 		  ok = 0;
 		}
 	      else if(parserFromLog(pFile,arrList)==-1)
 		{
 		  printf("\nMal leido");
 		}
 	      else
 		{
 		  printf("\nError");
 		}
 	  }
     }

   return ok;
}


int c_listLog(LinkedList* arrList)
{
  int ok = -1;
  int i;
  int tam;
  LogEntry* aux;

  if(arrList != NULL)
    {
      tam = ll_len(arrList);
      ll_sort(arrList,ordenamiento,1);
      header();
      for(i=0;i<tam;i++)
	{
	  aux = (LogEntry*)ll_get(arrList,i);
	  listarEntrada(aux);
	  ok = 0;
	}
    }
  return ok;
}

int c_saveAs(char* path,LinkedList* arrList)
{
  int ok = -1;
  FILE* log;
  LogEntry* entry;
  char info[4][65];
  int gravedad;
  int tam;
  int i;
  if(path!=NULL && arrList!=NULL)
    {
      //1.tomar de la arr list los graves y discriminarlos
      //2.si son menores a 3 descartarlos,sin son entre 4 y 7 a warnings,mayor a 7 a errors
      tam = ll_len(arrList);
      log = fopen(path,"w");
      if(tam > 0 && log != NULL)
	{
	  for(i=0;i<tam;i++)
	      {
		entry = (LogEntry*)ll_get(arrList,i);
		getDate(entry,info[0]);
		getTime(entry,info[1]);
		getServiceName(entry,info[2]);
		getGravedad(entry,&gravedad);
		getMensaje(entry,info[3]);
		fprintf(log,"%s;%s;%s;%s;%d",info[0],info[1],info[2],info[3],gravedad);
	      }
	  fclose(log);
	  if(i==tam)
	    {
	      ok=1;
	    }
	}
    }
  return ok;
}
int c_informes(LinkedList* this,LinkedList* warnings,LinkedList* errors)
{
  int i;
  int k;
  int j;
  int z;
  int ok;
  int tam;
  LogEntry* logGravedad[3];
  if(this!=NULL)
    {
      tam = ll_len(this);
      printf("\n\n");
      header();
	for(i=0;i<tam;i++)
	{
	  logGravedad[0] = (LogEntry*)ll_get(this,i);

	  if(logGravedad[0]->gravedad < 3)
	    {

	      listarEntrada(logGravedad[0]);
	      ok = 0;
	    }
	}
    }
  if(this!=NULL)
    {
      tam = ll_len(this);
      printf("\n\n");
      header();
      for(k=0;k<tam;k++)
      {
	logGravedad[0] = (LogEntry*)ll_get(this,k);

	if(logGravedad[0]->gravedad == 3)
	  {
	    listarEntrada(logGravedad[0]);
	    ok = 0;
	  }
      }
    }
  if(warnings!=NULL)
      {
        tam = ll_len(warnings);
        printf("\n\n");
        header();
  	for(j=0;j<tam;j++)
  	{
  	  logGravedad[1] = (LogEntry*)ll_get(warnings,j);

  	  if(logGravedad[1]->gravedad >= 4 && logGravedad[1]->gravedad <=7)
  	    {
  	      listarEntrada(logGravedad[1]);
  	      ok = 0;
  	    }
  	}
      }
  if(errors!=NULL)
       {
         tam = ll_len(errors);
         printf("\n\n");
         header();
   	for(z=0;z<tam;z++)
   	{
   	  logGravedad[2] = (LogEntry*)ll_get(errors,z);

   	  if(logGravedad[2]->gravedad >= 8)
   	    {
   	      listarEntrada(logGravedad[2]);
   	      ok = 0;
   	    }
   	}
       }

  return ok;
}

