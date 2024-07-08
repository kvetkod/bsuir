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
	TEST_CLASS(ComputerTest1)
	{
	public:
		TEST_METHOD(ComputerTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			Assert::IsFalse(A.GetState());
		}
		TEST_METHOD(TurnOnTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.TurnOn();
			Assert::IsTrue(A.GetState());
		}
		TEST_METHOD(TurnOffTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.TurnOn();
			A.TurnOff();
			Assert::IsFalse(A.GetState());
		}
		TEST_METHOD(InstallOPTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.InstallOP(true);
			Assert::IsTrue(A.GetOP());
		}
		TEST_METHOD(RequestTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Request();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(InformationTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Information();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'M');
		}
		TEST_METHOD(MemoryRecordingTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.MemoryRecording("123");
			Assert::AreEqual(A.GetMemory()->GetFree(), 253);
		}
		TEST_METHOD(GetKeyboardTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			string a = A.GetKeyboard()->GetDevice();
			char b = a[0];
			Assert::AreEqual(b, 'k');
		}
		TEST_METHOD(GetMonitorTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			string a = A.GetMonitor()->GetDevice();
			char b = a[0];
			Assert::AreEqual(b, 'm');
		}
		TEST_METHOD(GetProcessorTest) 
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.GetProcessor()->Information();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'M');
		}

	};

	


}
