#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

# include <stdio.h>

template<class Type>
class MergeSort {

private:

  bool ( *mCompare ) ( Type data1, Type data2 ) ;

  void RecursiveMergeSort( Type* dataPtr, int beginIndex, int endIndex ) ;
  void Merge( Type* dataPtr, int beginIndex, int midIndex, int endIndex ) ;

public:

  MergeSort( bool ( *compare ) ( Type data1, Type data2 ) ) ; // constructor
  ~MergeSort() ; // destructor

  void Sort( Type* dataPtr, int size ) ;

} ; // class MergeSort

template<class Type>
MergeSort<Type>::MergeSort( bool ( *compare ) ( Type data1, Type data2 ) ) { // constructor

  mCompare = compare ;

} // MergeSort<Type>::MergeSort()

template<class Type>
MergeSort<Type>::~MergeSort() { // destructor

  mCompare = NULL ;

} // MergeSort<Type>::~MergeSort()

template<class Type>
void MergeSort<Type>::Sort( Type* dataPtr, int size ) {

  if ( dataPtr == NULL ) {
    return ;
  } // if

  RecursiveMergeSort( dataPtr, 0, size - 1 ) ;

} // MergeSort<Type>::Sort()

template<class Type>
void MergeSort<Type>::RecursiveMergeSort( Type* dataPtr, int beginIndex, int endIndex ) {

  if ( beginIndex < endIndex ) {

    int midIndex = ( beginIndex + endIndex ) / 2 ;

    RecursiveMergeSort( dataPtr, beginIndex, midIndex ) ;
    RecursiveMergeSort( dataPtr, midIndex + 1, endIndex ) ;

    Merge( dataPtr, beginIndex, midIndex, endIndex ) ;

  } // if

} // MergeSort<Type>::RecursiveMergeSort()

template<class Type>
void MergeSort<Type>::Merge( Type* dataPtr, int beginIndex, int midIndex, int endIndex ) {

  Type* tempPtr = new Type[endIndex - beginIndex + 1] ;
  int tempPtrIndex = 0, leftIndex = beginIndex, rightIndex = midIndex + 1 ;

  while ( leftIndex <= midIndex && rightIndex <= endIndex ) {
    tempPtr[tempPtrIndex++] = ( mCompare( dataPtr[leftIndex], dataPtr[rightIndex] ) ?
                                dataPtr[leftIndex++] : dataPtr[rightIndex++] ) ;
  } // while

  while ( leftIndex <= midIndex ) {
    tempPtr[tempPtrIndex++] = dataPtr[leftIndex++] ;
  } // while

  while ( rightIndex <= endIndex ) {
    tempPtr[tempPtrIndex++] = dataPtr[rightIndex++] ;
  } // while

  for ( int i = beginIndex, j = 0 ; i <= endIndex ; i++, j++ ) {
    dataPtr[i] = tempPtr[j] ;
  } // for

  delete[] tempPtr ;
  tempPtr = NULL ;

} // MergeSort<Type>::Merge()

#endif // MERGE_SORT_H_INCLUDED

