#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(void);
        Zombie(const std::string& name);
        ~Zombie(void);
        void announce(void) const;
};

#endif
