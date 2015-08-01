#pragma once

#include "BiffStructure.h"
#include <Logic/Biff_structures/SDContainer.h>
#include <Logic/Biff_structures/BiffString.h>

namespace XLS
{;

class CFRecord;

class FeatProtection : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(FeatProtection)
public:
	FeatProtection();
	FeatProtection(CFRecord& record);
	BiffStructurePtr clone();

	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

	static const ElementType	type = typeFeatProtection;

	bool fSD;
	unsigned int wPassword;
	XLUnicodeString stTitle;
	SDContainer sdContainer;
	bool sdContainer_set;
};

} // namespace XLS

