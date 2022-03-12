#pragma once

class Counter 
{
	private: 
		static int count; //lets class know of count's existence
		static const int DAYS_IN_WEEK;  //class constant
		static const float TAX_RATE; //another class constant
		
	public:
		static void setCount(int); 
		static void printCount(); 
		static void printConstants();
};