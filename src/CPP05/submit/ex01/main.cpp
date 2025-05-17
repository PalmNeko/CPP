#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>
#include <iostream>

#define ALIGN_WIDTH 35
#define LEFT_ALIGN std::left << std::setw(ALIGN_WIDTH)

void testForm();
void testFormTemplate(const std::string name,
                      int requireGradeToSign,
                      int requireGradeToExecute,
                      const Bureaucrat &bureaucrat,
                      const std::string label);
void printHeader(const std::string name,
                 int requireGradeToSign,
                 int requireGradeToExecute,
                 const Bureaucrat &bureaucrat,
                 const std::string label);
void testFormAbstract();
void testFormDetail();

int main(void)
{
    std::cout << std::endl;
    testForm();
    std::cout << std::endl;
    return 0;
}

void testForm()
{
    testFormAbstract();
    std::cout << std::endl;
    testFormDetail();
}

void testFormAbstract()
{
    // 各メソッドが実装されていますよ―なテスト
    std::cout << " === Abstract test === " << std::endl;
    Form form("abstract", 15, 30);
    std::cout << "Form: " << form << std::endl;
    std::cout << " - Name: " << form.getName() << std::endl;
    std::cout << " - Is Signed: " << form.getIsSigned() << std::endl;
    std::cout << " - Required Grade For Sign: " << form.getRequireGradeToSign() << std::endl;
    std::cout << " - Required Grade For Execute: " << form.getRequireGradeToExecute()
              << std::endl;
    Bureaucrat bob("bob", 13);
    bob.signForm(form);

    // コピーコンストラクタが動きますよ―なテスト
    Form copied = Form(form);
    std::cout << "Copied Form: " << copied << std::endl;
}

void testFormDetail()
{
    // 範囲外でエラー出力しますよ―なテスト
    std::cout << " === Detail test === " << std::endl;
    Bureaucrat higher("higher", 1);
    Bureaucrat lower("lower", 150);

    testFormTemplate("Form 1", 0, 1, higher,
                     " * Fail Constructor : grade for sign is too high");

    testFormTemplate("Form 2", 151, 150, higher,
                     " * Fail Constructor : grade for sign is too low");

    testFormTemplate("Form 3", 1, 0, higher,
                     " * Fail Constructor : grade for execute is too high");

    testFormTemplate("Form 4", 150, 151, higher,
                     " * Fail Constructor : grade for execute is too low");

    // Form が範囲内で サインできる人が違いますよーなテスト
    testFormTemplate("Form 5", 30, 30, lower, " * Fail Sign : grade for sign is not enough");
    testFormTemplate("Form 6", 30, 30, higher, " * Success Sign: grade for sign is enough");
}

void testFormTemplate(const std::string name,
                      int requireGradeToSign,
                      int requireGradeToExecute,
                      const Bureaucrat &bureaucrat,
                      const std::string label)
{
    printHeader(name, requireGradeToSign, requireGradeToExecute, bureaucrat, label);
    try
    {
        Form form(name, requireGradeToSign, requireGradeToExecute);

        bureaucrat.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[31mError:\033[m " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

// もしもGradeが範囲外なら赤で表示
void printHeader(const std::string name,
                 int requireGradeToSign,
                 int requireGradeToExecute,
                 const Bureaucrat &bureaucrat,
                 const std::string label)
{
    std::cout << label << std::endl;
    std::cout << "ARGS: name: " << name;
    std::cout << " requireGradeToSign: ";
    if (1 <= requireGradeToSign && requireGradeToSign <= 150)
        std::cout << requireGradeToSign;
    else
        std::cout << "\e[31m" << requireGradeToSign << "\e[m";
    std::cout << " requireGradeToExecute: ";
    if (1 <= requireGradeToExecute && requireGradeToExecute <= 150)
        std::cout << requireGradeToExecute;
    else
        std::cout << "\e[31m" << requireGradeToExecute << "\e[m";
    std::cout << " bureaucrat: " << bureaucrat << std::endl;
}
