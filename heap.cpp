// heap.cpp
// Diba Mirza
//Daisy and Emily 

#include "heap.h"
#include <iostream>
using std::cout;
using std::swap;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){

 vdata = std::vector<int>(start,end);

 int size = vdata.size();

 for(int i = size/2-1;i >= 0; i--){
   heapify(i);

 }

}

void Heap::heapify(int parent){
  int size = vdata.size();

   while(true){

     int left = 2 * parent + 1;
     int right = 2 * parent + 2;
     int minimum = parent;

     if(left < size && vdata[left] < vdata[minimum]){
      minimum = left;
     }
     if(right < size && vdata[right] < vdata[minimum] ){
       minimum = right;
     }

     if(minimum != parent){
       std::swap(vdata[parent], vdata[minimum]);
       parent = minimum;
     }
     else{
      break;
     }


   }

 }



// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){


 vdata.push_back(value);


 int curr = vdata.size() - 1;


 while(curr > 0){
   int parenti = (curr - 1)/2;


   if(vdata[curr] < vdata[parenti]){
     std::swap(vdata[curr], vdata[parenti]);
     curr = parenti;
   }
   else{
     break;
   }
 }


}


// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.empty()){
    return;
  }

  std::swap(vdata[0], vdata.back());
  vdata.pop_back();

  heapify(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.empty()){
    return true;
  }

  return false;
}
    