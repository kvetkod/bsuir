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
	TEST_CLASS(LaptopTest) {
		TEST_METHOD(OpenLaptopTest)
		{
			Laptop A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.OpenLaptop();
			Assert::IsTrue(A.GetCover());
		}
		TEST_METHOD(CloseLaptopTest)
		{
			Laptop A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.OpenLaptop();
			A.CloseLaptop();
			Assert::IsFalse(A.GetCover());
		}
		TEST_METHOD(TurnOnTest)
		{
			Laptop A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.OpenLaptop();
			A.TurnOn();
			Assert::IsTrue(A.GetState());
		}
		TEST_METHOD(TurnOffTest)
		{
			Laptop A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.OpenLaptop();
			A.TurnOn();
			A.TurnOff();
			Assert::IsFalse(A.GetState());
		}
	};
}
