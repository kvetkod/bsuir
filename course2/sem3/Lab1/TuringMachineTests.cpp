#include "pch.h"
#include <sstream>
#include<vector>
#include "CppUnitTest.h"
#include "../lab1.1/TuringMachine.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestNamespace
{
	TEST_CLASS(TuringMachineTests)
	{
	public:
		TEST_METHOD(ShowRulesTest1)
		{
			TuringMachine machine;
			char found, required, turn; int nextrule = 1;
			found = '1'; required = '1'; turn = 'r';
			machine.create_rules(found, required, turn, nextrule);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_rules(1);
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, '1');
		}
		TEST_METHOD(ShowTapeTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			machine.show_tape();

			string a = buf.str();
			char output = a[0];
			Assert::AreEqual(output, '1');
		}
		TEST_METHOD(AddElementTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, '1');
		}
		TEST_METHOD(AddElementTest2)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.add_element('2');
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, '1');
		}
		
		TEST_METHOD(AddElementTest4)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.add_element('2');
			machine.add_element('3');
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[2];
			Assert::AreEqual(a, '3');
		}

		TEST_METHOD(ClearTapeTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.clear_tape();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreNotEqual(a, '1');
		}
		TEST_METHOD(ClearTapeTest2)
		{
			TuringMachine machine;
			machine.add_element('1');
			machine.add_element('2');
			machine.clear_tape(); 
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreNotEqual(a, '1');
		}
		TEST_METHOD(ClearTapeTest3)
		{
			TuringMachine m1, m2;
			m1.add_element('1');
			m2.add_element('2');
			m1.clear_tape();
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			m2.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, '2');
		}
	

		TEST_METHOD(CreateRulesTest1)
		{
			TuringMachine machine;
			int size = 1;
			char found, required, turn; int nextrule;
			found = '1'; required = '0'; nextrule = 1; turn = 'r';
			machine.create_rules(found, required, turn, nextrule);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_rules(size);
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, '1');
		}

		TEST_METHOD(RunMachineTest1)
		{
			TuringMachine machine;
			machine.add_element('1');
			char found, required, turn; int nextrule;
			found = '1'; required = '0'; nextrule = 1; turn = 'r';
			machine.create_rules(found, required, turn, nextrule);
			machine.run_machine(1);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());

			machine.show_tape();
			cout.rdbuf(oldbuf);

			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, '0');
		}
	
		TEST_METHOD(RunMachineTest3)
		{
			TuringMachine m1, m2;
			m1.add_element('1');
			m2.add_element('1');
			stringstream buf2;
			streambuf* oldbuf2 = cout.rdbuf(buf2.rdbuf());

			m1.show_tape();
			cout.rdbuf(oldbuf2);

			string output2 = buf2.str();
			char b = output2[0];
			char found, required, turn; int nextrule;
			found = '1'; required = '0'; nextrule = 1; turn = 'r';
			m1.create_rules(found, required, turn, nextrule);
			m1.run_machine(1);
			stringstream buf1;
			streambuf* oldbuf1 = cout.rdbuf(buf1.rdbuf());

			m1.show_tape();
			cout.rdbuf(oldbuf1);
			
			string output1 = buf1.str();
			char a = output1[0];
			Assert::AreNotEqual(a, b);
		}
	};
}
