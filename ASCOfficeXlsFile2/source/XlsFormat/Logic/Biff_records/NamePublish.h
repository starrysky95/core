#pragma once

#include "BiffRecord.h"
#include <Logic/Biff_structures/BiffString.h>

namespace XLS
{


// Logical representation of NamePublish record in BIFF8
class NamePublish: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(NamePublish)
	BASE_OBJECT_DEFINE_CLASS_NAME(NamePublish)
public:
	NamePublish();
	~NamePublish();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeNamePublish;

//-----------------------------
	bool fPublished;
	bool fWorkbookParam;

	XLNameUnicodeString strName;
};

} // namespace XLS

