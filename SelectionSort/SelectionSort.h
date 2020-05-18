#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class SelectionSort {

private:

  bool ( *mCompare ) ( Type data1, Type data2 ) ;

public:

  SelectionSort( bool ( *compare ) ( Type data1, Type data2 ) ) ; // constructor
  ~SelectionSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class SelectionSort

template<class Type>
SelectionSort<Type>::SelectionSort( bool ( *compare ) ( Type data1, Type data2 ) ) { // constructor

  mCompare = compare ;

} // SelectionSort<Type>::SelectionSort()

template<class Type>
SelectionSort<Type>::~SelectionSort() { // destructor

  mCompare = NULL ;

} // SelectionSort<Type>::~SelectionSort()

template<class Type>
void SelectionSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  for ( int i = 0 ; i < size ; i++ ) {

    int index = i ;

    for ( int j = i + 1 ; j < size ; j++ ) {
      if ( mCompare( dataPtr[index], dataPtr[j] ) ) {
        index = j ;
      } // if
    } // for

    Type temp = dataPtr[i] ;
    dataPtr[i] = dataPtr[index] ;
    dataPtr[index] = temp ;

  } // for

} // SelectionSort<Type>::Sort()

#endif // SELECTION_SORT_H_INCLUDED

