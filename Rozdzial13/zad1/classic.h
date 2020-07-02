#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd
{
private:
    char *title;
    int len;
public:
    Classic(char * s0, char * s1, char * s2, int n, double x);
    Classic();
    Classic(const char * s1, const Cd & cd);
    virtual ~Classic();
    Classic(const Classic & c);
    Classic & operator=(const Classic & c);
    virtual void Report() const;
};

#endif