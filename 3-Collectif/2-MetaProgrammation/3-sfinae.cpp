#include <iostream>

int times_power_of_two( int number, int exponent )
 {
  if (exponent<0) { return (number>>-exponent) ; }
  else { return (number<<exponent) ; }
 }

int main()
{
  std::cout<<times_power_of_two(42,1)<<std::endl ;
  std::cout<<times_power_of_two(42,-1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,1)<<std::endl ;
  std::cout<<times_power_of_two(3.14,-1)<<std::endl ;
  return 0 ;
}