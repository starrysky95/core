#pragma once

#include "BiffStructure.h"
#include "DXFN.h"
#include "XFExtNoFRT.h"

namespace XLS
{

class CFRecord;

class DXFN12 : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(DXFN12)
public:
	BiffStructurePtr clone();

	static const ElementType	type = typeDXFN12;
	
	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

	_UINT32			cbDxf;
	DXFNPtr			dxfn;
	XFExtNoFRTPtr	xfext;
};

} // namespace XLS

