/**
 * @file stdlib.h
 *
 * $Id: stdlib.h 2051 2009-08-27 20:55:09Z akoehler $
 */
/* Embedded Xinu, Copyright (C) 2009.  All rights reserved. */

#define RAND_MAX 2147483646

int atoi(char *);
void bzero(void *, int);
void *malloc(unsigned int nbytes);
void free(void *pmem);
