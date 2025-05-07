#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    private:
        std::string ideas[100];
        static const size_t ideasSize;
    public:
        Brain(void);
        Brain(const Brain& brain);
        ~Brain(void);
        Brain& operator=(const Brain& brain);
        void setIdea(size_t index, const std::string& idea);
        std::string getIdea(size_t index) const;
};

#endif
