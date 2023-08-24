#include "Serializer.hpp"

int	main()
{
	Serializer::initializeData();
	Serializer::deserialize(Serializer::serialize(Serializer::getData()));
	return 1;
}