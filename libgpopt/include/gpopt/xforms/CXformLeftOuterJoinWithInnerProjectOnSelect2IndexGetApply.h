//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2019 Pivotal, Inc.
//
//	@filename:
//		CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply.h
//
//	@doc:
//		Transform Left Outer Join with a Project on Select over a table
//		on the inner branch to a IndexGet Apply
//
//	@owner:
//		n
//
//	@test:
//
//---------------------------------------------------------------------------

#ifndef GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply_H
#define GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply_H

#include "gpos/base.h"
#include "gpopt/xforms/CXformJoin2IndexApplyBase.h"

namespace gpopt
{
	using namespace gpos;

	//---------------------------------------------------------------------------
	//	@class:
	//		CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply
	//
	//	@doc:
	//		Transform Inner Join with a Select over a table on the inner branch
	//		to IndexGet Apply
	//
	//---------------------------------------------------------------------------
	class CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply : public CXformJoin2IndexApplyBase
		<CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalGet,
		true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBtree>
	{
		private:
			// private copy ctor
			CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply
				(
				const CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply &
				);

		public:
			// ctor
			explicit
			CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply(CMemoryPool *mp)
				: CXformJoin2IndexApplyBase
				 <CLogicalLeftOuterJoin, CLogicalIndexApply, CLogicalGet,
				 true /*fWithSelect*/, true /*fWithProject*/, false /*is_partial*/, IMDIndex::EmdindBtree>
				(mp)
			{}

			// dtor
			virtual
			~CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply()
			{}

			// ident accessors
			virtual
			EXformId Exfid() const
			{
				return ExfLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply;
			}

			virtual
			const CHAR *SzId() const
			{
				return "CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply";
			}

			// return true if xform should be applied only once
			virtual
			BOOL IsApplyOnce()
			{
				return true;
			}

	}; // class CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply
}

#endif // !GPOPT_CXformLeftOuterJoinWithInnerProjectOnSelect2IndexGetApply_H

// EOF
