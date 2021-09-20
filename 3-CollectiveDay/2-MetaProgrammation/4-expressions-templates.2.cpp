#include <iostream>

// Nodes

template <typename Itr1, typename Itr2>
struct NodeAdd
 {
  Itr1 itr1 ; Itr2 itr2 ;
  void operator ++() { ++itr1 ; ++itr2 ; }
  double operator *() const { return (*itr1)+(*itr2) ; }
 } ;

template <typename Itr1, typename Itr2>
struct NodeSub
 {
  Itr1 itr1 ; Itr2 itr2 ;
  void operator ++() { ++itr1 ; ++itr2 ; }
  double operator *() const { return (*itr1)-(*itr2) ; }
 } ;

// Vector

struct Vector
 {
  double data[3] ;
  // assignment
  //...   
 } ;

std::ostream & operator<<( std::ostream & os, const Vector & v )
 { return (os<<v.data[0]<<"|"<<v.data[1]<<"|"<<v.data[2]) ; }

template <class Node1, class Node2>
auto operator +(const Node1 & n1, const Node2 & n2)
 { return NodeAdd<Node1,Node2>{n1,n2} ; }

template <class Node>
auto operator +(const Vector & v, const Node & n)
 { return NodeAdd<const double *,Node>{v.data,n} ; }

template <class Node>
auto operator +(const Node & n, const Vector & v)
 { return NodeAdd<Node,const double *>{n,v.data} ; } 

auto operator +(const Vector & v1, const Vector & v2)
 { return NodeAdd<const double *,const double *>{v1.data,v2.data} ; }
 
template <class Node1, class Node2>
auto operator -(const Node1 & n1, const Node2 & n2)
 { return NodeSub<Node1,Node2>{n1,n2} ; }

template <class Node>
auto operator -(const Vector & v, const Node & n)
 { return NodeSub<const double *,Node>{v.data,n} ; }

template <class Node>
auto operator -(const Node & n, const Vector & v)
 { return NodeSub<Node,const double *>{n,v.data} ; } 

auto operator -(const Vector & v1, const Vector & v2)
 { return NodeSub<const double *,const double *>{v1.data,v2.data} ; }
 
// Main

int main()
 {
  Vector v1{1,2,3}, v2{0.1,0.2,0.3}, v3{0.01,0.02,0.03}, v4{0,0,0} ;
  v4 = v1+(v2-v3) ;
  std::cout<<v4<<std::endl ;
  return 0 ;
 }