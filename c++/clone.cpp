#include <iostream>

class Resume {
private:
    std::string name;
    std::string age;
    std::string education;
public:
    Resume() 
    {
        std::cout << "Construct !" << std::endl;
    };
    Resume(const Resume& resume)
    {
        this->name = resume.name;   
        this->age = resume.age;
        this->education = resume.education;
        std::cout << "Copy Construct !" << std::endl;
    }
    void SetPersonalInfo(const std::string& name, const std::string& age)
    {
        this->name = name;
        this->age = age;
    }
    void SetEducation(const std::string& educatoin)
    {
        this->education = educatoin;
    }
    void PrintResume()
    {
        std::cout << name << ", " << age  << ", " << education << std::endl;
    }
    Resume* Clone()
    {
        return new Resume(*this);
    }
};

int main()
{
    Resume* p1 = new Resume();
    p1->SetPersonalInfo("Tom", "25");
    p1->SetEducation("master");
    p1->PrintResume();

    Resume* p2 = p1->Clone();
    p2->SetPersonalInfo("Jack", "28");
    p2->PrintResume();
}