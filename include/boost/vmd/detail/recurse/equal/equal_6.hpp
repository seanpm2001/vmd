#if !defined(BOOST_VMD_DETAIL_EQUAL_6_HPP)
#define BOOST_VMD_DETAIL_EQUAL_6_HPP

#include <boost/vmd/detail/recurse/equal/equal_headers.hpp>

#define BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST_FND(vseq1,vseq2,vtype) \
	BOOST_VMD_DETAIL_LIST_EQUAL_6_NC(vseq1,vseq2) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST_FND_D(d,vseq1,vseq2,vtype) \
	BOOST_VMD_DETAIL_LIST_EQUAL_6_NC_D(d,vseq1,vseq2) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST(vseq1,vseq2,vtype) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_EQUAL_TYPE(vtype,BOOST_VMD_TYPE_LIST), \
		BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST_FND, \
		BOOST_VMD_DETAIL_DATA_EQUAL_6 \
		) \
	(vseq1,vseq2,vtype) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST_D(d,vseq1,vseq2,vtype) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_EQUAL_TYPE_D(d,vtype,BOOST_VMD_TYPE_LIST), \
		BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST_FND_D, \
		BOOST_VMD_DETAIL_DATA_EQUAL_6_D \
		) \
	(d,vseq1,vseq2,vtype) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_CNI(vseq1,vseq2,vtype) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_PP_BITOR \
				( \
				BOOST_VMD_DETAIL_EQUAL_TYPE(vtype,BOOST_VMD_TYPE_ARRAY), \
				BOOST_VMD_DETAIL_EQUAL_TYPE(vtype,BOOST_VMD_TYPE_LIST) \
				), \
			BOOST_PP_BITOR \
				( \
				BOOST_VMD_DETAIL_EQUAL_TYPE(vtype,BOOST_VMD_TYPE_SEQ), \
				BOOST_VMD_DETAIL_EQUAL_TYPE(vtype,BOOST_VMD_TYPE_TUPLE) \
				) \
			), \
		BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST, \
		BOOST_VMD_DETAIL_EQUAL_CNI_SMP \
		) \
	(vseq1,vseq2,vtype) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_CNI_D(d,vseq1,vseq2,vtype) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_PP_BITOR \
				( \
				BOOST_VMD_DETAIL_EQUAL_TYPE_D(d,vtype,BOOST_VMD_TYPE_ARRAY), \
				BOOST_VMD_DETAIL_EQUAL_TYPE_D(d,vtype,BOOST_VMD_TYPE_LIST) \
				), \
			BOOST_PP_BITOR \
				( \
				BOOST_VMD_DETAIL_EQUAL_TYPE_D(d,vtype,BOOST_VMD_TYPE_SEQ), \
				BOOST_VMD_DETAIL_EQUAL_TYPE_D(d,vtype,BOOST_VMD_TYPE_TUPLE) \
				) \
			), \
		BOOST_VMD_DETAIL_EQUAL_6_CNI_CLIST_D, \
		BOOST_VMD_DETAIL_EQUAL_CNI_SMP_D \
		) \
	(d,vseq1,vseq2,vtype) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_WT_IR(vseq1,vseq2,vtype1,vtype2) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_EQUAL_TYPE \
			( \
			vtype1, \
			vtype2 \
			), \
		BOOST_VMD_DETAIL_EQUAL_6_CNI, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(vseq1,vseq2,vtype1) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_WT_IR_D(d,vseq1,vseq2,vtype1,vtype2) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_EQUAL_TYPE_D \
			( \
			d, \
			vtype1, \
			vtype2 \
			), \
		BOOST_VMD_DETAIL_EQUAL_6_CNI_D, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(d,vseq1,vseq2,vtype1) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_WT(vseq1,vseq2,vtype1,vtype2) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_EQUAL_6_WT_IR(vseq1,vseq2,vtype1,vtype2)) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_WT_D(d,vseq1,vseq2,vtype1,vtype2) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_EQUAL_6_WT_IR_D(d,vseq1,vseq2,vtype1,vtype2)) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_GTYPE(vseq1,vseq2) \
	BOOST_VMD_DETAIL_EQUAL_6_WT \
		( \
		vseq1, \
		vseq2, \
		BOOST_VMD_TYPE(vseq1), \
		BOOST_VMD_TYPE(vseq2) \
		) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_GTYPE_D(d,vseq1,vseq2) \
	BOOST_VMD_DETAIL_EQUAL_6_WT_D \
		( \
		d, \
		vseq1, \
		vseq2, \
		BOOST_VMD_TYPE_D(d,vseq1), \
		BOOST_VMD_TYPE_D(d,vseq2) \
		) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6(vseq1,vseq2) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITAND \
			( \
			BOOST_VMD_IS_EMPTY(vseq1), \
			BOOST_VMD_IS_EMPTY(vseq2) \
			), \
		BOOST_VMD_DETAIL_EQUAL_BOTH_EMPTY, \
		BOOST_VMD_DETAIL_EQUAL_6_GTYPE \
		) \
	(vseq1,vseq2) \
/**/

#define BOOST_VMD_DETAIL_EQUAL_6_D(d,vseq1,vseq2) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITAND \
			( \
			BOOST_VMD_IS_EMPTY(vseq1), \
			BOOST_VMD_IS_EMPTY(vseq2) \
			), \
		BOOST_VMD_DETAIL_EQUAL_BOTH_EMPTY, \
		BOOST_VMD_DETAIL_EQUAL_6_GTYPE_D \
		) \
	(d,vseq1,vseq2) \
/**/

#endif /* BOOST_VMD_DETAIL_EQUAL_6_HPP */
