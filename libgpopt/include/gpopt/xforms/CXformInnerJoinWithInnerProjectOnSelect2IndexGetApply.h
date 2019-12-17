//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply.h
//
//	@doc:
//		Transform Inner Join with a Project on Select over a table
//		on the inner branch to a IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply_H
#define GPOPT_CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a table on the inner branch
	//		to IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalInnerJoin, CLogicalIndexApply, CLogicalGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::Emdind>
	{
		private:
			// private copy ctor
			CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply
				(
				const CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalInnerJoin, CLogicalIndexApply, CLogicalGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::Emdind>
				(mp)
			{}

			// dtor
			virtual
			~CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfInnerJoinWithInnerProjectOnSelect2IndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply
}

#endif // !GPOPT_CXformInnerJoinWithInnerProjectOnSelect2IndexGetApply_H

// EOF
