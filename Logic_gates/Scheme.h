#pragma once
#include <vector>
#include <memory>
#include "Gates.h"


class Scheme
{
public:

	void add(gate* g);
	void prepare();
	void dump();
private:
	void recursively_assign_precedence(gate* current_gate, int precedence);
	//std::vector<std::unique_ptr<gate>> elements;
	std::vector<gate*> elements;
};

