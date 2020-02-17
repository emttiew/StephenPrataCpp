# ifndef GOLF_H_
# define GOLF_H_

class Golf {
	static const int Len = 40;
	char fullname[Len];
	int _handicap;	
public:
	Golf(const char * name, int hc);
	Golf();
	void handicap(int hc);
	void showgolf() const;

};
# endif

