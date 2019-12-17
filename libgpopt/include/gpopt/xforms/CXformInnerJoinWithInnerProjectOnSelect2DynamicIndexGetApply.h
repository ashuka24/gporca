//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply.h
//
//	@doc:
//		Transform Inner Join with a Project on Select over a partitioned table
//		on the inner branch to a dynamic IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply_H
#define GPOPT_CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a partitioned on the inner branch
	//		to dynamic IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalInnerJoin, CLogicalIndexApply, CLogicalDynamicGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBtree>
	{
		private:
			// private copy ctor
			CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply
				(
				const CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalInnerJoin, CLogicalIndexApply, CLogicalDynamicGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBtree>
				(mp)
			{}

			// dtor
			virtual
			~CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply
}

#endif // !GPOPT_CXformInnerJoinWithInnerProjectOnSelect2DynamicIndexGetApply_H

// EOF
