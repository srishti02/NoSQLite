#include <iostream>
#include "mongoDB/mongo.h"
#include "redis/redis.h"

#include <chrono>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

int main()
{
  //----------------------------------------------------------------------------
  std::string s1 = "1";
  std::string s2 = "Jimish";
  std::string s3 = "TestDoc";
  NoSQLite::Mongo test;
  test.connect();
  test.insert(0,s1,s2,s3);
  // test.remove(1,s1,s2,s3);
  test.find(2,s1,s2,s3);
  // NoSQLite::Redis test1;
  // test1.insert(0,"abc","foo","bbo");


  /* Mongo Connection Details*/
  /*
     mongocxx::instance inst{};
     mongocxx::client conn{mongocxx::uri{}};
     std::cout<<"Connected"<<std::endl;
     auto db = conn["APIDB"];
     bsoncxx::document::value restaurent_doc = make_document(kvp("Key1","Value1"));
     */

  /* Mongo Insert Code 

     auto res = db["TestDoc"].insert_one(std::move(restaurent_doc));

     std::cout<<"Insrted"<< std::endl;*/
  //  ----------------------------------------------------------------------------

  NoSQLite::Redis test1;
  test1.connect("127.0.0.1",6379);
  std::string key = "Srishti";
  std::string value = "Ambala";
  std::string hash5 = "ADT";
  std::string key5 = "Sid";
  std::string value5 = "Ukr";
  test1.insert(0,key, value);
  test1.insert(3,hash5, key5, value5);
  //std::string key2 = "Jimish";
  // std::string value2 = "Gujarat";
  // test1.insert(0,key2,value2);
  std::string key1 ="unavailable";
  test1.find(1,key);
  test1.find(4,hash5,key5); 
  // test1.remove(5,hash5,key5); 
  //std::cout<<"Worked"<<std::endl;
  //test1.remove(2,key);
}
