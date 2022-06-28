#pragma once

#include <string>
#include <format>

class gate
{
public:
	virtual void solve() = 0;
	virtual std::string dump() const = 0;
	virtual bool is_user_input() const
	{
		return false;
	}

	int precedence{ -1 };
	gate* in[8]{};
	bool out{ false };
};

class logic_and : public gate
{
public:
	void solve() override
	{
		out = in[0]->out && in[1]->out;
	}

	std::string dump() const override
	{
		std::string temp;
		temp += std::format("And @ {}\n", static_cast<const void*>(this));
		temp += std::format("\tprecedence = {}\n", precedence);
		for (int i = 0; i < 8; ++i)
		{
			temp += std::format("\tin[{}] = {}\n", i, static_cast<void*>(in[i]));
		}
		temp += std::format("\tout = {}\n", out);
		return temp;
	}
};

class logic_or : public gate
{
public:
	void solve() override
	{
		out = in[0]->out || in[1]->out;
	}

	std::string dump() const override
	{
		std::string temp;
		temp += std::format("Or @ {}\n", static_cast<const void*>(this));
		temp += std::format("\tprecedence = {}\n", precedence);
		for (int i = 0; i < 8; ++i)
		{
			temp += std::format("\tin[{}] = {}\n", i, static_cast<void*>(in[i]));
		}
		temp += std::format("\tout = {}\n", out);
		return temp;
	}
};

class logic_not : public gate
{
public:
	void solve() override
	{
		out = !in[0]->out;
	}

	std::string dump() const override
	{
		std::string temp;
		temp += std::format("Not @ {}\n", static_cast<const void*>(this));
		temp += std::format("\tprecedence = {}\n", precedence);
		for (int i = 0; i < 8; ++i)
		{
			temp += std::format("\tin[{}] = {}\n", i, static_cast<void*>(in[i]));
		}
		temp += std::format("\tout = {}\n", out);
		return temp;
	}
};

class logic_xor : public gate
{
public:
	void solve() override
	{
		out = in[0]->out ^ in[1]->out;
	}

	std::string dump() const override
	{
		std::string temp;
		temp += std::format("Xor @ {}\n", static_cast<const void*>(this));
		temp += std::format("\tprecedence = {}\n", precedence);
		for (int i = 0; i < 8; ++i)
		{
			temp += std::format("\tin[{}] = {}\n", i, static_cast<void*>(in[i]));
		}
		temp += std::format("\tout = {}\n", out);
		return temp;
	}
};

class user_input : public gate
{
public:
	bool is_user_input() const override
	{
		return true;
	}

	void solve() override {}

	std::string dump() const override
	{
		std::string temp;
		temp += std::format("Input @ {}\n", static_cast<const void*>(this));
		temp += std::format("\tprecedence = {}\n", precedence);
		for (int i = 0; i < 8; ++i)
		{
			temp += std::format("\tin[{}] = {}\n", i, static_cast<void*>(in[i]));
		}
		temp += std::format("\tout = {}\n", out);
		return temp;
	}
};

class user_output : public gate
{
public:
	void solve() override 
	{
		out = in[0]->out;
	}

	std::string dump() const override
	{
		std::string temp;
		temp += std::format("Output @ {}\n", static_cast<const void*>(this));
		temp += std::format("\tprecedence = {}\n", precedence);
		for (int i = 0; i < 8; ++i)
		{
			temp += std::format("\tin[{}] = {}\n", i, static_cast<void*>(in[i]));
		}
		temp += std::format("\tout = {}\n", out);
		return temp;
	}
};