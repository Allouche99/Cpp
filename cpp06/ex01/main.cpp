#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data		data;
	data.id = 42;
	data.name = "yssr";
	data.value = 4.2;

	uintptr_t	raw = Serializer::serialize(&data);
	Data		*back = Serializer::deserialize(raw);

	std::cout << "Adresse datae : " << &data << std::endl;
	std::cout << "Valeur serialisee : " << raw << std::endl;
	std::cout << "Adresse retrouvee : " << back << std::endl;

	if (back == &data)
		std::cout << "OK : both pointers are identique" << std::endl;
	else
		std::cout << "KO : pointers are diferent" << std::endl;

	std::cout << "id=" << back->id << " name=" << back->name
		<< " value=" << back->value << std::endl;
	return 0;
}