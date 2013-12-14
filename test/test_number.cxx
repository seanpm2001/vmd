#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/number.hpp>
#include <boost/vmd/is_begin_parens.hpp>
#include <boost/vmd/is_empty.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/list/at.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

	#define A_TUPLE (27,251,145 ())
	#define JDATA 43
	#define A_SEQ (73 (split) clear)(red)(green 44)
	#define A_LIST (17 (5),(grist,(yellow,BOOST_PP_NIL)))
	
	BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_NUMBER(BOOST_PP_TUPLE_ELEM(2,A_TUPLE))),145);
	BOOST_TEST(BOOST_VMD_IS_BEGIN_PARENS(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_NUMBER(BOOST_PP_TUPLE_ELEM(2,A_TUPLE)))));
	
	BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_NUMBER(JDATA)),43);
	BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_NUMBER(JDATA))));
	
	BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_NUMBER(BOOST_PP_SEQ_ELEM(0,A_SEQ))),73);
	BOOST_TEST(BOOST_VMD_IS_BEGIN_PARENS(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_NUMBER(BOOST_PP_SEQ_ELEM(0,A_SEQ)))));
	
	BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_NUMBER(BOOST_PP_LIST_AT(A_LIST,0))),17);
	BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(0,BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_NUMBER(BOOST_PP_LIST_AT(A_LIST,0)))),5);
	
	BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_NUMBER(BOOST_PP_LIST_AT(A_LIST,1)))));
	BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_NUMBER(BOOST_PP_LIST_AT(A_LIST,1)))));
	
	BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_NUMBER(BOOST_PP_SEQ_ELEM(2,A_SEQ)))));
	BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_NUMBER(BOOST_PP_SEQ_ELEM(2,A_SEQ)))));
  
#endif

  return boost::report_errors();
  
  }
