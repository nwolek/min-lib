/** @file
	@ingroup 	jamoma2
 
	@brief 		Unit test for the Dataspace class
 
	@author		Timothy Place
	@copyright	Copyright (c) 2005-2015 The Jamoma Group, http://jamoma.org.
	@license	This project is released under the terms of the MIT License.

 */

#include "Jamoma.h"

namespace Jamoma {

	class DataspaceTest {
		
		UnitTest<DataspaceTest>*	mTest;
		
	public:
		DataspaceTest(Jamoma::UnitTest<DataspaceTest>* test)
		: mTest(test)
		{
			testAngle();
			testGain();
		}

		void testAngle()
		{
			double y = 0;
			
			// Angle: conversion to radian
			Jamoma::Dataspace::Angle<double, Dataspace::AngleUnit::radian>		radianConverter;
			
			y = radianConverter(0.5);
			mTest->TEST_ASSERT("unspecified unit is assumed to be the native unit (radian)", mTest->compare(y, 0.5));
			
			y = radianConverter(0.6, Dataspace::AngleUnit::radian);
			mTest->TEST_ASSERT("angle expressed as radians", mTest->compare(y, 0.6));
			
			y = radianConverter(0.7, Dataspace::AngleUnit::rad);
			mTest->TEST_ASSERT("angle expressed as rad", mTest->compare(y, 0.7));
			
			y = radianConverter(180., Dataspace::AngleUnit::degree);
			mTest->TEST_ASSERT("angle expressed as degree", mTest->compare(y, kPi));
			
			y = radianConverter(90., Dataspace::AngleUnit::degree);
			mTest->TEST_ASSERT("angle expressed as deg", mTest->compare(y, kPi*0.5));
			
			// Angle: conversions to degree
			Jamoma::Dataspace::Angle<double, Dataspace::AngleUnit::degree>		degreeConverter;
			
			y = degreeConverter(kPi*0.5, Dataspace::AngleUnit::radian);
			mTest->TEST_ASSERT("radian-to-degree using enum unit", mTest->compare(y, 90.));
			
			y = degreeConverter(kPi*0.5, "rad");
			mTest->TEST_ASSERT("rad-to-degree using string unit", mTest->compare(y, 90.));
		}
		
		void testGain()
		{
			// Dataspace Test
			double y = 0;
			
			
			// Gain: conversions to linear
			Jamoma::Dataspace::Gain<double, Dataspace::GainUnit::linear>		linearGainConverter;
			
			y = linearGainConverter(0.5);
			mTest->TEST_ASSERT("unspecified unit is assumed to be the native unit (linear)", mTest->compare(y, 0.5));
			
			y = linearGainConverter(-6, Dataspace::GainUnit::db);
			mTest->TEST_ASSERT("db unit specified as enum", mTest->compare(y, 0.50118723362727224));
			
			y = linearGainConverter(-12, "db");
			// TODO: test
			mTest->TEST_ASSERT("db unit specified as string", mTest->compare(y, 0.25118864315095796));
			
			
			// Gain: conversions to db
			Jamoma::Dataspace::Gain<double, Dataspace::GainUnit::db>		dbGainConverter;
			
			y = dbGainConverter(0.5);
			mTest->TEST_ASSERT("unspecified unit is assumed to be the native unit (db)", mTest->compare(y, 0.5));
			
			y = dbGainConverter(2.0, Dataspace::GainUnit::linear);
			mTest->TEST_ASSERT("linear-to-db", mTest->compare(y, 6.0205999132796242));
			
			y = dbGainConverter(100.0, Dataspace::GainUnit::midi);
			mTest->TEST_ASSERT("midi-to-db using enum unit", mTest->compare(y, 0.0));
			
			y = dbGainConverter(50, "midi");
			mTest->TEST_ASSERT("midi-to-db using string unit", mTest->compare(y, -28.999923402717513));
			
		}
		
		
	};

} // namespace Jamoma


int main(int argc, const char * argv[])
{
	Jamoma::UnitTest<Jamoma::DataspaceTest>	aUnitTestInstance;
	return aUnitTestInstance.failureCount();
}
