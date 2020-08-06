#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LogEntry.h"
#include "parser.h"
#include "LinkedList.h"
#include "utn.h"

int parserFromLog(FILE* pFile, LinkedList* pArrayList)
{

  int ok = -1;
  int cant;
  char asd[5][64];

  LogEntry* entry = NULL;

    if(pFile!=NULL && pArrayList!=NULL)
      {
	while(!feof(pFile))
	  {
	    cant = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n", asd[0], asd[1], asd[2], asd[3],asd[4]);

	    entry = entryNewParam(asd[0], asd[1], asd[2], asd[3],asd[4]);
	    if(entry!=NULL)
	      {
		ll_add(pArrayList,entry);
		ok=0;
	      }
	    if(feof(pFile) && cant >= 5)
	      {
		break;
	      }
	  }
      }
    return ok;

}


