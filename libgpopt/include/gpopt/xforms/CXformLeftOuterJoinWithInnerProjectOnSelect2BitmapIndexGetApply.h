//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply.h
//
//	@doc:
//		Transform Left Outer Join with a Project on Select over a table 
//		on the inner branch to a Bitmap IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply_H
#define GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a table on the inner branch
	//		to Bitmap IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
	{
		private:
			// private copy ctor
			CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply
				(
				const CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBitmap>
				(mp)
			{}

			// dtor
			virtual
			~CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply
}

#endif // !GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2BitmapIndexGetApply_H

// EOF
