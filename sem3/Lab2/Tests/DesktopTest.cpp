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
	TEST_CLASS(DesktopTest) {
		TEST_METHOD(ConnectTowifiTest) {
			Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
			B.ConnectToPower();
			B.TurnOn();
			B.ConnectToWiFi();
			Assert::IsTrue(B.GetEthernetPort());
		}
		TEST_METHOD(DisonnectTowifiTest) {
			Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
			B.ConnectToPower();
			B.TurnOn();
			B.ConnectToWiFi();
			B.DisconnectToWifi();
			Assert::IsFalse(B.GetEthernetPort());
		}
		TEST_METHOD(ConnectToPowerTest) {
			Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
			B.ConnectToPower();
			Assert::IsTrue(B.GetCabel());
		}
		TEST_METHOD(DisonnectToPowerTest) {
			Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
			B.ConnectToPower();
			B.DisconnectToPower();
			Assert::IsFalse(B.GetCabel());
		}
		TEST_METHOD(TurnOnTest) {
			Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
			B.ConnectToPower();
			B.TurnOn();
			Assert::IsTrue(B.GetState());
		}
		TEST_METHOD(TurnOffTest) {
			Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
			B.ConnectToPower();
			B.TurnOn();
			B.TurnOff();
			Assert::IsFalse(B.GetState());
		}
	};
}