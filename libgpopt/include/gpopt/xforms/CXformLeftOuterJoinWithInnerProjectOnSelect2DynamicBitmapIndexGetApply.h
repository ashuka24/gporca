//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply.h
//
//	@doc:
//		Transform Left Outer Join with a Project on Select over a partitioned table 
//		on the inner branch to a dynamic Bitmap IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply_H
#define GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a partitioned on the inner branch
	//		to dynamic Bitmap IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalDynamicGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
	{
		private:
			// private copy ctor
			CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply
				(
				const CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalDynamicGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
				(mp)
			{}

			// dtor
			virtual
			~CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply
}

#endif // !GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply_H

// EOF
