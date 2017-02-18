#include "TClass.h"


THaSoPr::~THaSoPr() {}


THaSoPr::THaSoPr() {}


THaSoPr::THaSoPr(const std::string & nName, const std::size_t & nNomber){
	Name = nName;
	Nomber = nNomber;
}


void THaSoPr::Print(){
	std::cout << "Name is " << Name << ", class is " << Nomber << std::endl;
}


bool THaSoPr::Check(const std::size_t & nNomber){
	if (Nomber <= nNomber) return true;
	return false;
}




