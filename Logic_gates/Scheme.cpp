#include "Scheme.h"
#include <iostream>
#include <format>
#include <algorithm>

void Scheme::add(gate* g)
{
	elements.push_back(g);
}

void Scheme::prepare()
{
	auto first_user_input = std::find_if(elements.begin(), elements.end(), [](gate* g) { return g->is_user_input(); });
	
	recursively_assign_precedence(*first_user_input, 0);
}

void Scheme::dump()
{
	std::cout << std::format("Sheme dump of {} elemets\n", elements.size());
	for (auto* e : elements)
	{
		std::cout << e->dump();
	}
}

void Scheme::recursively_assign_precedence(gate* current_gate, int precedence)
{
	current_gate->precedence = precedence;

	auto next_element = std::find_if(elements.begin(), elements.end(), [current_gate](gate* g) { return g->in[0] == current_gate; });
	if (next_element != elements.end())
		recursively_assign_precedence(*next_element, precedence + 1);
}
