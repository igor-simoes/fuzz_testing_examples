#include <stdio.h>
#include <stdlib.h>

#include "bubblesort.h"

extern "C" int LLVMFuzzerTestOneInput(const u_int8_t* Data, size_t size) {
   if (size < 3) return 0;

   int item[size];
   for (int i=0; i<size; i++)
   {
       item[i] = Data[i];
   }

   bubblesort(item, 3);

   return 0;
}
