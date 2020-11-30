#ifndef JOJ
#include "assignment.h"
#endif

#include <iostream>
#include <sstream>
#include <string>

static const char GRADES[] = "FFFFFFDCBAA";

class Grade {
    private:
        char ltr;
        int prct;

    public:
        inline Grade(int prct) : ltr(GRADES[prct / 10]), prct(prct) {}
        inline Grade(char ltr) : ltr(ltr), prct(100 - (ltr - 'A') * 10 - 5) {}

        template<class CharT, class Traits, class Allocator>
        operator std::basic_string<CharT, Traits, Allocator>() const {
            std::basic_ostringstream<CharT, Traits, Allocator> oss;
            oss << "Grade: " << prct << " -> " << ltr;
            return oss.str();
        }
};

template<class CharT, class Traits>
inline std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits> &os, const Grade &value) {
    return os << std::basic_string<CharT, Traits>(value) << std::endl;
}

void ex5() {
    using namespace std;

    int prct;
    char ltr;
    
    cout << "Input two space seprated grades (1st in %%, 2nd in letter): ";
    cin >> prct >> ltr;
    cout << Grade(prct) << Grade(ltr);
}

#ifndef CTEMPLATE_ASSIGNMENT_H

int main() {
    ex5();
    return 0;
}

#endif //CTEMPLATE_ASSIGNMENT_H
