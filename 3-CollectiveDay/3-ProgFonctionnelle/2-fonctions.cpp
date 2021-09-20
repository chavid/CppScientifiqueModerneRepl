#include <iostream>
#include <array>

template< typename Fonction1, typename Fonction2 >
... compose( Fonction1 f1, Fonction2 f2 )
 { return ... ; }

int carre( int i ) { return i*i ; }
int inc( int i ) { return i+1 ; }

int main()
 {     
  std::array<int,5> tableau = { 1, 2, 3, 4, 5 } ;
  auto f = compose(inc,carre) ;
  for ( auto element : tableau )
    std::cout<<f(element)<<std::endl ;
 }