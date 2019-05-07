/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include <string>
#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"}, c{""}, c11{"11"}, c111{"111"}, c1{"1"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"}, g{""}, g11{"11"}, g12{"12"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1111","1234"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4213","2231"), "1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("3124","1243"), "0,4")
		.CHECK_OUTPUT(calculateBullAndPgia("2314","1234"), "1,3")
		.CHECK_OUTPUT(calculateBullAndPgia("4444","1231"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1212","3434"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4311","2134"), "0,3")
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c11, g11, 2, 100), 1)
		.CHECK_EQUAL(play(c11, g12, 2, 100), 101)
		.CHECK_EQUAL(play(c11, g11, 3, 100), 0)
		.CHECK_EQUAL(play(c111, g11, 3, 100), 101)
		.CHECK_EQUAL(play(c, g, 0, 100), 1)
		.CHECK_EQUAL(play(c, g, 1, 100), 0)
		.CHECK_EQUAL(play(c1, g, 1, 100), 101)

		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (unsigned int i=0; i<100; ++i) {
			
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		for (unsigned int i=0; i<1000; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 40)<=100, true);  // smarty should win within 16 turns
		}
		for (unsigned int i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 5, 50)<=100, true);  // smarty should always win in at most 100 turns!
		}
		for (unsigned int i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 2, 20)<=100, true);  // smarty should always win in at most 100 turns!
		}
		
		for (unsigned int i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 0, 1)<=100, true);  // smarty should always win in at most 100 turns!
		}



    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

