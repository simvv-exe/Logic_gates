#pragma once

#include <string>
#include <format>

using namespace std::string_literals;

constexpr int in_size = 2;

class gate
{
public:
	gate(const std::string& type_p, const std::string& name_p)
		: type(type_p)
		, name(name_p)
	{}
	//gate(std::string&& type_p, std::string&& name_p)
	//	: type(std::move(type_p))
	//	, name(std::move(name_p))
	//{}
	virtual void solve() = 0;
	std::string dump() const
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
	virtual bool is_user_input() const
	{
		return false;
	}

	std::string name;
	std::string type;
	int precedence{ -1 };
	gate* in[in_size]{};
	bool out{ false };
};

class logic_and : public gate
{
public:
	logic_and(const std::string& name_p = ""s)
		: gate("and", name_p)
	{}

	void solve() override
	{
		out = in[0]->out && in[1]->out;
	}
};

class logic_or : public gate
{
public:
	logic_or(const std::string& name_p = ""s)
		: gate("or", name_p)
	{}

	void solve() override
	{
		out = in[0]->out || in[1]->out;
	}

};

class logic_not : public gate
{
public:
	logic_not(const std::string& name_p = ""s)
		: gate("not", name_p)
	{}

	void solve() override
	{
		out = !in[0]->out;
	}
};

class logic_xor : public gate
{
public:
	logic_xor(const std::string& name_p = ""s)
		: gate("xor", name_p)
	{}
	void solve() override
	{
		out = in[0]->out ^ in[1]->out;
	}
};

class user_input : public gate
{
public:
	user_input(const std::string& name_p = ""s)
		: gate("input", name_p)
	{}

	bool is_user_input() const override
	{
		return true;
	}

	void solve() override {}
};

class user_output : public gate
{
public:
	user_output(const std::string& name_p = ""s)
		: gate("output", name_p)
	{}

	void solve() override 
	{
		out = in[0]->out;
	}
};