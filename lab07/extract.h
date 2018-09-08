// Functions and types used by extract.c,
// Originally by Richard Buckland, 13 April 2014.
//
// Do not alter or submit this file,
// we'll use our own copy when marking it.

#ifndef _EXTRACT_H_
#define _EXTRACT_H_

typedef struct _triordinate {
   double x;
   double y;
   int z;
} triordinate;


triordinate extract (char *message);

double myAtoD (char *message);


long myAtoL (char *message);

#endif // !defined(_EXTRACT_H_)

