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
	TEST_CLASS(MonitorTest) {
		TEST_METHOD(ConnectionTest1)
		{
			Monitor A("a", false);
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
			Monitor A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(DisconnectionTest1)
		{
			Monitor A("a", true);
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
			Monitor A("a", true);
			A.Input();
		}
		TEST_METHOD(OutputTest)
		{
			Monitor A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Output("123");
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 't');
		}
	};

}