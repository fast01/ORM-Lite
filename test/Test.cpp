
// Unit Test of ORM Lite
// https://github.com/BOT-Man-JL/ORM-Lite
// BOT Man, 2016

#include <string>
#include <iostream>

#include "../src/ORMLite.h"
using namespace BOT_ORM;
using namespace BOT_ORM::Expression;

struct ModelA
{
	int a_int;
	std::string a_string;
	double a_double;

	Nullable<int> an_int;
	Nullable<double> an_double;
	Nullable<std::string> an_string;

	// Inject ORM-Lite into this Class :-)
	ORMAP ("ModelA", a_int, a_string, a_double, an_int, an_double, an_string);
};

struct ModelB
{
	unsigned long b_ulong;
	float b_float;

	Nullable<unsigned long> bn_ulong;
	Nullable<float> bn_float;

	// Inject ORM-Lite into this Class :-)
	ORMAP ("ModelB", b_ulong, b_float, bn_ulong, bn_float);
};

struct ModelC
{
	unsigned c_uint;
	int a_int;
	unsigned long b_ulong;

	// Inject ORM-Lite into this Class :-)
	ORMAP ("ModelC", c_uint, a_int, b_ulong);
};

int main ()
{
	// Open a Connection with *Test.db*
	ORMapper mapper ("Test.db");

	// Create Brand New Tables
	auto initTable = [&mapper] (const auto &model)
	{
		try
		{
			mapper.CreateTbl (model);
		}
		catch (...)
		{
			mapper.DropTbl (model);
			mapper.CreateTbl (model);
		}
	};
	initTable (ModelA {});
	initTable (ModelB {});
	initTable (ModelC {});

	// Case: Not Compile

	//mapper.CreateTbl (int ());
	//mapper.DropTbl (int ());
	//mapper.Insert (int ());
	//mapper.Insert (int (), false);
	////mapper.InsertRange (int ());
	//mapper.InsertRange (std::vector<int> ());
	//mapper.InsertRange (std::vector<int> (), false);
	//mapper.Update (int ());
	////mapper.UpdateRange (int ());
	//mapper.UpdateRange (std::vector<int> ());
	//mapper.Update (int (), SetExpr { "" }, Expr { Selectable<int> {}, "" });
	//mapper.Delete (int ());
	//mapper.Delete (int (), Expr { Selectable<int> {}, "" });
	//mapper.Query (int ());
	//FieldExtractor { int (), double () };
	//mapper.Query (ModelA {})
	//	.Join (int (), Expr { Selectable<int> {}, "" });
	//mapper.Query (ModelA {})
	//	.LeftJoin (int (), Expr { Selectable<int> {}, "" });

	return 0;
}
