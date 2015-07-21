#include <iostream>
#include <type_traits>

using namespace std;

int main(int argc, char **argv)
{
  int i, &j = i;
  // decltypes give an const int&
  [=]
  {
    cout << "int i, &j = i; (lambda, not mutable)"
         << "\nis_same<decltype    ((j)),     int         >::value   = " << is_same<decltype    ((j)),     int         >::value
         << "\nis_same<decltype   (((j))),    int      &  >::value   = " << is_same<decltype   (((j))),    int      &  >::value
         << "\nis_same<decltype  ((((j)))),   int const&  >::value   = " << is_same<decltype  ((((j)))),   int const&  >::value
         << "\nis_same<decltype (((((j))))),  int      && >::value   = " << is_same<decltype (((((j))))),  int      && >::value
         << "\nis_same<decltype((((((j)))))), int const&& >::value   = " << is_same<decltype((((((j)))))), int const&& >::value
         << std::endl;
  }();

  // decltypes give an int&
  [=]
  ()
  mutable
  {
    cout << "int i, &j = i; (mutable in lambda)"
         << "\nis_same<decltype    ((j)),     int         >::value   = " << is_same<decltype    ((j)),     int         >::value
         << "\nis_same<decltype   (((j))),    int      &  >::value   = " << is_same<decltype   (((j))),    int      &  >::value
         << "\nis_same<decltype  ((((j)))),   int const&  >::value   = " << is_same<decltype  ((((j)))),   int const&  >::value
         << "\nis_same<decltype (((((j))))),  int      && >::value   = " << is_same<decltype (((((j))))),  int      && >::value
         << "\nis_same<decltype((((((j)))))), int const&& >::value   = " << is_same<decltype((((((j)))))), int const&& >::value
         << std::endl;
  }();

  // outside lambda
  cout << "int i, &j = i; no lambda\n"
       << "\nis_same<decltype    ((j)),     int         >::value   = " << is_same<decltype    ((j)),     int         >::value
       << "\nis_same<decltype   (((j))),    int      &  >::value   = " << is_same<decltype   (((j))),    int      &  >::value
       << "\nis_same<decltype  ((((j)))),   int const&  >::value   = " << is_same<decltype  ((((j)))),   int const&  >::value
       << "\nis_same<decltype (((((j))))),  int      && >::value   = " << is_same<decltype (((((j))))),  int      && >::value
       << "\nis_same<decltype((((((j)))))), int const&& >::value   = " << is_same<decltype((((((j)))))), int const&& >::value
       << std::endl;
}
