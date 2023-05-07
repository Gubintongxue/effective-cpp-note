#pragma once

#include <string>
#include <stdexcept>

void encrypt(std::string& s)
{
	s = "pa$$w0rd";
}

std::string encryptPassword(const std::string& password)
{
	if (password.length() < 8)
	{
		throw std::logic_error("Password too short");
	}

	std::string encrypted(password);
	encrypt(encrypted);

	return encrypted;
}

int main()
{
	std::string encrypt = encryptPassword("password");
	return 0;
}