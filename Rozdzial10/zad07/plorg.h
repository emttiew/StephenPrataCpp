#ifndef PLORG_H_
#define PLORG_H_

class Plorg 
{   
    static const int LIMIT = 19;
    char name[LIMIT];
    int full_factor;
 public:
    Plorg();
    Plorg(const char * str, const int f = 50);    
    void set_factor(const int f);
    void show() const;

};

#endif