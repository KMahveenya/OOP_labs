#include "Noname.h"
#include "sha256.h"
#include "ConsoleManager.h"

bool Noname::registration(std::string login, std::string password1, std::string password2)
{
	//realisation

	/*if (checkLogin(login) == "")
	{
		ConsoleManager::getInstance()->wrongLogin();
		return false;
	}*/
	if (password1.length() < 6 || password1 != password2)
	{
		ConsoleManager::getInstance()->wrongPassword();
		return false;
	}

	//save sha pass in db

	return true;
}

bool Noname::authentification(std::string login, std::string password)
{
	//realisation

	//std::string hashPassword = checkLogin(login);
	std::string hashPassword = sha256("password1");
	/*if (checkLogin(login) == "")
	{
		ConsoleManager::getInstance()->wrongNoLogin();
		return false;
	}*/
	if (hashPassword != sha256(password))
	{
		ConsoleManager::getInstance()->wrongPassword();
		return false;
	}
	else
	{
		return true;
	}
}