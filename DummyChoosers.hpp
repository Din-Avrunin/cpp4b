#pragma once
#include "Chooser.hpp"


/**
 * ConstantChooser is a chooser that always chooses the same string. 
 */
class ConstantChooser: public bullpgia::Chooser {
		std::string myConstantString;
	public:
		ConstantChooser(const std::string& constantString) { myConstantString = constantString; }
		std::string choose(unsigned int length) override {
			return myConstantString;
		}
};

/**
 * RandomChooser is a chooser that chooses a random string.
 */
class RandomChooser: public bullpgia::Chooser {
		std::string choose(unsigned int length) override;
};


