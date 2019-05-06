#include "DummyChoosers.hpp"
#include <stdlib.h>

std::string RandomChooser::choose(unsigned int length) {
	std::string r="";
	for (unsigned int i=0; i<length; ++i) {
		char c = '0' + (rand()%10);
		r += c;
		
	}
	return r;
}
