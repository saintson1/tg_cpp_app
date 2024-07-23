#include "json.hpp"

#include <iostream>

#include <nlohmann/json.hpp>

#include "../file.hpp"

namespace tg_cpp_app
{
  json::json( const nlohmann::json & new_content ) : content_(new_content) {  };

  json::json( nlohmann::json && new_content ) : content_(std::move(new_content)) {  };

  json::json( const file & new_file )
  {
    const auto & subfiles = new_file.get_subfiles();

    if (new_file.get_content() != "")
      content_ = nlohmann::json::parse(new_file.get_content());
    else if(subfiles.size())
      for (auto subfile : subfiles)
        for (auto content : subfile->get_string_content())
          if (content == "")
            content_[subfile->get_name()] = nullptr;
          else
            content_[subfile->get_name()] = nlohmann::json::parse(content);
    else
      content_[new_file.get_filename()] = nullptr;
  };

  // json::json( const std::string & new_str_json ) : content_(nlohmann::json::parse(new_str_json)) {  };

  json::json( const json & new_json ) : content_(new_json.content_) {  };

  json::json( json && new_json ) : content_(std::move(new_json.content_)) {  };

  json & json::operator=( const json & new_json )
  {
    content_ = new_json.content_;
    return *this;
  };

  json & json::operator=( json && new_json )
  {
    content_ = std::move(new_json.content_);
    return *this;
  };

  json & json::operator=( const nlohmann::json & new_content )
  {
    content_ = new_content;
    return *this;
  };


  json::~json() {  };

  nlohmann::json & json::find( const std::string & key )
  {
    return content_[key];
  };

  std::string json::to_string() const
  {
    return content_.dump();
  };

  nlohmann::json & json::operator[]( const std::string & key )
  {
    nlohmann::json & find_res = find(key);
    if(find_res.is_null())
      return content_[key] = nullptr;
    return find_res;
  };

  nlohmann::json::iterator json::begin()
  {
    return content_.begin();
  };

  nlohmann::json::iterator json::end()
  {
    return content_.end();
  };

  bool json::is_empty() { return content_.empty(); };
};

