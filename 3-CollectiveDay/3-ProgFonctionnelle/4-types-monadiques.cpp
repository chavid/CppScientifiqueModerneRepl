#include <cmath>
#include <iostream>
#include <optional>

double mysqrt( double d )
 { return std::sqrt(d) ; }

double square( double d )
 { return d*d ; }

template< typename A >
std::ostream & operator<<( std::ostream & os, std::optional<A> const & opt )
 {
  if (opt) { return os<<opt.value() ; }
  else { return os<<"nothing" ; }
 }

int main()
 {
  std::cout<<square(mysqrt(10))<<std::endl ;
  std::cout<<square(mysqrt(-10))<<std::endl ;
 }