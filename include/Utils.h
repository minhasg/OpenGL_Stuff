/****************************************************
 *   This file is meant to hold generally useful    *
 *  utility functions that shouldn't belong to any  *
 *  single class. Things such as text file IO and   *
 *    error logging functions should go in here.    *
 *  This file will be written using C-style code    *
 * structure to ensure that the scope stays global. *
 ****************************************************
 */

#include <iostream>

std::string readTextFromFile(std::string filename);
