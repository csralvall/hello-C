/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    
    bool res = true;

    if ( x->rank > y->rank )
	    res = false;

    return res;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], unsigned int i, unsigned int j) {
	
   player_t tmp = a[i];

   a[i] = a[j];
   a[j] = tmp;

}

unsigned int partition_atp(player_t a[], unsigned int lft, unsigned int rgt) {

   unsigned int i = lft + 1;
   unsigned int j = rgt;
   unsigned int temp_ppiv = (rand()%(rgt-lft+1))+lft;

   swap(a, temp_ppiv, lft);

   unsigned int ppiv = lft;

   while ( i < j ) {
	   if ( goes_before(a[i],a[ppiv]))
		++i;
	   else if ( goes_before(a[ppiv],a[j]))
		   --j;
	   else {
		   swap(a,i,j);
	   	   ++i;
		   --j;
	   }
   }
   swap(a,ppiv,j);
   ppiv = j;
   return ppiv;
}

void quick_sort_rec_atp(player_t a[], unsigned int lft, unsigned int rgt) {
   
   unsigned int ppiv;

   if ( rgt > lft ) {
	ppiv = partition_atp(a,lft,rgt);
	if (ppiv != 0u)
		quick_sort_rec_atp(a,lft,ppiv-1);
	quick_sort_rec_atp(a,ppiv+1,rgt);
   }
}

void sort(player_t a[], unsigned int length) {

   player_t *p[] = &a;

   srand(time(NULL));

   if (length != 0u)
	   quick_sort_rec_atp(p,0,length-1);
}

