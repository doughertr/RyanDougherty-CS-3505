#include "food.h"
#include <queue>
#include <tuple>
#include <string>

using namespace std;

CS3505::food::food(const string & id, const int & shelfLife) :
	underlyingVec(100),
	inventory(underlyingVec)
{
	UPC_num = id;
	shelf_life = shelfLife;

}
