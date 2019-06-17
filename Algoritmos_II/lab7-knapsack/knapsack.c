#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "helpers.h"
#include "item.h"
#include "knapsack.h"

static value_t max(unsigned int elem1, unsigned int elem2) {

   value_t res = 0;

   if(elem1 > elem2)
     res = elem1;
   else
     res = elem2;

   return res;
}

value_t knapsack_backtracking(item_t *items, unsigned int array_length, weight_t max_weight) {

   value_t res = 0;
   weight_t weight = 0;
   value_t value = 0;

   if (array_length > 0) {
     weight = item_weight(items[array_length-1]);
     value = item_value(items[array_length-1]);
   }

   if (max_weight == 0)  
     res = 0;
   else if (max_weight > 0 && array_length == 0)
     res = 0;
   else if (weight > max_weight && max_weight > 0 && array_length > 0)
     res = knapsack_backtracking(items, array_length-1,max_weight);
   else if (max_weight > weight && weight > 0 && array_length > 0)
     res = max(knapsack_backtracking(items, array_length-1,max_weight), value + knapsack_backtracking(items,array_length-1,max_weight-weight));

   return res;
}

value_t knapsack_dynamic(item_t *items, unsigned array_length, weight_t max_weight) {

   value_t knapsack[array_length+1][max_weight+1];
   value_t res = 0;

   for (unsigned int i = 0; i <= array_length; ++i) {
     knapsack[i][0] = 0;
   }

   for (weight_t j = 0; j <= max_weight; ++j) {
     knapsack[0][j] = 0;
   }

   for (unsigned int i = 1; i <= array_length; ++i) {
     for (weight_t j = 1; j <= max_weight; ++j) {
       if (item_weight(items[i-1]) > j) {
         knapsack[i][j]=knapsack[i-1][j];
       } else {
         knapsack[i][j]=max(knapsack[i-1][j],item_value(items[i-1])+knapsack[i-1][j-item_weight(items[i-1])]);
       }
     }
   }

   res = knapsack[array_length][max_weight];

   return res;

}


value_t knapsack_dynamic_selection(item_t *items, bool *selected, unsigned array_length, weight_t max_weight) {

   value_t knapsack[array_length+1][max_weight+1];
   value_t res = 0;
   unsigned int r = array_length;
   weight_t s = max_weight;

   
   for (unsigned int i = 0; i <= array_length; ++i) {
     knapsack[i][0] = 0;
   }

   for (weight_t j = 0; j <= max_weight; ++j) {
     knapsack[0][j] = 0;
   }

   for (unsigned int i = 1; i <= array_length; ++i) {
     for (weight_t j = 1; j <= max_weight; ++j) {
       if (item_weight(items[i-1]) > j) {
         knapsack[i][j]=knapsack[i-1][j];
       } else {
         knapsack[i][j]=max(knapsack[i-1][j],item_value(items[i-1])+knapsack[i-1][j-item_weight(items[i-1])]);
       }
     }
   }

   res = knapsack[array_length][max_weight];

   while (knapsack[r][s] > 0) {
     if (knapsack[r][s] == knapsack[r-1][s]) {
       selected[r] = false;
     } else {
       selected[r] = true;
       s = s-item_weight(items[r]);
     }
     r = r - 1;
  }

   return res;
}

