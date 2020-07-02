#ifndef CD_H_
#define CD_H_

class Cd {
private:
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

#endif