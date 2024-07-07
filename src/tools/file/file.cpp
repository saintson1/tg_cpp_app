#include "file.hpp"

namespace tg_cpp_app
{
  file::content_node::content_node( std::string new_name_, const content_node_variant_type & new_content)
          : name_(std::move(new_name_))
  {
    contents_.push_back(new_content);
  };

  file::content_node::content_node( std::string new_name_, const std::vector<content_node *> & new_contents )
          : name_(std::move(new_name_))
  {
    for (const auto & content : new_contents)
      contents_.emplace_back(content);
  };

  file::content_node::content_node( const content_node & new_node ) : name_(new_node.name_)
  {
    for (auto & content : new_node.contents_)
      if (std::get_if<content_node *>(&content))
        contents_.emplace_back(new content_node(*std::get<content_node *>(content)));
      else
        contents_.emplace_back(std::get<std::string>(content));
  };

  file::content_node::content_node( content_node && new_node ) : name_(std::move(new_node.name_))
  {
    for (auto & content : new_node.contents_)
      if (std::get_if<content_node *>(&content))
      {
        contents_.emplace_back(std::get<content_node *>(content));
      }
      else
        contents_.emplace_back(std::move(std::get<std::string>(content)));

        new_node.contents_ = std::vector{content_node_variant_type("")};
  };

  file::content_node::~content_node()
  {
    for (auto content : contents_)
    {
      content_node ** dell_dbl_ptr = std::get_if<content_node *>(&content);
      if (dell_dbl_ptr)
        delete *dell_dbl_ptr;
    }
  };

  file::content_node * file::content_node::find( const std::string & find_name )
  {
    if (name_ == find_name)
      return this;

    for (auto & node : contents_)
      if (std::get_if<content_node *>(&node))
      {
        content_node *ans = std::get<content_node *>(node)->find(find_name);
        if (ans)
          return ans;
      }

    return nullptr;
  };

  const std::vector<file::content_node::content_node_variant_type> & file::content_node::get_content() { return contents_; };
  
  std::vector<std::string> file::content_node::get_string_content()
  {
    std::vector<std::string> string_content;

    for (auto & node : contents_)
      if (std::get_if<std::string>(&node))
        string_content.push_back(std::get<std::string>(node));
    return string_content;
  };

  const std::vector<file::content_node::content_node_variant_type> file::content_node::operator[]( const std::string & key )
  {
    content_node *node = find(key);
    if (node)
      return node->contents_;

    return std::vector<content_node_variant_type>();
  };

  file::content_node::content_node_variant_type file::content_node::operator[]( int key )
  {
    if (contents_.size() > key)
      return contents_[key];
    return nullptr;
  };

  const std::vector<std::string> file::content_node::find_content( const std::string & find_name )
  {
    std::vector<std::string> ans;

    content_node *node = find(find_name);
    if (node)
      for (auto & content : node->contents_)
        if (std::get_if<std::string>(&content))
          ans.push_back(std::get<std::string>(content));
    return ans;
  };

  const std::string & file::content_node::get_name() { return name_; };

  file::content_node * file::req_search (const boost::filesystem::path &entity)
  {
    try
    {
      if (boost::filesystem::exists(entity))
      {
        if (boost::filesystem::is_regular_file(entity))
        {
          std::ifstream fs(entity.generic_string());
          std::string content;
          if (!fs.is_open())
            throw std::runtime_error("file not open");

          std::string buf_line;
          while (std::getline(fs, buf_line))
            content += buf_line;
          return new content_node(entity.filename().generic_string(), content);
        }
        else if (boost::filesystem::is_directory(entity))
        {
          std::vector<content_node *> buf_vector;
          for (auto &unit : boost::filesystem::directory_iterator(entity))
          {
            buf_vector.push_back(req_search(unit.path()));
          }
          return new content_node(entity.filename().generic_string(), buf_vector);
        }
        else
          return nullptr;
      }
      else
        throw std::runtime_error("entity not found");
    }
    catch (const boost::filesystem::filesystem_error &ex)
    {
      throw std::runtime_error(ex.what());
    }
    catch (const std::runtime_error &err_ex)
    {
      throw err_ex;
    }
  };

  file::file() : content_(nullptr) {  };

  file::file(const std::string & path_name) : path_(boost::filesystem::path(path_name)), content_(req_search(path_)) {  };

  file::file(const file & new_file) : path_(new_file.path_), content_(new content_node(*new_file.content_)) {  };

  file & file::operator=(const file & new_file)
  {
    path_ = new_file.path_;
    content_ = new content_node(*new_file.content_);
    return *this;
  };

  file::file(file && new_file) : path_(std::move(new_file.path_)), content_(new content_node(std::move(*new_file.content_))) { new_file.content_ = nullptr; };

  file & file::operator=(file && new_file)
  {
    path_ = std::move(new_file.path_);
    content_ = new content_node(std::move(*new_file.content_));
    new_file.content_ = nullptr;
    return *this;
  };

  file::~file()
  {
    delete content_;
  };

  std::string file::get_content() const
  {
    for (auto & content : content_->get_string_content())
      return content;
    return "";
  };

  std::vector<file::content_node *> file::get_subfiles() const
  {
    std::vector<content_node *> subfiles;

    for (auto & content : content_->get_content())
      if (std::get_if<content_node *>(&content))
        subfiles.emplace_back(std::get<content_node *>(content));
    return subfiles;
  };

  std::string file::get_filename() const
  {
    return path_.filename().generic_string();
  };
};