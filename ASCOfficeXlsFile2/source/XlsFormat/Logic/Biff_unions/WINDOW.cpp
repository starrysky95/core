
#include "WINDOW.h"
#include <Logic/Biff_records/Window2.h>
#include <Logic/Biff_records/PLV.h>
#include <Logic/Biff_records/Scl.h>
#include <Logic/Biff_records/Pane.h>
#include <Logic/Biff_records/Selection.h>

namespace XLS
{


WINDOW::WINDOW()
{
}


WINDOW::~WINDOW()
{
}


BaseObjectPtr WINDOW::clone()
{
	return BaseObjectPtr(new WINDOW(*this));
}


// WINDOW = Window2 [PLV] [Scl] [Pane] *Selection
const bool WINDOW::loadContent(BinProcessor& proc)
{
	if(!proc.mandatory<Window2>())
	{
		return false;
	}
	m_Window2 = elements_.back();
	elements_.pop_back();

	if (proc.optional<PLV>())
	{
		m_PLV = elements_.back();
		elements_.pop_back();
	}
	if (proc.optional<Scl>())
	{
		m_Scl = elements_.back();
		elements_.pop_back();
	}	
	if (proc.optional<Pane>())
	{
		m_Pane = elements_.back();
		elements_.pop_back();
	}
	int count = proc.repeated<Selection>(0, 0);
	while(count > 0)
	{
		m_arSelection.insert(m_arSelection.begin(), elements_.back());
		elements_.pop_back();
		count--;
	}
	return true;
}

int WINDOW::serialize(std::wostream & stream)
{
	Window2 * window2 = dynamic_cast<Window2*>(m_Window2.get());
	if (window2 == NULL) return 0;

	Pane	* pane	= dynamic_cast<Pane*>	(m_Pane.get());
	PLV		* plv	= dynamic_cast<PLV*>	(m_PLV.get());
	Scl		* scl	= dynamic_cast<Scl*>	(m_Scl.get());

	CP_XML_WRITER(stream)    
    {
		CP_XML_NODE(L"sheetViews")
		{	
			CP_XML_NODE(L"sheetView")
			{	
				if (window2->fSelected)				CP_XML_ATTR(L"tabSelected"		, true);
				if (window2->fDspFmlaRt)			CP_XML_ATTR(L"showFormulas"		, true);
				if (!window2->fDspGridRt)			CP_XML_ATTR(L"showGridLines"	, false);
				if (!window2->fDspRwColRt)			CP_XML_ATTR(L"showRowColHeaders", false);
				if (!window2->fDspZerosRt)			CP_XML_ATTR(L"showZeros"		, false);
				if (window2->fRightToLeft)			CP_XML_ATTR(L"rightToLeft"		, true);
				if ((plv) && (!plv->fRulerVisible))	CP_XML_ATTR(L"showRuler"		, false);
				if (!window2->fDspGuts)				CP_XML_ATTR(L"showOutlineSymbols", false);
				if (!window2->fDefaultHdr)			CP_XML_ATTR(L"defaultGridColor"	, false);
				
				if ((plv) && (plv->fWhitespaceHidden))
				{
					CP_XML_ATTR(L"showWhiteSpace", false);
				}
				if (window2->fSLV)
				{
					CP_XML_ATTR(L"view", L"pageBreakPreview");
				}
				else if ((plv) && (plv->fPageLayoutView))
				{
					CP_XML_ATTR(L"view", L"pageLayout");
				}
				if ((window2->topLeftCell.value()) && (*window2->topLeftCell.value() != L"A1"))
				{
					CP_XML_ATTR(L"topLeftCell", *window2->topLeftCell.value());
				}
				if ( window2->icvHdr != (_UINT16)64)
				{
					CP_XML_ATTR(L"colorId", window2->icvHdr);
				}
				if (scl)
				{
					int scale = (int)(scl->nscl * 100./ scl->dscl);
					if (scale != 100 && scale > 0)
						CP_XML_ATTR(L"zoomScale", scale);
				}
				if ( (window2->fSLV || ((plv) && (plv->fPageLayoutView)) || !scl) &&  window2->wScaleNormal != (_UINT16)0)
				{
					CP_XML_ATTR(L"zoomScaleNormal", window2->wScaleNormal);
				}
				if ( (!window2->fSLV || !scl) &&  window2->wScaleSLV != (_UINT16)0)
				{
					CP_XML_ATTR(L"zoomScaleSheetLayoutView", window2->wScaleSLV);
				}
				CP_XML_ATTR(L"workbookViewId", 0);
				if (pane)
				{
					CP_XML_NODE(L"pane")
					{	
						if (pane->x != (_INT32)0)	CP_XML_ATTR(L"xSplit", pane->x);
						if (pane->y != (_INT32)0)	CP_XML_ATTR(L"ySplit", pane->y);
						
						if ((pane->topLeftCell.value()) && (*pane->topLeftCell.value() != L"A1"))
							CP_XML_ATTR(L"topLeftCell", *pane->topLeftCell.value());
						switch(pane->pnnAcct)
						{
						case PaneType::REVTPNNBOTRIGHT:	CP_XML_ATTR(L"activePane", L"bottomRight");	break;
						case PaneType::REVTPNNTOPRIGHT:	CP_XML_ATTR(L"activePane", L"topRight");	break;
						case PaneType::REVTPNNBOTLEFT:	CP_XML_ATTR(L"activePane", L"bottomLeft");	break;
						//default:						CP_XML_ATTR(L"activePane", L"topLeft"); 
						}

						if (window2->fFrozenRt && window2->fFrozenNoSplit) 
							CP_XML_ATTR(L"state", L"frozen");
						else if (window2->fFrozenRt && !window2->fFrozenNoSplit) 
							CP_XML_ATTR(L"state", L"frozenSplit");
						else 
							CP_XML_ATTR(L"state", L"split");
					}
				}
				for (int i = 0; i < m_arSelection.size(); i++)
				{
					Selection * selection = dynamic_cast<Selection*>(m_arSelection[i].get());
					if (selection == NULL) continue;

					if (selection->pnn == (unsigned char)PaneType::REVTPNNTOPLEFT &&
						selection->activeCell == L"A1"		&&
						selection->irefAct == (_INT16)0		&&
						selection->sqref == L"A1") continue;

					CP_XML_NODE(L"selection")
					{
						switch(selection->pnn)
						{
						case PaneType::REVTPNNBOTRIGHT:	CP_XML_ATTR(L"pane", L"bottomRight");	break;
						case PaneType::REVTPNNTOPRIGHT:	CP_XML_ATTR(L"pane", L"topRight");		break;
						case PaneType::REVTPNNBOTLEFT:	CP_XML_ATTR(L"pane", L"bottomLeft");	break;
						//	default:					CP_XML_ATTR(L"pane", L"topLeft"); 
						}

						if (*selection->activeCell.value() != L"A1") 
							CP_XML_ATTR(L"activeCell", *selection->activeCell.value());

						if (selection->irefAct != 0) 
							CP_XML_ATTR(L"activeCellId", selection->irefAct);

 						if (*selection->sqref.value() != L"A1") 
							CP_XML_ATTR(L"sqref", *selection->sqref.value());
					}

				}
			}
		}
	}
	return 0;
}

} // namespace XLS

