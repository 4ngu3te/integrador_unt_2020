/*
 ============================================================================
 Name        : integrador.c
 Author      : Franco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LogEntry.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"

int main(void) {

  setbuf(stdout,NULL);

  LinkedList* logEntry = ll_newLinkedList();
  LinkedList* logEntry_warning = ll_newLinkedList();
  LinkedList* logEntry_error = ll_newLinkedList();

  int op;
  int in=0;

  do
    {
      op=menu();
      switch(op)
      {
	case 1:
	  if(in==0)
	    {
	      if(c_loadFromLog("log.txt",logEntry)==0)
		{
		  in = 1;
		}
	    }
	  else
	    {
	      text("\nLa lista ya ha sido cargada...\n");
	    }
	  break;
	case 2:
	  if(ll_isEmpty(logEntry)!=1)
	    {
	      logEntry_warning = ll_filter(logEntry,calcGravedad_warnings);
	      logEntry_error = ll_filter(logEntry,calcGravedad_errors);
	      c_listLog(logEntry_warning);
	      text("\n\n");
	      c_listLog(logEntry_error);
	     if(logEntry_warning != NULL && c_saveAs("warnings.txt",logEntry_warning)==1 && c_saveAs("errors.txt",logEntry_error)==1)
		{
		 in=2;
		 text("\n\nLogs guardados correctamente...\n\n");
		}
	      else
		{
		  text("\nError al escribir.\n");
		}
	    }
	  break;
	case 3:
	  if(ll_isEmpty(logEntry)!=1 && in == 2)
	    {
	      c_informes(logEntry,logEntry_warning,logEntry_error);
	    }
	  else
	    {
	      text("\nTodavia no se han procesado los datos.\n");
	    }
	  break;
	case 4:
	  if(ll_isEmpty(logEntry)!=1)
	    {
	      c_listLog(logEntry);
	    }
	  break;
	  system("pause");
	  system("cls");
      }
    }while(op!=5);

  return EXIT_SUCCESS;
}
