#pragma once

namespace ID
{
	enum ID
	{
		new_doc = wxID_HIGHEST + 1,
		toolbar_1 = wxID_HIGHEST + 1,
		hello
	};
}

class MyApp : public wxApp
{
public:
	//MyApp()  
	//{}
	virtual bool OnInit();
};

