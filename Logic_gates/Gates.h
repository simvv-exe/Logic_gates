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
	std::string dump() const;
	virtual bool is_user_input() const { return false; }
	//void set_precedence(const int precedence_p) { precedence = precedence_p; }

	const std::string name;
	const std::string type;
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

	void solve() override;
};

class logic_or : public gate
{
public:
	logic_or(const std::string& name_p = ""s)
		: gate("or", name_p)
	{}

	void solve() override;
};

class logic_not : public gate
{
public:
	logic_not(const std::string& name_p = ""s)
		: gate("not", name_p)
	{}

	void solve() override;
};

class logic_xor : public gate
{
public:
	logic_xor(const std::string& name_p = ""s)
		: gate("xor", name_p)
	{}

	void solve() override;
};

class user_input : public  gate
{
public:
	user_input(const std::string& name_p = ""s)
		: gate("input", name_p)
	{}

	bool is_user_input() const override { return true; }

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
