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
	TEST_CLASS(ProcesorTest) {
		TEST_METHOD(IncreaseSpeedTest)
		{
			Processor A("A", 1, 3, 4);
			A.IncreaseSpeed(5);
			Assert::AreEqual(A.GetSpeed(), 8);
		}
		TEST_METHOD(ReduceSpeedTest)
		{
			Processor A("A", 1, 6, 4);
			A.ReduceSpeed(5);
			Assert::AreEqual(A.GetSpeed(), 1);
		}
	};
}