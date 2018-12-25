#include <boost/process.hpp>
#include <iostream>
#include <string>
/*!
\file super_agent.cpp
\author Igor Roshchin
start mongo agent and decorate 
*/
using namespace boost::process;
int main() {
	return system("./start");
}
