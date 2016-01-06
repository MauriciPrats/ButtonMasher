#pragma once


#include <string>
#include <sstream>

class Utils
{
public:

	static Utils& getInstance() {
		static Utils INSTANCE;
		return INSTANCE;
	}

	
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
	


};
