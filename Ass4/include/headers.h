#pragma once
#include <iostream>
#include <string>
#include<memory>
#include <sstream>

#include "calculate.h"
#include "operationFactory.h"
#include "db-lite.h"


class CALCULATOR
{
    private:
        std::string my_result;
        std::string my_query;
        std::unique_ptr<Calculate> my_calc;
        
    private:

        CALCULATOR(const CALCULATOR& ) = delete;

        CALCULATOR()
        {
            DB_LITE::Get().createTable();
        }

    public:

        static CALCULATOR& Get()
		{
			static CALCULATOR instance;
			return instance;
		}

        void calulate(std::string query)
        {
            my_query = query;
            Calculate calc(query);
            my_result = std::to_string(calc.evaluate());
            std::cout<<my_result<<std::endl;
            DB_LITE::Get().insertData(my_query.c_str(), my_result.c_str());
        }

        void showHistory()
        {
            std::cout<<std::endl;
            DB_LITE::Get().showTable();
        }

        void deleteHistory(const char* id)
        {
            std::cout<<std::endl;
            DB_LITE::Get().deleteRow(id);
            DB_LITE::Get().showTable();
        }
};