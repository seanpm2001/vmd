#if !defined(BOOST_VMD_CHECK_IF_VALUE_HPP)
#define BOOST_VMD_CHECK_IF_VALUE_HPP

#include <boost/vmd/detail/vmd_detail_setup.hpp>

#if BOOST_PP_VARIADICS

#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/vmd/vmd_is_empty.hpp>
#include <boost/vmd/detail/vmd_detail_check_if_value.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def BOOST_VMD_CHECK_IF_VALUE(parameter,key)

    \brief Tests whether a parameter is the same as some value

    The macro checks to see if the 'parameter' is equal to some value,
    meaning that it is the exact same preprocessing token.
    The value which is checked is mapped by the key ( see below ),
    which must be unique each time this macro is invoked.
    
    It returns 1 if they are the same, else returns 0.
    The parameter must be a C++ identifier,
    ie. it must consist of letters, numbers, and underscores.
    
    parameter = a C++ identifier to test
    key    = a C++ identifier as a unique key whenever the macro is invoked.
             The idea is not to duplicate the key that another library may use.
             
             The unique key should not begin with an underscore. It may end
             with an underscore only if the value to be tested does not begin
             with an underscore. It may contain underscores.
             
             Two different suggested ways to generate a unique key are:
             1) Use a specific mnemonic for a particular module and add an increasing
                numeric value to it each time you use it, ie. TTI0, TTI1, TTI2 etc.
             2) use a GUID ( 128 bit unique number ) generated by the OS or software.

    returns = expands to 1 if the parameter is equal to a particular value, otherwise expands to 0
    
    The 'value' to be tested against is specified by having the end-user 
    defining an object-like macro, which does not expand to anything, whose form is:
    
    #define BOOST_VMD_MAP_'key''value'
    
    where 'key' is the key passed to the BOOST_VMD_CHECK_IF_VALUE macro,
          'value' is the value to be tested against.
    
    As an example, let us suppose that within a library called 'plane_geometry' I want to
    use the BOOST_VMD_CHECK_IF_VALUE macro 3 times, checking whether a parameter is equal 
    to 'SQUARE' the first time, 'TRIANGLE' the second time and 'CIRCLE' the third time.
    
    First I write my object-like macros
    
    #define BOOST_VMD_MAP_PLANEGEOMETRY1_SQUARE
    #define BOOST_VMD_MAP_PLANEGEOMETRY2_TRIANGLE
    #define BOOST_VMD_MAP_PLANEGEOMETRY3_CIRCLE
    
    If I want to check if some preprocessor argument 'x' is SQUARE I invoke:
    
    BOOST_VMD_CHECK_IF_VALUE(x,PLANEGEOMETRY1_)
    
    If I want to check if some preprocessor argument 'x' is TRIANGLE I invoke:
    
    BOOST_VMD_CHECK_IF_VALUE(x,PLANEGEOMETRY2_)
    
    If I want to check if some preprocessor argument 'x' is CIRCLE I invoke:
    
    BOOST_VMD_CHECK_IF_VALUE(x,PLANEGEOMETRY3_)
    
*/

#define BOOST_VMD_CHECK_IF_VALUE(param,key) \
    BOOST_PP_EXPAND(BOOST_VMD_IS_EMPTY BOOST_VMD_DETAIL_CHECK_IF_VALUE_CAT(param,key)) \
/**/

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_CHECK_IF_VALUE_HPP */