#pragma once
#include <vector>
#include <memory>
#include "Gates.h"

enum class validation_result
{
	ok = 0,
	no_input,
	no_output,
	//no_path_from_input_to_output
};

class Scheme
{
public:
	void add(gate* g);
	[[nodiscard]] validation_result validate();
	void compile();
	void solve();
	void dump();

private:
	void calc_precedence();
	void reorder();
	
	//std::vector<std::unique_ptr<gate>> elements;
	std::vector<gate*> elements;
};

