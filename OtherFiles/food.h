#ifndef FOOD_H
#define FOOD_H
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include "boost/date_time/gregorian/gregorian_types.hpp"

namespace CS3505
{
	class food
	{
		public:
			food(const std::string & id, const int & shelfLife);
			~food();
		 	int get_shelf_life() const;	
			std::string get_UPCNum() const;

		private:
			std::string UPC_num;
			int shelf_life;

			typedef std::tuple<int, boost::gregorian::date> foodItem;

			std::vector<foodItem> underlyingVec;
			std::queue<foodItem, std::vector<foodItem>> inventory;


	};
}
#endif
