#include <boost/vmd/vmd.hpp>
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if !BOOST_PP_VARIADICS
  
#    if defined __GCCXML__
BOOST_ERROR("No variadic macro support: __GCCXML__ defined.");
#    elif defined __CUDACC__
BOOST_ERROR("No variadic macro support: __CUDACC__ defined.");
#    elif defined __PATHSCALE__
BOOST_ERROR("No variadic macro support: __PATHSCALE__ defined.");
#    elif defined __DMC__
BOOST_ERROR("No variadic macro support: __DMC__ defined.");
#    elif defined __CODEGEARC__
BOOST_ERROR("No variadic macro support: __CODEGEARC__ defined.");
#    elif defined __BORLANDC__
BOOST_ERROR("No variadic macro support: __BORLANDC__ defined.");
#    elif defined __MWERKS__
BOOST_ERROR("No variadic macro support: __MWERKS__ defined.");
#    elif defined __SUNPRO_CC
BOOST_ERROR("No variadic macro support: __SUNPRO_CC defined.");
#    elif defined __HP_aCC && !defined __EDG__
BOOST_ERROR("No variadic macro support: __HP_aCC defined and __EDG__ not defined.");
#    elif defined __MRC__
BOOST_ERROR("No variadic macro support: __MRC__ defined.");
#    elif defined __SC__
BOOST_ERROR("No variadic macro support: __SC__ defined.");
#    elif defined __IBMCPP__
BOOST_ERROR("No variadic macro support: __IBMCPP__ defined.");
#    elif defined __PGI
BOOST_ERROR("No variadic macro support: __PGI defined.");
#    /* VC++ (C/C++) */
#    elif defined _MSC_VER && _MSC_VER >= 1400 && (!defined __EDG__ || defined(__INTELLISENSE__)) && !defined __clang__
#    /* Wave (C/C++), GCC (C++) */
#    elif defined __WAVE__ && __WAVE_HAS_VARIADICS__ || defined __GNUC__ && __GXX_EXPERIMENTAL_CXX0X__
#    /* EDG-based (C/C++), GCC (C), and unknown (C/C++) */
#    elif !defined __cplusplus && __STDC_VERSION__ < 199901L
BOOST_ERROR("No variadic macro support: C compile and __STDC_VERSION__ is less than 199901L.");
#    elif __cplusplus < 201103L
BOOST_ERROR("No variadic macro support: C++ compile and __cplusplus is less than 201103L.");
#    endif

#endif

  return boost::report_errors();
  
  }
