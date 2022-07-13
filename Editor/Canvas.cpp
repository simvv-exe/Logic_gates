#include <wx/wxprec.h>
#include <wx/vscroll.h>
#include "Canvas.h"

Canvas::Canvas(wxWindow* parent)
	: wxHVScrolledWindow(parent, wxID_ANY)
{ 
}

wxCoord Canvas::OnGetRowHeight(size_t row) const
{
	return 42;
}
wxCoord Canvas::OnGetColumnWidth(size_t column) const
{
	return 42;
}