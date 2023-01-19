// Your First C++ Program

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cargs.h>
#include "coresolve.cpp"

bool debug = false;
bool help = false;
bool version = false;

static struct cag_option options[] = {
  {.identifier = 'd',
   .access_letters = "d",
   .access_name = "debug",
   .value_name = NULL,
   .description = "Run in debug mode with many logs for co-resolution and TLS session"},

  {.identifier = 'v',
   .access_letters = "v",
   .access_name = "version",
   .value_name = NULL,
   .description = "Simple flag"},

  {.identifier = 't',
    .access_letters = "t",
    .access_name = "type",
    .value_name = "TYPE",
    .description = "Type of record A / AAAA / TXT / CERT / CNAME"},

  {.identifier = 'h',
    .access_letters = "h",
    .access_name = "help",
    .description = "Shows the command help"}};

struct demo_configuration
{
  bool simple_flag;
  bool multiple_flag;
  bool long_flag;
  const char *key;
};

int main(int argc, char** argv) {
  char identifier;
  const char *value;
  cag_option_context context;
  struct demo_configuration config = {false, false, false, NULL};
  int param_index;

  /**
   * Now we just prepare the context and iterate over all options. Simple!
   */
  cag_option_prepare(&context, options, CAG_ARRAY_SIZE(options), argc, argv);
  while (cag_option_fetch(&context)) {
    identifier = cag_option_get(&context);
    switch (identifier) {
    case 'd':
      debug = true;
      config.simple_flag = true;
      break;
    case 'v':
      version = true;
      config.simple_flag = true;
      break;
    case 'm':
      config.multiple_flag = true;
      break;
    case 'l':
      config.long_flag = true;
      break;
    case 't':
      std::cout << "yes TYPE";
      value = cag_option_get_value(&context);
      config.key = value;
      break;
    case 'h':
      printf("Usage: cargsdemo [OPTION]...\n");
      printf("Demonstrates the cargs library.\n\n");
      cag_option_print(options, CAG_ARRAY_SIZE(options), stdout);
      printf("\nNote that all formatting is done by cargs.\n");
      return EXIT_SUCCESS;
    }
  }

  printf("simple_flag: %i, multiple_flag: %i, long_flag: %i, key: %s\n",
    config.simple_flag, config.multiple_flag, config.long_flag,
    config.key ? config.key : "-");

  for (param_index = context.index; param_index < argc; ++param_index) {
    printf("additional parameter: %s\n", argv[param_index]);
  }

  if (version) {
    std::cout << "version" << std::endl;
    return 0;
  }

  std::string record_type = "A";
  if (config.key) {
    if (
      config.key == std::string("A") ||
      config.key == std::string("AAAA") ||
      config.key == std::string("TXT") ||
      config.key == std::string("CERT") ||
      config.key == std::string("CNAME")
    ) {
      record_type = config.key;
    } else {
      std::cout << std::string("unrecognized --type parameter") << std::endl;
      return 1;
    }
  }

  return coresolve(debug, record_type);
}
