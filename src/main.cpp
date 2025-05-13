#include "Engine.h"
#include <iostream>


int main()
{
	try {
		auto engine = Engine();
		engine.run();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "unknown error\n" << std::endl;
	}
}
