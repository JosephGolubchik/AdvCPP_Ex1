#include "Card.h"
#define RANDOM
// #define WINDOWS
#ifdef WINDOWS
#include <windows.h>
#endif
Card generate_card() {
#ifdef RANDOM
	return Card(color(rand() % 4 + 1), sign(rand() % 14 + 1));
#else
	static int counter = 0;
	counter++;
	return Card(color(counter % 2 + 1), sign(counter % 5 + 8));
#endif

}
bool Card::is_leggal(const Card& other, const sign cs) const {
	bool ret = false;
	ret |= (get_color() == other.get_color());
	if (cs != TAKI)
		ret |= (get_sign() == other.get_sign());
	return ret;
}
ostream& operator << (ostream &os, const Card &c) {
#ifdef WINDOWS
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	switch (c.clr) {
	case R:
		SetConsoleTextAttribute(hstdout, 0x7C);
		break;
	case G:
		SetConsoleTextAttribute(hstdout, 0x73);
		break;
	case B:
		SetConsoleTextAttribute(hstdout, 0x79);
		break;
	case Y:
		SetConsoleTextAttribute(hstdout, 0x7E);
		break;
	default:
		os << c.clr << " error";
	}

	switch (c.s) {
	case PLUS:
		os << "+";
		break;
	case STOP:
		os << "STP";
		break;
	case CD:
		os << "-><-";
		break;
	case TAKI:
		os << "TAKI";
		break;
	case PLUSTWO:
		os << "2+";
		break;
	default:
		os << c.s;
	}

	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
#else
	switch (c.clr) {
	case R:
		// os << "R-";
		os << "\033[1;38;2;255;20;0;48;2;70;70;70m";
		break;
	case G:
		os << "\033[1;38;2;24;232;31;48;2;70;70;70m";
		break;
	case B:
		os << "\033[1;38;2;0;175;250;48;2;70;70;70m";
		break;
	case Y:
		os << "\033[1;38;2;255;202;28;48;2;70;70;70m";
		break;
	default:
		os << c.clr << " error";
	}

	switch (c.s) {
	case PLUS:
		os << "+";
		cout << "\033[0m";
		break;
	case STOP:
		os << "STP";
		cout << "\033[0m";
		break;
	case CD:
		os << "-><-";
		cout << "\033[0m";
		break;
	case TAKI:
		os << "TAKI";
		cout << "\033[0m";
		break;
	case PLUSTWO:
		os << "2+";
		cout << "\033[0m";
		break;
	default:
		os << c.s;
		cout << "\033[0m";
	}
#endif
	return os;
}
