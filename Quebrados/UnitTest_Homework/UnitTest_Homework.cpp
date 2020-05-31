#include "pch.h"
#include "CppUnitTest.h"
#include "../Fraction/Fraction.cpp"
#include "../Input/Input.cpp"
#include "../Operation/Operation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHomework
{
	TEST_CLASS(UnitTestHomework)
	{
	public:
		
		TEST_METHOD(to_string_test){
			//Arrange
			Fraction frac;
			frac.set_numerator(2);
			frac.set_denominator(4);
			string expectedValue = "2/4";
			//Act
			string result = frac.to_string();
			//Assert
			Assert::AreEqual(expectedValue, result);
		}

		TEST_METHOD(string_to_float_test) {
			//Arrange
			Input test;
			string data = "1.2";
			float expectedValue = 1.2;
			//Act
			float result = test.string_to_float(data);;
			//Assert
			Assert::AreEqual(expectedValue, result);
		}

		TEST_METHOD(calculate_test) {
			//Arrange
			Fraction frac_1, frac_2;
			frac_1.set_numerator(12);
			frac_1.set_denominator(2);
			
			frac_2.set_numerator(78);
			frac_2.set_denominator(6);
			
			Fraction expectedValue;
			expectedValue.set_numerator(228);
			expectedValue.set_denominator(12);

			//Act
			Operation opertacion;
			Fraction result = opertacion.calculate(frac_1, frac_2);

			//Assert
			Assert::AreEqual(expectedValue.to_string(), result.to_string());
		}
	};
}
