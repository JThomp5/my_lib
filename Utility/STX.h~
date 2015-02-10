#ifndef ICE_STX
#define ICE_STX

#include <map>
#include <cmath>
#include <set>

using namespace std;

template < typename T, typename R >
bool Insert( map < T, set < R > >& M, const T& k, const R& v){
  typename map < T, set < R > >::iterator it_m;

  if ( (it_m = M.find(k)) != M.end() ){
    pair < typename set < R >::iterator, bool > res = it_m->second.insert(v);
    return res.second;
  } else {
    set < R > newEntry;
    newEntry.insert(v);
    M.insert(pair < T, set < R > > (k, newEntry));    
    return true;
  }
  
  return false;
}

template < typename T, typename R >
bool Insert( map < T, vector < R > >& M, const T& k, const R& v){
  typename map < T, vector < R > >::iterator it_m;
  
  if ( ( it_m = M.find( k ) ) != M.end() ){
    it_m->second.push_back(v);
    return true;
  } else {
    vector < R > seed;
    seed.push_back(v);
    M.insert(pair < T, vector < R > > (k, seed));
    return true;
  }

  return true;
}

template < typename T, typename R, typename S >
bool Insert( map < T, map < R, S > >& M, const T& key1, const R& key2, const S& val, bool overwrite = false ){
  typename map < T, map < R, S > >::iterator it_m;
  typename map < R, S >::iterator it_e;
  
  if ( (it_m = M.find(key1)) != M.end() ){
    if ( (it_e = it_m->second.find(key2)) != it_m->second.end() ){
      if (overwrite){
	it_e->second = val;
	return true;
      } else {
	return false;
      }
    } else {
      it_m->second.insert(pair < R, S > (key2, val) );
      return true;
    }
  } else {
    map < R, S > newEntry;
    newEntry.insert(pair < R, S > (key2, val) );
    M.insert(pair < T, map < R, S > >(key1, newEntry));
    return true;
  }

  return false;
}

template < typename T >
int IntersectionSize(const set < T >& A, const set < T >& B){
  typename set < T >::const_iterator it_a, it_b;
  int result = 0;

  for (it_a = A.begin(); it_a != A.end(); it_a++){
    if ( B.find(*it_a) != B.end() ){
      result++;
    } 
  }

  return result;
}

template < typename T >
int UnionSize ( const set < T >& A, const set < T >& B ) {
  typename set < T >::const_iterator it_a;
  int result = B.size();

  for (it_a = A.begin(); it_a != A.end(); it_a++){
    if (B.find(*it_a) == B.end())
      ++result;
  }

  return result;  
}

/**Gross kuldge for vectors too*/
template < typename T >
int IntersectionSize( const vector < T >& A, const vector < T >& B ){
  set < T > a_copy( A.begin(), A.end() ), b_copy ( B.begin(), B.end() );
  return IntersectionSize(a_copy, b_copy);
}

template < typename T >
double Jaccard( const set < T >& A, const set < T >& B){
  return (double)(IntersectionSize<T>(A, B)) / (double)(UnionSize<T>(A, B));
}

template < typename T >
double Jaccard( const vector < T >& A, const vector < T >& B){
  set < T > a_copy( A.begin(), A.end() ), b_copy ( B.begin(), B.end() );
  return Jaccard( a_copy, b_copy );
}

double CosSim ( const vector < double >& A, const vector < double >& B );
double CosSim ( const vector < double >& A, const int a_begin, const int a_end, const vector < double >& B, const int b_begin, const int b_end );
double Pearson ( const vector < double >& A, const int a_begin, const int a_end, const vector < double >& B, const int b_begin, const int b_end );

#endif
