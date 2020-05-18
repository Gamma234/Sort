#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class QuickSort {

private:

  bool ( *mCompare ) ( Type data1, Type data2 ) ;

  void RecursiveQuickSort( Type* dataPtr, int beginIndex, int endIndex ) ;
  int Partition( Type* dataPtr, int beginIndex, int endIndex ) ;

public:

  QuickSort( bool ( *compare ) ( Type data1, Type data2 ) ) ; // constructor
  ~QuickSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class QuickSort

template<class Type>
QuickSort<Type>::QuickSort( bool ( *compare ) ( Type data1, Type data2 ) ) { // constructor

  mCompare = compare ;

} // QuickSort<Type>::QuickSort()

template<class Type>
QuickSort<Type>::~QuickSort() { // destructor

  mCompare = NULL ;

} // QuickSort<Type>::~QuickSort()

template<class Type>
void QuickSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  RecursiveQuickSort( dataPtr, 0, size - 1 ) ;

} // QuickSort<Type>::Sort()

template<class Type>
void QuickSort<Type>::RecursiveQuickSort( Type* dataPtr, int beginIndex, int endIndex ) {

  if ( beginIndex < endIndex ) {

    int pivotIndex = Partition( dataPtr, beginIndex, endIndex ) ;

    RecursiveQuickSort( dataPtr, beginIndex, pivotIndex - 1 ) ;
    RecursiveQuickSort( dataPtr, pivotIndex + 1, endIndex ) ;

  } // if

} // QuickSort<Type>::RecursiveQuickSort()

template<class Type>
int QuickSort<Type>::Partition( Type* dataPtr, int beginIndex, int endIndex ) {

  Type pivot = dataPtr[endIndex] ;
  int swapIndex = beginIndex - 1 ;

  for ( int i = beginIndex ; i < endIndex ; i++ ) {
    if ( mCompare( dataPtr[i], pivot ) ) {
      swapIndex++ ;
      Type temp = dataPtr[i] ;
      dataPtr[i] = dataPtr[swapIndex] ;
      dataPtr[swapIndex] = temp ;
    } // if
  } // for

  Type temp = dataPtr[swapIndex + 1] ;
  dataPtr[swapIndex + 1] = dataPtr[endIndex] ;
  dataPtr[endIndex] = temp ;

  return swapIndex + 1 ;

} // QuickSort<Type>::Partition()

#endif // QUICK_SORT_H_INCLUDED

