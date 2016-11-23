#include <tacopie/tacopie>

#include <iostream>

class my_logger : public tacopie::logger_iface {
public:
  //! ctor & dtor
  my_logger(void)  = default;
  ~my_logger(void) = default;

  //! copy ctor & assignment operator
  my_logger(const my_logger&) = default;
  my_logger& operator=(const my_logger&) = default;

public:
  void
  debug(const std::string& msg, const std::string& file, std::size_t line) {
    std::cout << "debug: " << msg << " @ " << file << ":" << line << std::endl;
  }

  void
  info(const std::string& msg, const std::string& file, std::size_t line) {
    std::cout << "info: " << msg << " @ " << file << ":" << line << std::endl;
  }

  void
  warn(const std::string& msg, const std::string& file, std::size_t line) {
    std::cout << "warn: " << msg << " @ " << file << ":" << line << std::endl;
  }

  void
  error(const std::string& msg, const std::string& file, std::size_t line) {
    std::cerr << "error: " << msg << " @ " << file << ":" << line << std::endl;
  }
};


int
main(void) {
  //! By default, no logging
  //! Force logger call, just for the example (you will never have to do that by yourself)
  std::cout << "By default: no logging" << std::endl;
  __TACOPIE_LOG(debug, "This is a debug message");
  __TACOPIE_LOG(info, "This is an info message");
  __TACOPIE_LOG(warn, "This is a warn message");
  __TACOPIE_LOG(error, "This is an error message");
  std::cout << std::endl;

  //! Use the default logger, provided with the library
  tacopie::active_logger = std::unique_ptr<tacopie::logger>(new tacopie::logger(tacopie::logger::log_level::debug));
  //! Force logger call, just for the example (you will never have to do that by yourself)
  std::cout << "With the library provided logger" << std::endl;
  __TACOPIE_LOG(debug, "This is a debug message");
  __TACOPIE_LOG(info, "This is an info message");
  __TACOPIE_LOG(warn, "This is a warn message");
  __TACOPIE_LOG(error, "This is an error message");
  std::cout << std::endl;

  //! Use your custom logger
  tacopie::active_logger = std::unique_ptr<my_logger>(new my_logger);
  //! Force logger call, just for the example (you will never have to do that by yourself)
  std::cout << "With an example of custom logger" << std::endl;
  __TACOPIE_LOG(debug, "This is a debug message");
  __TACOPIE_LOG(info, "This is an info message");
  __TACOPIE_LOG(warn, "This is a warn message");
  __TACOPIE_LOG(error, "This is an error message");
  std::cout << std::endl;

  return 0;
}
