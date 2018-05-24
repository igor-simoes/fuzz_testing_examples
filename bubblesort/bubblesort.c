#include <stdio.h>
#include <stdlib.h>

void bubblesort(int item[], int size)

{

  int a, b, t;

  for(a = 1; a < size; ++a)

  {

    for(b = size-1; b >= a; --b)

    {

      /* compare adjacent elements */

      if (b-1 < size && b < size)

      {

        if(item[ b - 1] > item[ b ])

        {

          /* exchange elements */

          t = item[ b - 1];

          item[ b - 1] = item[ b ];

          item[ b ] = t;

        }

      }

    }

  }

}
