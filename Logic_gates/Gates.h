#pragma once

class logic_and
{
public:
	void solve()
	{
		out = in1 && in2;
	}

//private:
	bool in1 { false };
	bool in2{ false };
	bool out{ false };
};

class logic_or
{
public:
	void solve()
	{
		out = in1 || in2;
	}

//private:
	bool in1{ false };
	bool in2{ false };
	bool out{ false };
};

class logic_not
{
public:
	void solve()
	{
		out = !in;
	}

//private:
	bool in{ false };
	bool out{ false };
};

class logic_xor
{
public:
	void solve()
	{
		out = in1 ^ in2;
	}

//private:
	bool in1{ false };
	bool in2{ false };
	bool out{ false };
};