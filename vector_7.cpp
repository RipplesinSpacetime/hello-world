#include   <stdlib.h>   
#include   <windows.h>   
#include   <conio.h>   
#include   <map>   //STL
#include   <functional> //STL  
#include   <algorithm>   //STL
#include   <iostream>   
using namespace std;   
typedef  map<int,int*> m_iip;   
typedef  map<int,char*> m_icp;   
class  f_c{   
  int _i;   
  public:   
  f_c(int i):_i(i){
          
  }   
  void operator()(m_iip::value_type ite)   
  {   
  cout<<_i++<<"\t"<<ite.first<<" shi"<<endl;   
  }   
  void operator()(m_icp::value_type ite)  
  {   
  cout<<_i++<<"\t"<<ite.first<<" yang"<<endl;  
  }   
  };   
  void f(int i,int c)   
  {   
      
  }   
  int main(int argc,char* argv[]){
  m_iip  iip;   
  m_icp  icp;   
  int i=0;   
  iip.insert(make_pair(34,&i));   
  iip.insert(make_pair(67,&i));   
  iip.insert(make_pair(5,&i));   
  iip.insert(make_pair(342,&i));    
  char d=0;   
  icp.insert(make_pair(12,&d));   
  icp.insert(make_pair(54,&d));   
  icp.insert(make_pair(6,&d));   
  icp.insert(make_pair(92,&d));   
  for_each(iip.begin(),iip.end(),f_c(8));   
  for_each(icp.begin(),icp.end(),f_c(65));//   
  return 0;   
  }
