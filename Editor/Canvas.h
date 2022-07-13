#pragma once
class Canvas : public wxHVScrolledWindow
{
public:
	Canvas(wxWindow* parent);
	virtual wxCoord OnGetRowHeight(size_t row) const;
	virtual wxCoord OnGetColumnWidth(size_t column) const;
};

