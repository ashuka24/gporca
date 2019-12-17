//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply.h
//
//	@doc:
//		Transform Left Outer Join with a Project on Select over a partitioned table
//		on the inner branch to a dynamic IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply_H
#define GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a partitioned on the inner branch
	//		to dynamic IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalDynamicGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBtree>
	{
		private:
			// private copy ctor
			CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply
				(
				const CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalDynamicGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBtree>
				(mp)
			{}

			// dtor
			virtual
			~CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply
}

#endif // !GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicIndexGetApply_H

// EOF
