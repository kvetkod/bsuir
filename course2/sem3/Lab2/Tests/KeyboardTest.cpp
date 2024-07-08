#include "pch.h"
#include "CppUnitTest.h"
#include"Computer.h"
#include"Desktop.h"
#include"Device.h"
#include"Keyboard.h"
#include"Laptop.h"
#include"Memory.h"
#include"Monitor.h"
#include"OperatingSystem.h"
#include"Processor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(KeyboardTest) {
		TEST_METHOD(ConnectionTest1)
		{
			Keyboard A("a", false);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(ConnectionTest2)
		{
			Keyboard A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(DisonnectionTest1)
		{
			Keyboard A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Disconnection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(InputTest)
		{
			Keyboard A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			stringstream input;
			input << "123" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			A.Input();
			cin.rdbuf(oldCinBuf);
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'e');
		}
		TEST_METHOD(OutpurTest) {
			Keyboard A("a", true);
			A.Output("123");
		}
	};
}