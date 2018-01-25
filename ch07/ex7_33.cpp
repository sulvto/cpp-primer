#include <iostream>
#include <vector>

using std::cout;
using std::cin;

class Window_mgr;

class Screen {
	friend class Window_mgr;
	public:
		typedef std::string::size_type pos;
		Screen() = default;
		Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {}
		Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

		Screen set(char c);
		Screen set(pos r, pos c, char s);
		char get() const { return contents[cursor]; }
		inline char get(pos r, pos c) const;
		Screen move(pos r, pos c);
		Screen display(std::ostream &os) { do_display(os); return *this; }
		const Screen &display(std::ostream &os) const{ do_display(os); return *this; }
		pos size() const;
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;	
		void do_display(std::ostream &os) const { os << contents; }
};

Screen::pos Screen::size() const {
	return height * width;
}

inline Screen Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen Screen::set(pos r, pos c, char s) {
	pos row = r * width;
	contents[row + c] = s;
	return *this;
}

char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}

Screen Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

class Window_mgr {
	public:
		using ScreenIndex = std::vector<Screen>::size_type;
		void clear(ScreenIndex);
	private:
		std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}


int main() {
}
