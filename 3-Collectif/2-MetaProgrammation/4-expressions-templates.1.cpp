#include <iostream>

// Addition
template <typename Itr1, typename Itr2>
struct NodeAdd
 {
  Itr1 itr1 ; Itr2 itr2 ;
  void operator ++() { ++itr1 ; ++itr2 ; }
  double operator *() const { return (*itr1)+(*itr2) ; }
 } ;

// Soustraction
template <typename Itr1, typename Itr2>
struct NodeSub
 {
  Itr1 itr1 ; Itr2 itr2 ;
  void operator ++() { ++itr1 ; ++itr2 ; }
  double operator *() const { return (*itr1)-(*itr2) ; }
 } ;
 
int main()
 {
  int array1[5] = { 1, 2, 3, 4, 5 } ;
  double array2[5] = { .1, .2, .3, .4, .5 } ;

  NodeAdd<int *,double *> add {array1,array2} ;
  for ( int i = 0 ; i<5 ; ++i )
   { std::cout<<(*add)<<std::endl ; ++add ; }
 }