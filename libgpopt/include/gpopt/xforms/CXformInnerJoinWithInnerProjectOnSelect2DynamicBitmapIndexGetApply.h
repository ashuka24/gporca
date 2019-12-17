//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply.h
//
//	@doc:
//		Transform Inner Join with a Project on Select over a partitioned table
//		on the inner branch to a dynamic Bitmap IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply_H
#define GPOPT_CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a partitioned on the inner branch
	//		to dynamic Bitmap IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalInnerJoin, CLogicalIndexApply, CLogicalDynamicGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
	{
		private:
			// private copy ctor
			CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply
				(
				const CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalInnerJoin, CLogicalIndexApply, CLogicalDynamicGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
				(mp)
			{}

			// dtor
			virtual
			~CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply
}

#endif // !GPOPT_CXformInnerJoinWithInnerProjectOnSelect2DynamicBitmapIndexGetApply_H

// EOF
