#pragma once
#include <vector>
#include <memory>
#include "Gates.h"


class Scheme
{
public:

	void add(gate* g);
	void prepare();
	void solve();
	void dump();
private:
	void calc_precedence();
	void reorder();
	//std::vector<std::unique_ptr<gate>> elements;
	std::vector<gate*> elements;
};

