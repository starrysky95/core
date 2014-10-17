#include "stdafx.h"

#include "ConvertXls2Xlsx.h"

#include "..\..\Common\OfficeFileErrorDescription.h"

#include "XlsFormat\Document\Document.h" 
#include "XlsFormat\Binary\CompoundFile.h"
#include "XlsFormat\Binary\BinSmartPointers.h"
#include "XlsFormat\Binary\CFStreamCacheReader.h"
//#include "XlsFormat\Binary\CFStreamCacheWriter.h"
#include "XlsFormat\Logic\GlobalWorkbookInfo.h"
#include "XlsFormat\Logic\WorkbookStreamObject.h"
#include "XlsFormat\Logic\BinProcessor.h"
#include "XlsFormat\Logic\SummaryInformationStream\SummaryInformation.h"
//#include "XlsFormat\Auxiliary\HelpersTagsGenerator.h"

HRESULT ConvertXls2Xlsx(const std::wstring &ext, const std::wstring & srcFile, const std::wstring & dstPath, bool bOnlyPresentation, const ProgressCallback* CallBack)
{
	HRESULT hr = S_OK;

	try 
    {
		XLS::CompoundFile cfile(srcFile, XLS::CompoundFile::cf_ReadMode);

		Document		doc(dstPath);

		XLS::CFStreamPtr summary;
		XLS::CFStreamPtr doc_summary;

		try
		{
			summary = cfile.getSummaryInformationStream();
		}
		catch (...)
		{
			return AVS_ERROR_UNEXPECTED;
		}

		try
		{
			doc_summary = cfile.getDocumentSummaryInformationStream();
		}
		catch (...)
		{
			return AVS_ERROR_UNEXPECTED;
		}

		WORD workbook_code_page = XLS::WorkbookStreamObject::DefaultCodePage;
		if(summary)
		{
			OLEPS::SummaryInformation summary_info(summary);
			workbook_code_page = summary_info.GetCodePage();
		}
		else if(doc_summary)
		{
			OLEPS::SummaryInformation doc_summary_info(doc_summary);
			workbook_code_page = doc_summary_info.GetCodePage();
		}

		if(1200/* UTF-16 */ == workbook_code_page || 0/*error*/ == workbook_code_page)
		{
			workbook_code_page = XLS::WorkbookStreamObject::DefaultCodePage;
		}

		XLS::GlobalWorkbookInfoPtr global_info(new XLS::GlobalWorkbookInfo(workbook_code_page));

		XLS::CFStreamCacheReader stream_reader(cfile.getWorkbookStream(), global_info);
		
		//XLS::BiffStructurePtr root = boost::shared_ptr<XLS::BiffStructure>(new XLS::BiffStructure());
		XLS::BinReaderProcessor proc(stream_reader , true);
		
		proc.mandatory(XLS::WorkbookStreamObject(workbook_code_page));

		return	S_OK;

	}
	catch(...)
	{
		return AVS_ERROR_UNEXPECTED;
	}
	return hr;

}