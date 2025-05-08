#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    private:
        static const size_t ideasSize = 100;
        std::string ideas[ideasSize];
    public:
        Brain(void);
        Brain(const Brain& brain);
        ~Brain(void);
        Brain& operator=(const Brain& brain);
        void setRandomIdea(void);
        std::string getIdea(size_t index) const;
};

#endif
