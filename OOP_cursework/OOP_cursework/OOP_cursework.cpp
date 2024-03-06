#include <iostream>
#include "Test.h"
#include "IQuestion.h"
#include "MonoCloseQuestion.h"

int main()
{
    IQuestion* question = new MonoCloseQuestion();
    std::cout << static_cast<MonoCloseQuestion*>(question)->check(3);
}