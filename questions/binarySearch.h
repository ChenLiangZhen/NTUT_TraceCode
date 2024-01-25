//
// Created by Lightii Chen on 2023/12/14.
//

#include <cmath>

#ifndef TRACECODE_BINARYSEARCH_H
#define TRACECODE_BINARYSEARCH_H

int bsearch(vector<int> data, int key, int left, int right){

   int mid = floor((left + right) / 2);

   if(left  >= right) {
      return -1;
   }

   if(data[mid] == key) {
      return mid;

   } else if(data[mid] > key) {
      return bsearch(data, key, left, mid - 1);

   }  else {
      return bsearch(data, key, mid + 1, right);
   }
}

#endif //TRACECODE_BINARYSEARCH_H
