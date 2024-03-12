#include <iostream>
#include "Test.h"
#include "IQuestion.h"
#include "MonoCloseQuestion.h"
#include "MultiCloseQuestion.h"
#include "Admin.h"
#include "TestRepository.h"

TestRepository* TestRepository::testRep = NULL;

int main()
{
    /*IQuestion* question = new MonoCloseQuestion();
    std::cout << question->check(3) << '\n';

    IQuestion* question2 = new MultiCloseQuestion();
    std::vector<int> v{ 1, 6, 3 };
    std::cout << question2->check(v);*/
    //TestRepository* TestRepository::testRep = NULL

    Admin* admin = new Admin();
    admin->testing();
    //admin->addQuestion("id123451", "what1?", 100, QuestionType::Open, "bebra1");
    //admin->addQuestion("id12345", "what?", 100, QuestionType::Open, "bebra");
    //admin->removeQuestion("qwerty", 0);
    
    //std::cout << static_cast<MonoCloseQuestion*>(question)->check(3);
}