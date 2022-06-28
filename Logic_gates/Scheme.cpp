#include "Scheme.h"
#include <iostream>
#include <format>
#include <algorithm>

void Scheme::add(gate* g)
{
	elements.push_back(g);
}

template<typename T, class Pred>
std::vector<T> find_all_if(const std::vector<T>& data, Pred pred)
{
	std::vector<T> rez;
	rez.reserve(data.size());
	auto begin_iter = data.begin();
	while (1)
	{
		auto fit = std::find_if(begin_iter, data.end(), pred);
		if (fit == data.end())
			break;
		rez.push_back(*fit);
		begin_iter = ++fit;	
	}
	return rez;
}

	
	recursively_assign_precedence(*first_user_input, 0);


void Scheme::prepare()
{
	calc_precedence();
	reorder();
}

void Scheme::solve()
{
	for (auto* e : elements)
		e->solve();
}

void Scheme::dump()
{
	std::cout << std::format("\n\nSheme dump of {} elemets\n", elements.size());
	for (auto* e : elements)
	{
		std::cout << e->dump();
	}
}

void Scheme::calc_precedence()
{
	auto first_user_input = std::find_if(elements.begin(), elements.end(), [](gate* g) { return g->is_user_input(); });

	auto current_gate = *first_user_input;
	int precedence = 0;

	while (1)
	{
		current_gate->precedence = precedence++;
		auto next_element = std::find_if(elements.begin(), elements.end(), [current_gate](gate* g) { return g->in[0] == current_gate; });
		if (next_element == elements.end())
			break;
		current_gate = *next_element;
	}
}

void Scheme::reorder()
{
	std::stable_sort(elements.begin(), elements.end(), [](gate* lhs, gate* rhs) { return lhs->precedence < rhs->precedence; });
}


