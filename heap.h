#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream> 

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  
  //I need vector to store heap elements
  std::vector<T> storeElements; 
  //comp object 
  PComparator c; 
  //track children per node (degree of my heap) 
  int trackChild; 


//helper functions
  void up(int idx); // inserting new element into heap, move up the heap
  void down(int idx); // when removing, move down
   


};

// Add implementation of member functions here
//constructor implementation 
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator comp) : trackChild(m), c(comp) {
  // if (m < 2){
  //   m=2; 
  // 
}


//destructor 
template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap(){} //isnt there no memory to free

template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item){
  storeElements.push_back(item); //new element at last position
  if (storeElements.size() == 1){
    return; 
  }
  up(storeElements.size()-1); 
}

//top and pop below//come bacl

template <typename T, typename Comparator>
bool Heap<T, Comparator>::empty() const{
  if (storeElements.size() == 0){
    return true;
  }
  return false; 
}

template <typename T, typename Comparator>
size_t Heap<T, Comparator>::size() const{
  return storeElements.size(); 
}

//my own implementations of my 2 helper functions 
template <typename T, typename Comparator>
void Heap<T, Comparator>::up(int idx){
  //use when uyou push to maintain heap property 
  //takes in element that you want to move up
  //move it to the correct position 
  //check parent first 

  if (idx == 0){
    return; 
  }
  while(idx != 0){
    int parent = (idx -1) / trackChild; 
    T &current = storeElements[idx]; 
    T &p = storeElements[parent]; 
    if (c(current,p)){
      std::swap(current,p); 
      idx = parent; 
    }
    else{
      break; 
    }
  }

  // if (c(storeElements[idx], storeElements[parent])){
  //   //comparator based on what we are looking to do 
  //   //perform swap 
  //   T temp = storeElements[idx]; 
  //   storeElements[idx] = storeElements[parent]; 
  //   storeElements[parent] = temp; 

  //   //recursive call to do it again 
  //   up(parent); 
  //   //is parent gonna move or no
  }
  //compare child and parent for the place 


//move down 
template <typename T, typename Comparator>
void Heap<T, Comparator>::down(int idx){
  //maintain heap property when you pop 
  int parent = idx; 
  int leftChild = 0;
  while(leftChild < storeElements.size()){
    //std::cout << "left child" << leftChild << std::endl; 
    leftChild = trackChild * parent + 1; 
    int bestChild = leftChild; 
    if (leftChild >= storeElements.size()){
      break; 
    }
    for (int i = 1; i < trackChild; i++){
      int rightChild = leftChild + i; 
      if (rightChild >= storeElements.size()){
        break; 
      }
      if (c(storeElements[rightChild], storeElements[bestChild])){
        bestChild = rightChild; 
    } 
    }
    if (c(storeElements[bestChild], storeElements[parent])){
      std::swap(storeElements[bestChild], storeElements[parent]); 
      parent = bestChild; 
    }
    else {
      break; 
    }
  }
}
    // int rightChild = 2 * parent + 1; 
    // //storeElements[leftchild]

    // if (leftChild > storeElements.size()){ //or equal to (index confusing me)
    //   return; 
    // }
    // int move = leftChild; 
    // if (rightChild < storeElements.size() && c(storeElements[leftChild], storeElements[rightChild])){
    //   move = rightChild; //have to select betwee left and right which should switch with parent
    // }

    // T temp = storeElements[parent]; 
    // storeElements[parent] = storeElements[move]; 
    // storeElements[move] = temp; 

    // down(move); //go down the heap recursively 



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return storeElements[0]; 
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty."); 

  }
//pop back , heapfiy down 
  storeElements[0] = storeElements[storeElements.size() -1]; 
  storeElements.pop_back(); 
  down(0); 
  //is this working properly idk??

}

#endif

