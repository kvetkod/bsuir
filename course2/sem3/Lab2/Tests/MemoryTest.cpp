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
	TEST_CLASS(MemoryTest) {
		TEST_METHOD(MemoryCaptureTest) {
			Memory a(256);
			a.MemoryCapture(6);
			Assert::AreEqual(a.GetFree(), 250);
		}
		TEST_METHOD(InformationTest) {
			Memory a(256);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			a.Information();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char b = output[0];

			Assert::AreEqual(b, 'A');
		}
	};
}