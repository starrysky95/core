#pragma once

#include "BiffStructure.h"
#include "Ptg.h"

namespace XLS
{;

class CFRecord;

class RgbExtra : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(RgbExtra)
public:
	BiffStructurePtr clone();

	static const ElementType	type = typeRgbExtra;
	
	void load(CFRecord& record, const PtgVector& records_from_rgce, bool is_part_of_a_revision);
	void load(CFRecord& record, unsigned short rgce_record_type, bool is_part_of_a_revision);
	virtual void store(CFRecord& record);

	const PtgQueue& getPtgs() const;
	const bool isEmpty() const;
	void addPtg(const PtgPtr ptg);

	// Shall not be used. This is just a stub for the virtual 'load' realization
	virtual void load(CFRecord& record);

private:
	PtgQueue ptg_records;
};

} // namespace XLS

