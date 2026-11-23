#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &name, const std::string &target) const;

private:
    static AForm *createShrubbery(const std::string &target);
    static AForm *createRobotomy(const std::string &target);
    static AForm *createPardon(const std::string &target);

};

struct Entry
{
    const char *name;
    AForm *(*create)(const std::string &);
};

#endif