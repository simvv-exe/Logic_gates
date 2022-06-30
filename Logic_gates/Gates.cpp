#include "Gates.h"

std::string gate::dump() const
{
	std::string temp;
	temp += std::format("\"{}\" {} @{}\n", name, type, static_cast<const void*>(this));
	temp += std::format("\tprecedence = {}\n", precedence);
	for (int i = 0; i < in_size; ++i)
	{
		if (in[i])
			temp += std::format("\tin[{}] = \"{}\" {} @{}\n", i, in[i]->name, in[i]->type, static_cast<void*>(in[i]));
		else
			temp += std::format("\tin[{}] = N/C\n", i);
	}
	temp += std::format("\tout = {}\n", out);
	return temp;
}

void logic_and::solve()
{
	out = in[0]->out && in[1]->out;
}

void logic_or::solve()
{
	out = in[0]->out || in[1]->out;
}

void logic_not::solve()
{
	out = !in[0]->out;
}

void logic_xor::solve()
{
	out = in[0]->out ^ in[1]->out;
}
