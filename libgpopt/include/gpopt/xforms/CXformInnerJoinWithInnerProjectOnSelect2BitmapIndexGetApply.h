//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply.h
//
//	@doc:
//		Transform Inner Join with a Project on Select over a table 
//		on the inner branch to a  Bitmap IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply_H
#define GPOPT_CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a table on the inner branch
	//		to Bitmap IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalInnerJoin, CLogicalIndexApply, CLogicalGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
	{
		private:
			// private copy ctor
			CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply
				(
				const CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalInnerJoin, CLogicalIndexApply, CLogicalGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
				(mp)
			{}

			// dtor
			virtual
			~CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply
}

#endif // !GPOPT_CXformInnerJoinWithInnerProjectOnSelect2BitmapIndexGetApply_H

// EOF
