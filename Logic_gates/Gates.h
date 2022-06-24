#pragma once

class gate
{
public:
	bool out{ false };
};

class logic_and : public gate
{
public:
	void solve()
	{
		out = in1->out && in2->out;
	}

//private:
	gate* in1{ nullptr };
	gate* in2{ nullptr };
};

class logic_or : public gate
{
public:
	void solve()
	{
		out = in1->out || in2->out;
	}

//private:
	gate* in1{ nullptr };
	gate* in2{ nullptr };
};

class logic_not : public gate
{
public:
	void solve()
	{
		out = !in->out;
	}

//private:
	gate* in{ nullptr };
};

class logic_xor : public gate
{
public:
	void solve()
	{
		out = in1->out ^ in2->out;
	}

//private:
	gate* in1{ nullptr };
	gate* in2{ nullptr };
};

class user_input : public gate
{
};

class user_output : public gate
{
public:
	bool get_rez() const { return terminal->out; }

	gate* terminal{ nullptr };
};