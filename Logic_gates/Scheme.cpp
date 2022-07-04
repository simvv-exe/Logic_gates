#include "Scheme.h"
#include <iostream>
#include <format>
#include <algorithm>

template<typename T, class Pred>
std::vector<T> find_all_if(const std::vector<T>& data, const Pred& pred)
{
	// static_assert than pred is callable with T and return value is bool convertable
	std::vector<T> rez;
	// is this reserve reasonable
	rez.reserve(data.size());
	auto begin_iter = data.cbegin();
	while (1)
	{
		const auto fit = std::find_if(begin_iter, data.cend(), pred);
		if (fit == data.cend())
			break;
		rez.push_back(*fit);
		begin_iter = std::next(fit);	
	}
	return rez;
}


void Scheme::add(gate* g)
{
	elements.push_back(g);
}

validation_result Scheme::validate()
{
	bool has_input = false;
	for (auto* e : elements)
	{
		if (e->is_user_input())
		{
			has_input = true;
			break;
		}
	}
	if (!has_input)
		return validation_result::no_input;
	
	bool has_output = false;
	for (auto* e : elements)
	{
		if (e->is_user_output())
		{
			has_output = true;
			break;
		}
	}
	if (!has_output)
		return validation_result::no_output;

	return validation_result::ok;
}

void Scheme::compile()
{
	if (validate() != validation_result::ok)
		throw std::runtime_error("lavidation error");
	
	//calc_precedence_as_signal_propagation();
	calc_precedence_as_best_backtrace_fit();
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


void Scheme::calc_precedence_as_signal_propagation()
{
	// solve signal's propagation from use input to last element in chain 
	auto elements_to_visit = find_all_if(elements, [](gate* g) { return g->is_user_input(); });
	
	// FIXME: added protection againts no user input
	
	int precedence = 0;
	decltype(elements_to_visit) nex_step_to_visit;

	while (1)
	{
		nex_step_to_visit.clear();

		for (auto* e : elements_to_visit)
		{
			if (e->precedence != -1)
				continue;
			e->precedence = precedence++;
			const auto one_pass_finded = find_all_if(elements, [e](gate* g)
				{
					bool rez = false;
					for (auto b : g->in)
					{
						if (b == e)
						{
							rez = true;
							break;
						}
					}
					return rez;
				});
			nex_step_to_visit.insert(nex_step_to_visit.end(), one_pass_finded.begin(), one_pass_finded.end()); // is there more succinct way of expressing this, like append or +=
		}
		if (nex_step_to_visit.empty())
			break;
		elements_to_visit = nex_step_to_visit;
	}

	// reorder
	std::stable_sort(elements.begin(), elements.end(), [](gate* lhs, gate* rhs) { return lhs->precedence < rhs->precedence; });
}

void Scheme::calc_precedence_as_best_backtrace_fit()
{
	auto elements_to_visit = find_all_if(elements, [](gate* g) { return g->is_user_output(); });


	int precedence = 0;
	decltype(elements_to_visit) nex_step_to_visit;

	while (1)
	{
		nex_step_to_visit.clear();

		for (auto* e : elements_to_visit)
		{
			if (e->precedence != -1)
				continue;
			e->precedence = precedence++;
			if (auto element = e->in[0]; element)
				nex_step_to_visit.push_back(element);
			if (auto element = e->in[1]; element)
				nex_step_to_visit.push_back(element);

		}
		if (nex_step_to_visit.empty())
			break;
		elements_to_visit = nex_step_to_visit;
	}

	// reorder
	std::stable_sort(elements.begin(), elements.end(), [](gate* lhs, gate* rhs) { return lhs->precedence > rhs->precedence; });
}


