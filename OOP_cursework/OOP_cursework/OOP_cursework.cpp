#include <iostream>
#include "Test.h"
#include "IQuestion.h"
#include "MonoCloseQuestion.h"
#include "MultiCloseQuestion.h"

int main()
{
    IQuestion* question = new MonoCloseQuestion();
    std::cout << question->check(3) << '\n';

    IQuestion* question2 = new MultiCloseQuestion();
    std::vector<int> v{ 1, 6, 3 };
    std::cout << question2->check(v);
    //std::cout << static_cast<MonoCloseQuestion*>(question)->check(3);
}