
#ifndef SEDBAD_H
# define SEDBAD_H

#include <iostream>
#include <fstream>
#include <string>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define NC "\033[0m"

void		printFile(const char *filename);
std::string	replaceFilename(char *filename);

#endif